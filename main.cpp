#include<iostream>
#include "namesp.h"
using std::cout; using std::endl;

void other();
void another();

int main(){

    using debts::Debt;
    using debts::showDebt;
    Debt golf = {"Benny", "Goatsniff", 120.0};
    showDebt(golf);
    other();
    another();
    
    return 0;
}

void other(){
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    for(int i = 0; i < 3; i++){
        getDebt(zippy[i]);
    }
    for(int i = 0; i < 3; i++){
        showDebt(zippy[i]);
    }
    cout << "总债务为：" << sumDebts(zippy,3) << endl;
}
void another(){
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    cout << endl;
}