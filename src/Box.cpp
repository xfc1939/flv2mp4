//
// Created by xfc on 2019/5/8.
//

#include "Box.h"
#include "Utils.h"
#include <string>
#include <cstdint>

const uint32_t MinSize = 0;

Box::Box(const std::string &type)
    : type_(type)
    , size_(MinSize)
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
        Utils::writeU32(str, 1);
    } else {
        Utils::writeU32(str, size_);
    }
    str += type_;
    if (size_ > UINT32_MAX){
        size_ += 8;
        Utils::writeU64(str, size_);
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
    size_ += content.size();
}

std::string Box::type() const {
    return type_;
}

// FullBox

FullBox::FullBox(const std::string & type, uint8_t ver, uint32_t flags)
    : Box(type)
    , ver_(ver)
{}

std::string FullBox::build()
{
    std::string str;
    uint32_t ver_flags = ver_;
    ver_flags = (ver_flags << 24) | flags_;
    Utils::write32(str, ver_flags);
    content_ = str + content_;
    return Box::build();
}