//
// Created by xfc on 2019/5/8.
//

#ifndef FLV2MP4_BOXES_H
#define FLV2MP4_BOXES_H

#include "Utils.h"
#include "Box.h"
#include <vector>

class FtypBox : public Box {
public:
    FtypBox() : Box("fype"){}
    ~FtypBox() override = default;
public:
    std::string build() override;
};

// mdat
class MdatBox : public Box {
public:
    MdatBox() : Box("mdat"){}
    ~MdatBox() override = default;
public:
    std::string build() override;
};

// moov container box
class MvhdBox : public FullBox{
public:
    MvhdBox();
    ~MvhdBox() override = default;
public:
    std::string build() override;
    void setTimeScale(uint32_t scale);
    void setTime(uint32_t createTime, uint32_t modifyTime);
    void setRate(uint32_t rate);
    void setVolume(uint32_t volume);
    void setMatrix(const std::vector<uint32_t> &matrix);
    
private:
    uint32_t timeScale_;
    uint32_t rate_;
    uint32_t volume_;

    uint64_t duration_;
    uint64_t createTime;
    uint64_t modifyTime;

    std::vector<uint32_t> matrix_;
};

//// trak container box
//class
#endif //FLV2MP4_BOXES_H
