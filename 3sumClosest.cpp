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



//��3sum����abs�ж� 
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()<=2){
    	return 0;
	}
	int closet=nums[1]+nums[2]+nums[3];//��ʼ��closet 
	sort(nums.begin(),nums.end());//������ 
	for(int i=0;i<nums.size();i++){
		int j=i+1;
		int k=nums.size()-1;
		while(j<k){
			int sum=nums[i]+nums[j]+nums[k];//��ʼ��sum 
			if(sum==target){
				return sum;
			}
			if(abs(target-sum)<abs(target-closet)){//�ƽ��Ĺ�С���滻 
				closet=sum;
			}
			if(sum>target){//���ϱƽ� 
				k--;
			}else{
				j++;
			}
		}
	}
	return closet;
}


