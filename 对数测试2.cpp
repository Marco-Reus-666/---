#include<iostream>
#include<cmath>
#include<algorithm>

using std::cout; using std::cin; using std::endl; using std::swap;

int* generateRandomArray(const int& minSize, const int& maxSize, const int& minValue, const int& maxValue);
void copyArray(int arr2[],const int arr1[], int n);
void newMethod(int arr[],int n);//选择排序
//void baoLi(int arr[],int n);//冒泡排序
bool isEqual(const int arr1[],const int arr2[],int n);
void printArr(int arr[],int n);
int biFen(const int arr[],int n,int num);
int baoLi(const int arr[],int n,int num);

int main(){

    int testTime = 100;//测试次数
    int minSize = 5;//数组的最小尺寸
    int maxSize = 30;//数组的最大尺寸 
    int minValue = 10;//元素的最小值
    int maxValue = 30;//元素的最大值
    bool succeed = true;
    srand((unsigned int)time(NULL));//随机数种子放在循环外
    for(int i = 0;i < testTime;i++){
        int randomSize = (rand() % (maxSize - minSize + 1) + minSize);//生成[minSize,maxSize]内的int型随机数；
        int* arr1 = new int[randomSize];
        for(int i = 0;i < randomSize;i++){
            int randomValue = (rand() % (maxValue - minValue + 1) + minValue);//生成[minValue,maxValue]内的int型随机数；
            arr1[i] = randomValue;  
        } 
        //int* arr1 = generateRandomArray(minSize,maxSize,minValue,maxValue);
        //int randomSize = sizeof(arr1) / sizeof(arr1[0]);
        cout << "第" << i+1 << "次测试：数组大小：" << randomSize << endl;
        newMethod(arr1,randomSize);//选择排序
        cout << "原始数组 经排序后的 内容：";
        printArr(arr1,randomSize);
        int k = 26;//要查找的元素
        int arr2[randomSize]; 
        copyArray(arr2,arr1,randomSize);
        //newMethod(arr1,randomSize);//选择排序
        //baoLi(arr2,randomSize);//冒泡排序
        int res1 = biFen(arr1,randomSize,k);
        int res2 = baoLi(arr2,randomSize,k);
        cout << "res1 = " << res1 << "   ;res2 = " << res2 << endl;
        if( res1 != res2){
            succeed = false;
            break;
        }
        // cout << "排序后的数组内容：" << endl;
        // printArr(arr1,randomSize);
        // printArr(arr2,randomSize);
        
        delete[] arr1;
    }
    cout << (succeed ? "测试通过！" : "测试失败！") << endl;
    
    return 0;
}
int* generateRandomArray(const int& minSize, const int& maxSize, const int& minValue, const int& maxValue){
    //int random = (rand() % (100 - 60 + 1) + 60);//生成[60,100]内的int型随机数；
    //srand((unsigned int)time(NULL));
    int randomSize = (rand() % (maxSize - minSize + 1) + minSize);//生成[minSize,maxSize]内的int型随机数；
    int* arr = new int[randomSize];
    for(int i = 0;i < randomSize;i++){
        int randomValue = (rand() % (maxValue - minValue + 1) + minValue);//生成[minValue,maxValue]内的int型随机数；
        arr[i] = randomValue;
    }
    return arr;
}
void copyArray(int arr2[],const int arr1[],int n){
    for(int i = 0;i < n;i++){
        arr2[i] = arr1[i];
    }
}
void newMethod(int arr[],int n){//选择排序
    for(int i = 0;i < n;i++){
        int min = i;
        for(int j = i;j < n;j++){
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            swap(arr[i],arr[min]);
    }
}
void baoLi(int arr[],int n){//冒泡排序
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - i -1;j++){
            if(arr[j] > arr[j + 1])
                swap(arr[j],arr[j + 1]);
        }
    }
}
bool isEqual(const int arr1[],const int arr2[],int n){
    for(int i = 0;i < n;i++){
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}
void printArr(int arr[],int n){
    for(int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int biFen(const int arr[],int n,int num){
    int left,right,middle;
    left = 0;
    right = n - 1;
    while(left <= right){
        middle = left + ((right - left) / 2);
        if(arr[middle] < num)
            left = middle + 1;
        else if(arr[middle] > num){
            right = middle - 1;
        }
        else
            return middle;
    }
    return -1;
}
int baoLi(const int arr[],int n,int num){
    for(int i = 0;i < n;i++){
        if(arr[i] == num)
            return i;
    }
    return -1;
}