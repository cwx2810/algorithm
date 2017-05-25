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

//�ж��ǲ��Ǿ����������õݹ�

bool isSymmetric(TreeNode* root) {
    //corner case���ڵ�Ϊ�գ�����Ҳ�Ǿ�����
    if(root==NULL){
    	return true;
	}
	//���õݹ飬������������
	return Helper(root->left,root->right); 
}
//�����ݹ麯��
bool Helper(TreeNode* left,TreeNode* right){
	//corner case���Ҷ�Ϊ�գ���ֻ�и�ͬ���Ǿ�����
	if(left==NULL&&right==NULL){
		return true;
	}else if(left==NULL||right==NULL){	//���ߵ���Ϊ���ǾͲ�����
		return false;
	}
	//�ݹ�Ҫ��1�����ҽڵ�ֵ���
	bool cond1=left->val==right->val;
	//�ݹ�Ҫ��2���ݹ����������������������������������
	bool cond2=Helper(left->left,right->right);
	//�ݹ�Ҫ��3���ݹ����������������������������������
	bool cond3=Helper(left->right,right->left);
	//����ͬʱ���������ݹ�Ҫ�� 	
	return cond1&&cond2&&cond3;
}






 
