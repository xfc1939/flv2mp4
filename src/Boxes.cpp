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
    , rate_(1)
    

std::string MvhdBox::build() {
    return std::string();
}

void MvhdBox::setTimeScale(uint32_t scale) {
    timeScale_ = scale;
}