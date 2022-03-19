#include<iostream>
#include<new>
#include<cstring>
using std::cout; using std::endl;

char buffer[256];
struct Students
{
    char name[20];
    int age;
};

int main(){

    char* buffer1 = new char[256];
    //Students* p = new(buffer) Students[2];
    Students* p = new(buffer1) Students[2];
    strcpy(p[0].name,"marco reus");
    p[0].age = 26;
    strcpy(p[1].name,"thiago silva");
    p[1].age = 29;
    for(int i = 0; i < 2; i++){
        cout << "姓名：" << p[i].name << "；年龄：" << p[i].age << endl;
    }


    //cout << "buffer的地址：" << (void *)buffer << endl;
    cout << "buffer1的地址：" << (void *)buffer1 << endl;
    cout << "p = " << p << endl;
    cout << "&p[0] = " << &p[0] << endl;
    cout << "&p[1] = " << &p[1] << endl;

    delete[] buffer1;
    cout << "delete[] buffer1" << endl;
    return 0;
}