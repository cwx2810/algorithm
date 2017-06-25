#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�ҵ����������е������������ʹ����ϵ�sum=target�����Ҫ����targetҪ�������������ظ�ȡ��
//��һ���ǹ涨k������ϣ���ѹջ������k�Ƚϣ���һ���Ǹ�����ϵ�sum��ֱ��ѹջ��sum��sum��0�Ƚϡ��ݹ飬����������ѹ��ret 
 

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //��ʼ�����ض�ά����
    vector<vector<int> > ret;
	//corner case��������Ϊ�ջ���target��������
	if(candidates.size()==0||target<0){
		return ret;
	}
	//��ʼ�����һά����
	vector<int> curr;
	//�ȶԸ�����������
	sort(candidates.begin(),candidates.end());
	//�ݹ麯��
	BackTracking(ret,curr,candidates,target,0);
	//���� 
	return ret;
}
//�����ݹ麯�������뷵�ض�ά���飬���һά���飬�������飬����target���ݹ����
void BackTracking(vector<vector<int> > &ret,vector<int> curr,vector<int> candidates,int target,int level){
	//ÿ�β������飬һά����ӽ�ȥһ����target��һ��������պü�������0��˵��������������������target
	if(target==0){
		ret.push_back(curr);
	}
	//�������С��0�������㣬ֱ�ӷ��أ������Ǵ���0������0˵������û���չ�������������ݹ�
	else if(target<0){
		return;
	}
	//�ݹ��������
	for(int i=level;i<candidates.size();++i){
		//targetÿ�����յ�ǰ����ֵ����һ�ξͲ��������ˣ�����ÿ�μ�ȥ��ǰ����ֵ
		target-=candidates[i];
		//ѹջ��ǰ��ֵ
		curr.push_back(candidates[i]);
		//��ȵݹ飬�ٴ����յ�ǰi��ֵ��ֱ�����պ�С��0�����ص����ִ����һ��
		BackTracking(ret,curr,candidates,target,i);
		//��С��0��˵�����մ��ˣ�����ջ��
		curr.pop_back();
		//��targetҲ�ӻ�����������һ��i
		target+=candidates[i]; 
	}
}

 
 
