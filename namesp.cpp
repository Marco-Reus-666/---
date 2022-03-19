#include<iostream>
#include "namesp.h"

using std::cout; using std::cin; using std::endl;
namespace pers{

    void getPerson(Person &rp){
        cout << "请输入姓："; 
        getline(cin,rp.fname);
        cout << "请输入名：";
        getline(cin,rp.lname);
    }
    void showPerson(const Person & rp){
        cout << "姓： " << rp.fname << ";  名： " << rp.lname << "; ";
    }
}

namespace debts{

    void getDebt(Debt & rd){
        getPerson(rd.name);
        cout << "请输入债务数额：";
        cin >> rd.amount;
        cin.get();
    }
    void showDebt(const Debt & rd){
        showPerson(rd.name);
        cout << "债务数额：" << rd.amount << endl;
    }
    double sumDebts(const Debt ar[], int n){
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += ar[i].amount;
        }
        return sum;
    }
    
}