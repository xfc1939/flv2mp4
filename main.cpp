//
// Created by xfc on 2019/5/8.
//

#include <iostream>
#include <strstream>

int main(int argc, char* argv[]) {

    std::cout << "hello" << std::endl;
    std::strstream str;
    str << int (1) << int (0) << int (1);
    std::cout << str.str();
    std::string tmpStr = str.str();
    printf("%x", tmpStr[0]);
    return 0;
}