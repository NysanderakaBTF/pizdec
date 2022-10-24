#include"RBTree.h"
#include<iostream>
#include<vector>

#include "file.h"
using namespace std;
int main()
{
    int ch, y = 0;
    RBtree obj;
    file::textToBin("aaa.txt", "aaa.bin");
    file::printBin("aaa.bin");
    obj.constuct("aaa.bin");
    obj.display(obj.root, 0);
}