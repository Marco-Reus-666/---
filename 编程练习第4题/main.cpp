#include<iostream>
#include "namesp.h"

using std::cout; using std::endl;

int main(){

    using namespace SALES;
    Sales s1;
    double arr[3] = {11.1, 22.2, 33.3};
    setSales(s1,arr,3);
    showSales(s1);

    Sales s2;
    setSales(s2);
    showSales(s2);

    return 0;
}