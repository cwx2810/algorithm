#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findMin(vector<int> &nums);

int main(){
	int a[]={4,5,6,7,2,2,2};
    vector<int> A(a,a+7);
    int result=findMin(A);
    cout<<result<<endl;
}



//���ظ�Ԫ�ص�����������Сֵ����û�ظ�������������������mid=i������i��i++������ 
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
		if(mid>i){
			i=mid;
		}else if(mid<i){
			j=mid;
		}else{
			i++;
		}
	}
	return min(nums[i],nums[j]);
}


