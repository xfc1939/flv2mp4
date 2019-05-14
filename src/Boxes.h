//
// Created by xfc on 2019/5/8.
//

#ifndef FLV2MP4_BOXES_H
#define FLV2MP4_BOXES_H

#include "Utils.h"
#include "Box.h"

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
class MvhdBox : public Box{
public:
    MvhdBox() : Box("mvhd"){}
    ~MvhdBox() override = default;
public:
    std::string build() override;

};

//// trak container box
//class
#endif //FLV2MP4_BOXES_H
