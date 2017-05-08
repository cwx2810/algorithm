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



//有重复元素的数组里找最小值，和没重复的区别就在于如果发现mid=i，跳过i（i++）即可 
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
		if(nums[i]<nums[j]){
			return nums[i];
		}
		int mid=(i+j)/2;
		if(nums[mid]>nums[i]){
			i=mid;
		}else if(nums[mid]<nums[i]){
			j=mid;
		}else{
			i++;
		}
	}
	return min(nums[i],nums[j]);
}


