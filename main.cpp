#include <iostream>
#include <vector>
#include "Source/StrCutMgr.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    char t[] = "当我们在里输入一个中字时其实它在里对应的两个字符值为和那么里其实记录的就是这个编码值。当我们电脑控制面板里设置的为中文的时候在里就是呈现出中字；但是如果设置为韩文时在里就是呈现出的就是它所表示的韩文字。即同一个编码值对于不同的值不同的字符集显示出来的字符是不一样的";
//    std::cout << t << std::endl;
//    for (char *p = t; *p; ++p)printf("%i\n", *p);//std::cout << p << std::endl;
//
//    std::vector<char> vec[100];
//
//    vec[0].push_back(t[0]);
//
//    std::cout << vec[0][0] << std::endl;

    StrCutMgr _Scm(t, "中");

    for (_Scm.First(); _Scm.hasNext();) {
        std::cout << _Scm.Next() << std::endl;
    }

    return 0;
}