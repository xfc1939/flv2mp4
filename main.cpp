//
// Created by xfc on 2019/5/8.
//

#include <iostream>
#include <string>
#include "src/Boxes.h"

int main(int argc, char* argv[]) {

    std::cout << "hello" << std::endl;
    Box *box = new FtypBox;
    std::cout << box->build();

    return 0;
}
