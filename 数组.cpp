#include<iostream>
#include<vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target);
int searchLeftPos(vector<int>& nums,int target);
int searchRightPos(vector<int>& nums,int target);
int main(){
    vector<int> v1 = {5,7,7,8,8,8,10};
    int k = 10;
    vector<int> v2 = searchRange(v1,k);
    cout << "[" << v2[0] << ", " << v2[1] << "]" << endl;
    return 0;
}



vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2);
    if(nums.size() == 0)
        res[0] = -1; res[1] = -1;
    if(nums[0] > target || nums[nums.size() - 1] < target)
        res[0] = -1; res[1] = -1;
    
    int leftPos = searchLeftPos(nums,target);//大于等于target的最左边位置
    int rightPos = searchRightPos(nums,target);//小于等于target的最右边位置
    res[0] = leftPos;
    res[1] = rightPos;
    //cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    return vector<int> { res[0], res[1]};// leftPos, rightPos//return res;
}
int searchLeftPos(vector<int>& nums,int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] >= target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid + 1;
    }
    if(nums[right + 1] == target)
        return right + 1;
    else
        return -1;
}
int searchRightPos(vector<int>& nums,int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] <= target)
            left = mid + 1;
    }
    if(nums[left - 1] == target)
        return left - 1;
    else
        return -1;
}