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



//�ҵ���ֵԪ�ص�index��Ҫ���Ԫ�ش��������ߵ�Ԫ��
//˼·�����ֲ��ң����mid�����ߴ�ֱ�ӷ��أ����mid��ߴ󣬼���������ҷ�ֵ���Դ����� 
int findPeakElement(vector<int>& nums){
	//corner case�����о�һ��Ԫ�أ�ֱ�ӷ���0 
	if(nums.size()==1){
		return 0;
	}
	//��ʼ��ͷβ��ͬʱΪ����󷵻�midҪ������ͳ�ʼ��mid��������ѭ���г�ʼ�� 
	int start=0;
	int end=nums.size()-1;
	int mid=0;
	//�仯�Ķ���
	while(start<=end){
		mid=(start+end)/2;
		//midֱ���Ƿ�ֵ���߰�mid�Ƶ����˵���� 
		if(mid==0||nums[mid]>=nums[mid-1] && mid==nums.size()-1||nums[mid]>=nums[mid+1]){
			return mid;
		}else if(mid>0 && nums[mid-1]>nums[mid]){//mid��߱�mid��������� 
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	//�������ѭ��������mid�� 
	//Ϊʲô����mid����Ϊ����ѭ����������start��end��
	//������ѭ�������ı����start��end��ֵ���⵼����ѭ����������
	//��mid�ǲ���ģ�����ȷ����������ֵ��������ֵ�����Է���mid 
	return mid;
}
