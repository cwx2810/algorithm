#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��n������ѡk����������ϣ�ȥ���ظ��ģ��õݹ� 
 

vector<vector<int>> combine(int n, int k) {
    //��ʼ����������
    vector<vector<int> > ret;
	//corner case ������n����
	if(n<=0) return ret;
	//��ʼ��һά�������
	vector<int> curr; 
	//DFS 
	DFS(ret,curr,n,k,1);
	//���� 
	return ret;
}
//����DFS�������ά�������飬һάk������������飬n��k��DFS���
void DFS(vector<vector<int> > &ret,vector<int> curr,int n,int k,int level){
	//��һά����������k����ʱ��ѹ���ά���飬���أ�֮���Կ���ֱ�ӷ��أ�����Ϊһֱ�ڵݹ飩
	if(curr.size()==k){
		ret.push_back(curr);
		return;
	}
	//һά��ϴ���k��ֱ�ӷ��أ������֦�����ǿ��ǵ���ʡ�ݹ�ʱ��
	if(curr.size()>k){
		return;
	}
	//����1~n�� 
	for(int i=level;i<=n;++i){
		//������������ѹ��һά����
		curr.push_back(i);
		//�ݹ�DFS����ȥ�ж��ǲ��ǳ���k��
		DFS(ret,curr,n,k,i+1);
		//����k�᷵�������ջ
		curr.pop_back();
	}
}
 
 
