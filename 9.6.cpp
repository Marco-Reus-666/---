//程序清单9.6：
#include<iostream>
using std::cout; using std::endl;
extern double warming;

void update(double dt);
void local();

void update(double dt){
    extern double warming;//这行代码可有可无
    warming += dt;
    cout << "update warming = " << warming << endl;//0.4
}
void local(){
    double warming = 0.8;
    cout << "local warming = " << warming << endl;//0.8   
    cout << "local ::warming = " << ::warming << endl;//0.4
}

// //程序清单9.8：
// #include<iostream>
// using std::cout; using std::endl;

// extern int tom;            //使用文件1中定义的常规外部变量---全局变量，多个文件可访问
// static int dick = 10;          //静态外部变量---全局变量，当前文件可访问，并且会覆盖 = 30
// //int harry = 200;               //常规外部变量---全局变量，多个文件可访问

// void remote_access(){
    
//     cout << "remote_access: tom = " << tom << "; &tom = " << &tom << endl;//
//     cout << "remote_access: dick = " << dick << "; &dick = " << &dick << endl;
//     //cout << "remote_access: harry = " << &harry << "; &harry = " << &harry << endl;
// }


