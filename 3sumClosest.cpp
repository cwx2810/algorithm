#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target); 

int main(){
	int a[]={-1,0,1,2,-1,-4};
    vector<int> A(a,a+6);
    int t=6;
    int result=threeSumClosest(A,t);
	cout<<result<<" ";
}


//给定数组和一个值，要求找出三个数，他们的和尽量接近给定数 
//比3sum多了abs判断 
int threeSumClosest(vector<int>& nums, int target) {
	//corner case 给定数组不足三个数 
    if(nums.size()<=2){
    	return 0;
	}
	int closet=nums[1]+nums[2]+nums[3];//初始化返回的最接近的三个数只和，初始为前三个数 
	sort(nums.begin(),nums.end());//先排序 
	for(int i=0;i<nums.size();i++){
		int j=i+1;
		int k=nums.size()-1;
		while(j<k){
			int sum=nums[i]+nums[j]+nums[k];//初始化sum 
			if(sum==target){
				return sum;//不用再移动游标，有这一组足够了 
			}
			if(abs(target-sum)<abs(target-closet)){//逼近的够小就替换 
				closet=sum;
			}
			if(sum>target){//因为是排过序的，所以发生和比给定数大的情况，一定是太靠外了，不满足条件，两端游标不断逼近 
				k--;
			}else{
				j++;
			}
		}
	}
	return closet;
}


