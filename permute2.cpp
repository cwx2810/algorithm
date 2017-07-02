#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��������������п��ܵı������У���θ����������ظ�Ԫ�أ��𰸵����в�����ͬ 
//�Ը��������������������ͬ��Ԫ�ؾͻ���һ������������˼·����ÿ��Ԫ��Ϊ��׼����������
//����һ�������ĳ��Ԫ�ص����У����������һ�����ظ�Ԫ�ؾ������������ͱ�������ͬ�������� 
vector<vector<int>> permuteUnique(vector<int>& nums) {
    //��ʼ�����ض�ά����
    vector<vector<int>> ret;
	//corner case��������Ϊ��
	if(nums.size()==0) return ret;
	//��ʼ��һά����
	vector<int> curr;
	//��ʼ��������У���С���ڸ������飬��ʼ��Ϊfalse
	vector<bool> isVisited(nums.size(),false);
	//�ȶԸ��������������
	sort(nums.begin(),nums.end());
	//�ݹ�
	backTracking(ret,curr,nums,isVisited);
	//���� 
	return ret;
}
//�����ݹ麯���������ά�������飬һά���飬�������飬�������
void backTracking(vector<vector<int>> &ret,vector<int> curr,vector<int> nums,vector<bool> isVisited){
	//���һά���д�С���ڸ������У�ѹջ��ɣ�ѹ���ά���鲢����
	if(curr.size()==nums.size()){
		ret.push_back(curr);
		return;
	}
	//����
	for(int i=0;i<nums.size();++i){
		//���δ��ǣ����������ǹ��˲�����������
		if(isVisited[i]==false){
			//���֮
			isVisited[i]=true;
			//ѹջһά����
			curr.push_back(nums[i]);
			//��ȵݹ�
			backTracking(ret,curr,nums,isVisited);
			//�ݹ鵽ͷ�����ص���������һ��·�������õ�ǰ�ڵ�Ϊδ����
			isVisited[i]=false;
			//��ջ
			curr.pop_back();
			//�������ظ�Ԫ��ʱ������
			while(i<nums.size()-1&&nums[i]==nums[i+1]) ++i;
		}
	}
}
