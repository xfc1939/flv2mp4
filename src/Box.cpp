//
// Created by xfc on 2019/5/8.
//

#include "Box.h"
#include "Utils.h"
#include <string>
#include <cstdint>

Box::Box(const std::string &type)
    : type_(type)
{

}
void Box::addChildBox(Box *box) {
    if (box) {
        boxLists_.push_back(box);
        size_ += box->size();
    }
}

std::string Box::build() {
    std::string str;
    if (size_ > UINT32_MAX) {
        Utils::write32(str, 1);
    } else {
        Utils::write32(str, size_);
    }
    str += type_;
    if (size_ > UINT32_MAX){
        Utils::write64(str, size_);
    }
    str += content_;
    for(auto box : boxLists_) {
        str += box->build();
    }
    return str;
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