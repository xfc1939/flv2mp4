//
// Created by xfc on 2019/5/8.
//

#include "Boxes.h"

// Ftyp box
std::string FtypBox::build()
{
    std::string str;
    Utils::writeU32(str, 0x00002000);
    str += "isomiso2avc1mp41";
    addContent(str);
    return Box::build();
}

// Mdat box
std::string MdatBox::build() {
    return std::string();
}

// Mvhd box
MvhdBox::MvhdBox()
    : FullBox("mvhd")
    , timeScale_(1000)
    , rate_(0x00010000)
    , volume_(0x100)
    , duration_(0)
    , modifyTime_(0)
    , createTime_(0)
    , nextTrackId_(3)
    , matrix_({0x00010000,0,0,0,0x00010000,0,0,0,0x40000000})
{

}

    

std::string MvhdBox::build() {

    std::string str;

    if (ver_ == 1) {
        Utils::writeU64(str, createTime_);
        Utils::writeU64(str, modifyTime_);
        Utils::writeU32(str, timeScale_);
        Utils::writeU64(str, duration_);
    } else {
        Utils::writeU32(str, createTime_);
        Utils::writeU32(str, modifyTime_);
        Utils::writeU32(str, timeScale_);
        Utils::writeU32(str, duration_);
    }

    Utils::writeU32(str, rate_);
    Utils::writeU16(str, volume_);
    Utils::writeU16(str, 0x00);
    Utils::writeU64(str, 0x00);

    for(auto value : matrix_) {
        Utils::writeU32(str, value);
    }
    Utils::writeU64(str, 0x00);
    Utils::writeU64(str, 0x00);
    Utils::writeU64(str, 0x00);

    Utils::writeU32(str, nextTrackId_);
    addContent(str);

    return FullBox::build();
}

void MvhdBox::setTimeScale(uint32_t scale) {
    timeScale_ = scale;
}

void MvhdBox::setTime(uint32_t createTime, uint32_t modifyTime) {
    createTime_ = createTime;
    modifyTime_ = modifyTime;
}

void MvhdBox::setRate(uint16_t rateI, uint16_t rateF) {
    rate_ = (rateI << 16) | (rateF);
}

void MvhdBox::setVolume(uint8_t volumeI, uint8_t volumeF) {
    volume_ = (volumeI << 8) | (volumeF);
}

void MvhdBox::setDuration(uint32_t duration) {
    duration_ = duration;
}

void MvhdBox::setNextTrackId_(uint32_t nextTrackId) {
    nextTrackId_ = nextTrackId;
}

void MvhdBox::setMatrix(const std::vector<uint32_t> &matrix) {
    matrix_.clear();
    matrix_.assign(matrix.begin(), matrix.end());
}