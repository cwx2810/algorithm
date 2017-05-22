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

//�����������������������ά���飬����һ��Ԫ�ؾ���һ��
//˼·���Ƚ�����ά���飬��С��DFS����������Ⱦ�������DFSÿһ���Ԫ�� 
vector<vector<int> > levelOrder(TreeNode* root) {
    //��ʼ�����
    int depth=getHeight(root);
	//������ȳ�ʼ����ά����
	vector<vector<int> > ret(depth);
	//corner case��һ���Ϊ0
	if(depth==0){
		return ret;
	}
	//���õݹ�ѹջ����
	getSolution(ret,root,0);
	//���ض�ά���� 
	return ret;
}
//�����ݹ�ѹջ������������ά�����Ԫ��
void getSolution(vector<vector<int> > &ret,TreeNode* root,int level){
	//corner case���ڵ�Ϊ��
	if(root==NULL){
		return;
	}
	//ѹ����ڵ�
	ret[level].push_back(root->val);
	//���������ݹ����
	getSolution(ret,root->left,level+1);
	//���������ݹ���� 
	getSolution(ret,root->right,level+1);
}
//����DFS��Ⱥ������ó������������ 
int getHeight(TreeNode* root){
	//corner case���ڵ�Ϊ��
	if(root==NULL){
		return 0;
	}
	//�ݹ��ʼ��������
	int left=getHeight(root->left);
	//�ݹ��ʼ���Ҳ����
	int right=getHeight(root->right);
	//�ı߸�height�Ͱ��ı߸���height��ÿ�εݹ�����1��߶� 
	int height=(left>right?left:right)+1;
	//����height
	return height;
}


 
