#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��������������п��ܵı������У���combination����ֻ����combination��������ϣ�permutation����͸�������һ���������� 
//ͬ������DFS������ѹջ��ÿ��Ԫ��Ϊ�׵����У�����bool������������Ϊtrue 
vector<vector<int>> permute(vector<int>& nums) {
    //��ʼ�����ض�ά����
    vector<vector<int>> ret;
	//corner case��������Ϊ��
	if(nums.size()==0) return ret;
	//��ʼ��һά����
	vector<int> curr;
	//��ʼ��bool���飬��С�͸�������һ������ʼΪfalse
	vector<bool> isVisited(nums.size(),false); 
	//���û��ݺ���
	backTracking(ret,curr,isVisited,nums);
	//���� 
	return ret;
}
//������ݺ��������뷵�ض�ά���飬һά���У�������飬��������
void backTracking(vector<vector<int>> &ret,vector<int> curr,vector<bool> isVisited,vector<int> nums){
	//һά�����С���ڸ������飬˵���������������������飬ѹջ������
	if(curr.size()==nums.size()){
		ret.push_back(curr);
		return;
	}
	//������������
	for(int i=0;i<nums.size();++i){
		//��ǰ�ڵ�û�б�Ǿͽ��б�ǺͲ�������ǹ��˾�����������һ��
		if(isVisited[i]==false){
			//��ǵ�ǰ�ڵ� 
			isVisited[i]=true;
			//�ѵ�ǰ�ڵ�ѹ��һά����
			curr.push_back(nums[i]);
			//��Ȼ���
			backTracking(ret,curr,isVisited,nums);
			//������ݵ�ͷ���ص���������ñ��Ϊfalse����ջ
			isVisited[i]=false;
			curr.pop_back();
		} 
	}
} 
