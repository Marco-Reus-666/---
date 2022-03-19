#include<iostream>
#include<string>
using std::cin; using std::cout; using std::endl; using std::string;

void strCount(const string& str);

int main(){
    string str;
    cout << "请输入一个字符串（以空串作为结束输入的标志）：";
    getline(cin,str);
    while(str != ""){//如果arr是空串，会返回0，这样的话就退出循环        
        strCount(str);
        cout << "请输入一个字符串（以空串作为结束输入的标志）：";
        getline(cin,str);
    }
    cout << "bye" << endl;
    return 0;
}

void strCount(const string& str){
    int count = 0;          //局部变量
    static int total = 0;   //静态局部变量
    
    count = str.length();
    total += count;
    cout << "字符串 " << str << " 包含 " << count << " 个字符； 目前一共累计输入了 " << total << " 个字符。" << endl;
}