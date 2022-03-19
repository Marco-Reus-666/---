#include<iostream>

using std::cout; using std::cin; using std::endl;

void func1();//返回函数被调用的次数

int main(){
    
    func1();
    func1();
    func1();
    func1();
    func1();
    
    return 0;
}

void func1(){
    static int count = 0;//静态局部变量
    int num = 0;//局部变量
    num += 2;
    cout << "num = " << num << "; ";
    count++;
    cout << "函数被调用第 count = " << count << "次。" << endl;
}