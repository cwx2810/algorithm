#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findPeakElement(vector<int>& nums);

int main(){
	int A[]={1,2,3,1};
	vector<int> nums(A,A+4);
	int result=findPeakElement(nums);
	cout<<result;
}



//找到峰值元素的index，要求次元素大于他两边的元素
//思路：二分查找，如果mid比两边大直接返回，如果mid左边大，继续在左边找峰值，以此类推 
int findPeakElement(vector<int>& nums){
	//corner case数组中就一个元素，直接返回0 
	if(nums.size()==1){
		return 0;
	}
	//初始化头尾，同时为了最后返回mid要在这里就初始化mid，不能在循环中初始化 
	int start=0;
	int end=nums.size()-1;
	int mid=0;
	//变化的二分
	while(start<=end){
		mid=(start+end)/2;
		//mid直接是峰值或者把mid逼到两端的情况 
		if(mid==0||nums[mid]>=nums[mid-1] && mid==nums.size()-1||nums[mid]>=nums[mid+1]){
			return mid;
		}else if(mid>0 && nums[mid-1]>nums[mid]){//mid左边比mid大，向左查找 
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	//如果跳出循环，返回mid， 
	//为什么返回mid，因为跳出循环的条件是start比end大，
	//而二分循环里后面改变的是start和end的值，这导致了循环的跳出，
	//而mid是不变的，是正确的数组最后的值，即最大的值，所以返回mid 
	return mid;
}
