//程序清单9.7：
#include<iostream>

using std::cout; using std::endl;

int tom = 3;            //常规外部变量---全局变量，多个文件可访问
int dick = 30;          //常规外部变量---全局变量，多个文件可访问
static int harry = 300; //静态外部变量---全局变量，当前文件可访问 = 300

void remote_access();

int main(){

    cout << "main: tom = " << tom << "; &tom = " << &tom << endl;
    cout << "main: dick = " << dick << "; &dick = " << &dick << endl;
    cout << "main: harry = " << harry << "; &harry = " << &harry << endl;
    remote_access();

    return 0;
}