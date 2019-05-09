//
// Created by xfc on 2019/5/8.
//

#ifndef FLV2MP4_BOXES_H
#define FLV2MP4_BOXES_H

#include "Box.h"
#include <strstream>

class FtypBox : public Box {
public:
    FtypBox() : Box("fype"){}
    ~FtypBox() override = default;

    std::string build() override {
        std::strstream stream;
        stream << 0 << 0 << 2 << 0;
        stream << "isomiso2avc1mp41";
        addContent(stream.str());
        return Box::build();
    }
};

#endif //FLV2MP4_BOXES_H
