#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target);

int main(){
	int A[]={1,3,5,6};
	vector<int> nums(A,A+4);
	int target=7;
	int result=searchInsert(nums,target);
	cout<<result;
}



//查找数组中等于target的位子，或者没有等于target的就找一个插入点插入后数组任然有序 
//思路：刚好可以用二分查找，找到最好，找不到就返回target的最小的那一个target，这个就是插入点
//其实就是返回跳出循环后的low，因为循环是low<=high 
int searchInsert(vector<int>& nums, int target){
	//初始化low和high
	int low=0;
	int high=nums.size()-1;
	//二分
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]==target){
			return mid;
		}else if(nums[mid]<target){
			low=mid+1;
		}else{
			high=mid-1;
		}
	} 
	return low;
}
