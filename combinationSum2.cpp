#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�ҵ����������е������������ʹ����ϵ�sum=target�����Ҫ����targetҪ�������������ظ�ȡ��
//�����combinationSumһģһ����Ψһ��������ÿ�ε���ǰ��һ���ж���ȡ���Ƿ��ظ����ظ���Ҫ���� 
 

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //��ʼ����ά��������
    vector<vector<int> > ret;
	//corner case����Ϊ�ջ�target��������
	if(candidates.size()==0||target<0) return ret;
	//��ʼ��һά�������
	vector<int> curr;
	//������
	sort(candidates.begin(),candidates.end());
	//�ݹ����
	BackTracking(ret,curr,candidates,target,0);
	//���� 
	return ret;
}
//���������㷨�����뷵�ض�ά���飬һά������ϣ��������飬target���ݹ����
void BackTracking(vector<vector<int> > &ret,vector<int> curr,vector<int> candidates,int target,int level){
	//target�����պ�Ϊ0������������ѹջ����
	if(target==0){
		ret.push_back(curr);
		return;
	}
	//target����С��0������������������
	else if(target<0){
		return;
	}
	//������������
	for(int i=level;i<candidates.size();++i){
		//ÿ��������һ������target�ͼ�ȥ�����
		target-=candidates[i];
		//ѹջ����
		curr.push_back(candidates[i]);
		//����������ݹ�
		BackTracking(ret,curr,candidates,target,i+1);
		//������������������ص������ջ
		curr.pop_back();
		//��target�ӻ���
		target+=candidates[i];
		//�ж���ȡ���Ƿ��ظ������ظ�������
		while(i<candidates.size()-1&&candidates[i]==candidates[i+1]) ++i;
	}
}
 

 
 
