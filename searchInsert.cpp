#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target);

int main(){
	int A[]={1,3,5,6};
	vector<int> nums(A,A+4);
	int target=7;
	int result=searchInsert(nums,target);
	cout<<result;
}



//���������е���target��λ�ӣ�����û�е���target�ľ���һ�����������������Ȼ���� 
//˼·���պÿ����ö��ֲ��ң��ҵ���ã��Ҳ����ͷ���target����С����һ��target��������ǲ����
//��ʵ���Ƿ�������ѭ�����low����Ϊѭ����low<=high 
int searchInsert(vector<int>& nums, int target){
	//��ʼ��low��high
	int low=0;
	int high=nums.size()-1;
	//����
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]==target){
			return mid;
		}else if(nums[mid]<target){
			low=mid+1;
		}else{
			high=mid-1;
		}
	} 
	return low;
}
