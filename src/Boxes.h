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

    std::string build() override {
        std::string str;
        Utils::write32(str, 0x00002000);
        str += "isomiso2avc1mp41";
        addContent(str);
        return Box::build();
    }
};

#endif //FLV2MP4_BOXES_H
