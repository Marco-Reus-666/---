#include<iostream>
#include<new>
using std::cout; using std::cin; using std::endl;

char buffer[512];//用一个静态char数组为定位new运算符提供内存空间，这块内存空间在全局区
const int N = 5;
int main(){

    double* p1;
    double* p2;
    p1 = new double[N];
    p2 = new(buffer) double[N];

    cout << "堆区的地址：" << p1 << "；  全局区的地址：" << (void *)buffer << endl;//这里要写 (void *)，否则输出的是字符串的内容
    for(int i = 0; i < N; i++){
        p1[i] = i + 10.1;
        p2[i] = i + 20.2;
    }
    for(int i = 0; i < N; i++){
        cout << "p1[i] = " << p1[i] << "; &p1[i] = " << &p1[i] << "  ---  "; 
        cout << "p2[i] = " << p2[i] << "; &p2[i] = " << &p2[i] << endl; 
    }

    delete[] p1;
    cout << "delete[] p1;" << endl;
    // p1 = new double[N];
    // p2 = new(buffer + N * sizeof(double)) double[N];
    // for(int i = 0; i < N; i++){
    //     p1[i] = i + 11.1;
    //     p2[i] = i + 22.2;
    // }
    // for(int i = 0; i < N; i++){
    //     cout << "p1[i] = " << p1[i] << "; &p1[i] = " << &p1[i] << "  ---  "; 
    //     cout << "p2[i] = " << p2[i] << "; &p2[i] = " << &p2[i] << endl; 
    // }
    // delete[] p1;
    // cout << "delete[] p1;" << endl;

    int* p3;
    int* p4;
    p3 = new int[N];
    p4 = new(buffer + sizeof(int)) int[N];
    cout << "堆区的地址：" << p3 << "；  全局区的地址：" << (void *)buffer << endl;//这里要写 (void *)，否则输出的是字符串的内容
    for(int i = 0; i < N; i++){
        p3[i] = i + 10;
        p4[i] = i + 20;
    }
    for(int i = 0; i < N; i++){
        cout << "p3[i] = " << p3[i] << "; &p3[i] = " << &p3[i] << "  ---  "; 
        cout << "p4[i] = " << p4[i] << "; &p4[i] = " << &p4[i] << endl; 
    }
    delete[] p3;
    cout << "delete[] p3;" << endl;



    return 0;
}