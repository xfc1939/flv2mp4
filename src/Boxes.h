//
// Created by xfc on 2019/5/8.
//

#ifndef FLV2MP4_BOXES_H
#define FLV2MP4_BOXES_H

#include "Utils.h"
#include "Box.h"
#include <strstream>

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
};

// moov container box
class MvhdBox : public Box{

};

// trak container box
class 
#endif //FLV2MP4_BOXES_H
