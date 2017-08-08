#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findMin(vector<int> &nums);

int main(){
	int a[]={10,1,10,10,10};
    vector<int> A(a,a+5);
    int result=findMin(A);
    cout<<result<<endl;
}



//有重复元素的先排好序又滚动了一次的数组里找最小值，和没重复的区别就在于如果发现mid=开始元素，跳过开始（i++）即可  
int findMin(vector<int> &nums){
	//corner case 给定数组仅有0个，1个，2个元素 
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
		if(nums[i]<nums[j]){//直接是排好序的，开始元素就是最小的 
			return nums[i];
		}
		int mid=(i+j)/2;//初始化中间点 
		if(nums[mid]>nums[i]){//中间大于开始，在后面查找 
			i=mid;
		}else if(nums[mid]<nums[i]){//中间小于开始，在前面查找 
			j=mid;
		}else{//中间等于开始，跳过开始 
			i++;
		}
	}
	return min(nums[i],nums[j]);
}


