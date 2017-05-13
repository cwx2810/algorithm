#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target);

int main(){
	int A[]={5,7,7,8,8,10};
	vector<int> nums(A,A+6);
	int target=7;
	vector<int> result=searchRange(nums,target);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}



//���������е��ڸ���ֵ������Ԫ�ص������±꣬Ҫ��ʱ�临�Ӷ�logn
//˼·�������ζ��� 
vector<int> searchRange(vector<int>& nums, int target){
	//corner case
	if(nums.size()==0){
		return vector<int>({-1,-1});
	}
	//��ʼ�����淵��ֵ��Χ��vector����
	vector<int> v;
	//��ʼ����������ͺ�����α�
	int low=0;
	int high=nums.size()-1;
	//���ֲ��ҵ�һ��λ�ӣ�������>=�ϣ�ÿ�ζ�����ͷ�ˣ�Ȼ��һ��low����high�ˣ���ʱ�պ�low�ǵ�һ��λ�� 
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]>=target){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	//���ҵ����±�ѹջ����һ��corner case 
	if(low<nums.size() && nums[low]==target){
		v.push_back(low);
	}else{
		return vector<int>({-1,-1});
	}
	//�ڶ��γ�ʼ��
	low=low;
	high=nums.size()-1;
	//���ֲ������һ��λ�ӣ��͵�һ�ζ��ַ����� 
	while(low<=high){
		int mid=(low+high)/2;
		if(nums[mid]<=target){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	//���ҵ����±�ѹջ����һ�ζ������Ѿ��ж��˿϶��������Ԫ�ص�����£��ڶ��ξͲ����ж�corner case�� 
	v.push_back(high);
	return v;
}
