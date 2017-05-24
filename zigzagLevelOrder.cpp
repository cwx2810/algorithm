#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
}

//�����������������������ά���飬����һ��Ԫ�ؾ���һ�㣬��zigzag�ķ�ʽ�Ų� 

//��ʼ����ά���� 
vector<vector<int> > ret;
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    //��ʼ����������������root��level
    build(root,1);
    //��ת��ά���飬ע������Ǵӵڶ��п�ʼ��ÿ��i+2����Ϊzigzag�Ǹ�һ�з�תһ�� 
    for(int i=1;i<ret.size();i=i+2){
    	reverse(ret[i].begin(),ret[i].end());//reverse����Ҫ��ת��������ͷ��β 
	}
	//���ض�ά���� 
	return ret;
}
//��������
void build(TreeNode* root,int level){
	//corner caseû�и��ڵ�
	if(!root){
		return;
	}
	//��������СС�ڲ���������˵��û�а����в㶼ѹ��ȥ����ѹջ��һά 
	if(ret.size()<level){//ѹ��level-1Ҫֹͣ����ѹһ�θպ�ѹ��level�� 
		ret.push_back(vector<int>());
	}
	//������ڶ�άѹ��Ԫ��ֵ
	ret[level-1].push_back(root->val);//ret���㿪ʼ��level-1�������±� 
	//��������������ݹ���ù�������
	if(root->left){
		build(root->left,level+1);
	}
	//��������������ݹ���ù�������
	if(root->right){
		build(root->right,level+1);
	}
}




 
