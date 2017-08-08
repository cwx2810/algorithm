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



//���ظ�Ԫ�ص����ź����ֹ�����һ�ε�����������Сֵ����û�ظ�������������������mid=��ʼԪ�أ�������ʼ��i++������  
int findMin(vector<int> &nums){
	//corner case �����������0����1����2��Ԫ�� 
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
		if(nums[i]<nums[j]){//ֱ�����ź���ģ���ʼԪ�ؾ�����С�� 
			return nums[i];
		}
		int mid=(i+j)/2;//��ʼ���м�� 
		if(nums[mid]>nums[i]){//�м���ڿ�ʼ���ں������ 
			i=mid;
		}else if(nums[mid]<nums[i]){//�м�С�ڿ�ʼ����ǰ����� 
			j=mid;
		}else{//�м���ڿ�ʼ��������ʼ 
			i++;
		}
	}
	return min(nums[i],nums[j]);
}


