#include<iostream>
#include<cstring>
#include "golf.h"

using std::cout; using std::endl;

void setgolf(golf& g, const char* name, int hc){
    strcpy(g.fullname,name);
    g.handicap = hc;
}
int setgolf(golf& g){

    if(strcmp(g.fullname,"") == false)//name是空串，就返回0
        return 0;
    else 
        return 1;

    // if(!strcmp(g.fullname,""))//name是空串，就返回1
    //     return 0;
    // else 
    //     return 1;

    // if(strcmp(g.fullname,""))//name是空串，就返回1
    //     return 1;
    // else 
    //     return 0;
}
void handicap(golf& g, int hc){
    g.handicap = hc;
}
void showgolf(const golf& g){
    cout << "姓名：" << g.fullname << "; 等级：" << g.handicap << endl;
}
