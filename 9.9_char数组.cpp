#include<iostream>
#include<cstring>
using std::cin; using std::cout; using std::endl;

const int SIZE = 10;
void strCount(const char* arr);

int main(){
    char arr[SIZE];
    cout << "请输入一个字符串（长度<=10，以空串作为结束输入的标志）：";
    cin.getline(arr,SIZE);
    while(strcmp(arr,"")){//如果arr是空串，会返回0，这样的话就退出循环        
        strCount(arr);
        cout << "请输入一个字符串（长度<=10，以空串作为结束输入的标志）：";
        cin.getline(arr,SIZE);
    }
    cout << "bye" << endl;
    return 0;
}

void strCount(const char* arr){
    int count = 0;          //局部变量
    static int total = 0;   //静态局部变量
    int i = 0;
    while(arr[i++]){
        count++;//每次都从0开始加
        total++;//每次在上次的基础上累加
    }
    cout << "字符串 " << arr << " 包含 " << count << " 个字符； 目前一共累计输入了 " << total << " 个字符。" << endl;
}