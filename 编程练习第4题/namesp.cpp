#include<iostream>
#include "namesp.h"

using std::cout; using std::endl; using std::cin;
namespace SALES{

    void setSales(Sales & s, const double ar[], int n){
        double max,min,ave;
        max =  min = ar[0];
        ave = 0.0;
        if(n > QUARTERS){
            for(int i = 0; i < QUARTERS; i++) s.sales[i] = ar[i];
        }
        else{
            for(int i = 0; i < n; i++) s.sales[i] = ar[i];
            for(int i = n; i < QUARTERS; i++) s.sales[i] = 0;//其余位置补0
        }
        for(int i = 0; i < n; i++){
            ave += s.sales[i];
            if(s.sales[i] > max) max = s.sales[i];
            if(s.sales[i] < min) min = s.sales[i];
        }
        s.max = max;
        s.min = min;
        s.average = ave / QUARTERS;
    }
    void setSales(Sales & s){
        double arr[QUARTERS] = {};
        // double max,min,ave;
        // max =  min = arr[0];
        // ave = 0.0;
        
        for(int i = 0; i < QUARTERS; i++){
            cout << "请输入第 " << i+1 << " 个季度的销售额：";
            cin >> arr[i];
            while(!cin){
                cin.clear();
                while(cin.get() != '\n');
                cout << "输入错误，请重新输入第 " << i+1 << " 个季度的销售额：";
                 cin >> arr[i];
            }
            s.sales[i] = arr[i];
            // ave += s.sales[i];
            // if(s.sales[i] > max) max = s.sales[i];
            // if(s.sales[i] < min) min = s.sales[i];
        }
        // s.max = max;
        // s.min = min;
        // s.average = ave / QUARTERS;
        setSales(s,arr,QUARTERS);//得到arr数组之后，可以直接调用namespace中的重载函数setSales来初始化结构体
    }
    void showSales(const Sales & s){
        cout << "销售额：";
        for(int i = 0; i < QUARTERS; i++){
            cout << s.sales[i] << "; ";
        }
        cout << "最大值：" << s.max << "； 最小值：" << s.min << "；平均值：" << s.average << endl;
    }
}