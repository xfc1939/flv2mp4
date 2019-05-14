//
// Created by xfc on 2019/5/8.
//

#include <iostream>
#include <string>
#include <fstream>
#include "src/Boxes.h"

int main(int argc, char* argv[]) {

    std::cout << "hello" << std::endl;
    MvhdBox *box = new MvhdBox;
    box->setDuration(30046);

    std::ofstream f("/Users/xfc/1.txt", std::ios::binary);
    std::string str = box->build();
    f.write(str.c_str(), str.size());
    f.close();
    std::cout << str;

    return 0;
}
