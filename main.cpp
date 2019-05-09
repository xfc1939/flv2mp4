//
// Created by xfc on 2019/5/8.
//

#include <iostream>
#include <strstream>

int main(int argc, char* argv[]) {

    std::cout << "hello" << std::endl;
    std::string str;
    str.push_back(1);
    str.push_back(0);
    str.push_back(1);
    str.push_back('1');
    std::cout << str << std::endl;
    printf("%x", str[3]);
    printf("%x", str[0]);
    return 0;
}
