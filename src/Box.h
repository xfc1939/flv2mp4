//
// Created by xfc on 2019/5/8.
//

#ifndef FLV2MP4_BOX_H
#define FLV2MP4_BOX_H

#include <string>
#include <cstdint>
#include <vector>

class Box {
public:
    explicit Box(const std::string &type);
    virtual ~Box() = default;

    // 此方法针对容器类box，内部将不会判断是否当前box可否增加子box
    void addChildBox(Box *box);

    // 构建box，得到box中的内容
    virtual std::string build();

    // 得到box的大小
    uint64_t size() const;

    // 向box里面添加内容
    void addContent(const std::string &content);

    // 得到box的类型
    std::string type() const;

protected:
    // 保存box的类型
    std::string type_;

    // 保存box的内容
    std::string content_;

    // 保存box的大小
    uint64_t size_;

    // 保存child box指针
    std::vector<Box*> boxLists_;
};

class FullBox : public Box {
public:
    FullBox(const std::string &type, uint8_t ver = 0, uint32_t flags = 0);
    ~FullBox() = default;

public:
    std::string build() override;

protected:
    // 保存box的版本
    uint8_t ver_;

    // 保存box的flag位
    uint32_t flags_;
};


#endif //FLV2MP4_BOX_H
