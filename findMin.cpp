#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findMin(vector<int> &nums);

int main(){
	int a[]={4,5,6,7,1,2,3};
    vector<int> A(a,a+7);
    int result=findMin(A);
    cout<<result<<endl;
}



//在轮转排序数组里找最小值，先用二分查找，关键在于找到中间数以后如何判断大小
//经过观察不难看出，如果中间数大于开始数，则最小值落在右边区间，如果中间数小于开始数，则最小值落在左边区间 
int findMin(vector<int> &nums){
	if(nums.size()==0){
		return 0;
	}
	if(nums.size()==1){
		return nums[0];
	}
	if(nums.size()==2){
		return min(nums[0],nums[1]);
	}
	int i=0;
	int j=nums.size()-1;
	while(i<j-1){
	/*
	* 注意这道题的另一个难点就在这个j-1上，如果i和j贴死，会造成一种局面:
	* 最后剩下两个数，第一个比第二个大，第一个始终是mid，无限循环ing
	* 需要设置中间隔一个数，这样每次剩余两个数时就会跳出循环
	*/ 
		if(nums[i]<nums[j]){
			return nums[i];
		}
		int mid=(i+j)/2;
		if(nums[mid]>nums[i]){
			i=mid;
		}else if(nums[mid]<nums[i]){
			j=mid;
		}
	}
	return min(nums[i],nums[j]);
}


