//程序清单9.5：
#include<iostream>
//#include "test1.cpp"
using std::cout; using std::endl;

double warming = 0.3;//链接性为外部的静态变量

void update(double dt);
void local();

int main(){
    cout << "main warming = " << warming << endl;//0.3
    update(0.1);
    cout << "main warming = " << warming << endl;//0.4
    local();
    cout << "main warming = " << warming << endl;//0.4

    return 0;
} 


