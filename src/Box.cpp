//
// Created by xfc on 2019/5/8.
//

#include "Box.h"
#include <strstream>
#include <cstdint>

Box::Box(const std::string &type)
    : type_(type)
{

}
void Box::addChildeBox(Box *box) {
    if (box) {
        boxLists_.push_back(box);
        size_ += box->size();
    }
}

std::string Box::build() {
    std::strstream strstream;
    if (size_ > UINT32_MAX) {
        strstream << 1;
        //strstream << _
    } else {
        strstream << static_cast<uint32_t>(size_);
    }
    return strstream.str();
}

uint64_t Box::size() const {
    return size_;
}

void Box::addContent(const std::string &content) {
    content_ += content;
}

std::string Box::type() const {
    return type_;
}



