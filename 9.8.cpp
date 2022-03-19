//程序清单9.8：
#include<iostream>
using std::cout; using std::endl;

extern int tom;            //使用文件1中定义的常规外部变量---全局变量，多个文件可访问
static int dick = 10;          //静态外部变量---全局变量，当前文件可访问，并且会覆盖 = 30
int harry = 200;               //常规外部变量---全局变量，多个文件可访问

void remote_access(){
    
    cout << "remote_access: tom = " << tom << "; &tom = " << &tom << endl;//
    cout << "remote_access: dick = " << dick << "; &dick = " << &dick << endl;
    cout << "remote_access: harry = " << harry << "; &harry = " << &harry << endl;
}


