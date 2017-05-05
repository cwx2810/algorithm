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



//比3sum多了abs判断 
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()<=2){
    	return 0;
	}
	int closet=nums[1]+nums[2]+nums[3];//初始化closet 
	sort(nums.begin(),nums.end());//先排序 
	for(int i=0;i<nums.size();i++){
		int j=i+1;
		int k=nums.size()-1;
		while(j<k){
			int sum=nums[i]+nums[j]+nums[k];//初始化sum 
			if(sum==target){
				return sum;
			}
			if(abs(target-sum)<abs(target-closet)){//逼近的够小就替换 
				closet=sum;
			}
			if(sum>target){//不断逼近 
				k--;
			}else{
				j++;
			}
		}
	}
	return closet;
}


