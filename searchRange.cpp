#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target);

int main(){
	int A[]={5,7,7,8,8,10};
	vector<int> nums(A,A+6);
	int target=7;
	vector<int> result=searchRange(nums,target);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}



//返回数组中等于给定值的所有元素的两端下标，要求时间复杂度logn
//思路：用两次二分 
vector<int> searchRange(vector<int>& nums, int target){
	//corner case
	if(nums.size()==0){
		return vector<int>({-1,-1});
	}
	//初始化保存返回值范围的vector数组
	vector<int> v;
	//初始化搜索的最低和最高游标
	int low=0;
	int high=nums.size()-1;
	//二分查找第一个位子，精髓在>=上，每次都减过头了，然后一加low超过high了，此时刚好low是第一个位子 
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]>=target){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	//将找到的下标压栈，另一个corner case 
	if(low<nums.size() && nums[low]==target){
		v.push_back(low);
	}else{
		return vector<int>({-1,-1});
	}
	//第二次初始化
	low=low;
	high=nums.size()-1;
	//二分查找最后一个位子，和第一次二分反着来 
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]<=target){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	//将找到的下标压栈，上一次二分完已经判断了肯定存在这个元素的情况下，第二次就不用判断corner case了 
	v.push_back(high);
	return v;
}
