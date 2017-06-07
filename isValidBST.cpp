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

//�ж�һ�����ǲ��Ƕ�����������ʹ�õݹ��б�ڵ�������С�������� 

bool isValidBST(TreeNode* root) {
    //���صݹ麯����������ڵ㡢��ʼ���������Сֵ����ʼ����������ֵ 
    return valid(root,NULL,NULL);
}
//�����ݹ麯��
bool valid(TreeNode* root,TreeNode* minNode,TreeNode* maxNode){
	//corner case û�и��ڵ�
	if(!root){
		return true;
	}
	//�����С���ڵ���ڣ����ڵ����СֵС������ֵ�󣬷���false
	//�����ݹ鵽������ֵ����ԭ���ڵ㣬�ݹ鵽�ұ���Сֵ����ԭ���ڵ㣩
	if(minNode&&root->val<=minNode->val || maxNode&&root->val>=maxNode->val){
		return false;
	}
	//���صݹ��ж���������	
	return valid(root->left,minNode,root) && valid(root->right,root,maxNode);
}
 



 
 







 
