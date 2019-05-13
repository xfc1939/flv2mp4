//
// Created by xfc on 2019/5/8.
//

#include "Boxes.h"

std::string FtypBox::build()
{
    std::string str;
    Utils::write32(str, 0x00002000);
    str += "isomiso2avc1mp41";
    addContent(str);
    return Box::build();
}