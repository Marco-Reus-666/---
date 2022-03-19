#include<iostream>
#include<cstring>
#include "golf.h"

using std::cin; using std::cout; using std::endl;

int main(){

    golf info[5];
    int count = 0;
    char name[Len];
    int hc;
    for(int i = 0; i < 5;i++){
        cout << "请输入用户名：";
        cin.getline(name,Len);
        cout << "请输入用户等级：";
        cin >> hc;
        cin.get();//清缓存 或者while(cin.get() != '\n');
        setgolf(info[i],name,hc);
        //showgolf(info[i]);
        if(!setgolf(info[i])){
            cout << "您输入的姓名为空，输入结束！";
            break;
        }
        count++;
    }
    if(count == 5)
        cout << "输入结束，";
    cout << "count = " << count << endl;
    
    for(int i = 0; i < count; i++){
        showgolf(info[i]);
    }

    cout << "调用handicap()函数修改handicap值：" << endl;
    handicap(info[0], info[0].handicap + 10);
    showgolf(info[0]);
    handicap(info[count - 1], info[count - 1].handicap + 10);
    showgolf(info[count - 1]);

    // golf g1;
    // setgolf(g1,"abcde",12);
    // showgolf(g1);
    // handicap(g1,26);
    // showgolf(g1);

    // golf g2;
    // setgolf(g2,"",20);
    // cout << setgolf(g2) << endl;
    // showgolf(g2);

    return 0;
}