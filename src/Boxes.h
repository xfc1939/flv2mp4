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

    void setTime(uint64_t createTime, uint64_t modifyTime);

    void setDuration(uint32_t duration);

    // 格式16.16，rate是整数部分，而rateF是小数部分
    void setRate(uint16_t rateI, uint16_t rateF);

    // 格式8.8，volumeI是整数部分，而volumeF是小数部分
    void setVolume(uint8_t volumeI, uint8_t volumeF);


    void setNextTrackId_(uint32_t nextTrackId);

    void setMatrix(const std::vector<uint32_t> &matrix);
    
private:
    uint32_t timeScale_;
    uint32_t rate_;
    uint16_t volume_;
    uint32_t nextTrackId_;

    uint64_t duration_;
    uint64_t createTime_;
    uint64_t modifyTime_;

    std::vector<uint32_t> matrix_;
};

// trak container box

class TkhdBox : public  FullBox {
public:
    TkhdBox(uint8_t ver = 0, uint32_t flags = 0);

    std::string build() override;

    void setTime(uint64_t createTime, uint64_t modifyTime);
    void setDuration(uint64_t duration);
    void setTrackId(uint32_t trackId);
    void setLayer(uint16_t layer);

private:
    uint64_t createTime_;
    uint64_t modifyTime_;
    uint64_t duration_;
    uint32_t trackId_;
    uint16_t layer_;

};
#endif //FLV2MP4_BOXES_H
