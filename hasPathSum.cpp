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

//�ж���û��·����Ԫ�صĺ�Ϊ����sum����dfs 

bool hasPathSum(TreeNode* root, int sum) {
    //corner case rootΪ��
    if(root==NULL){
    	return false;
	}
	//����DFS������Ŀ��������ʱ�ͣ���
	return DFS(sum,0,root); 
}
//��ʼ��DFS
bool DFS(int target,int sum,TreeNode* root){
	//corner case rootΪ��
	if(root==NULL){
		return false;
	}
	//��ʼ��sumΪÿ�α���������һ��Ľڵ�ֵ֮��
	sum+=root->val;
	//�������������Ϊ�գ�������Ҷ�ڵ㣬sum����Ŀ������Ϊ�棬��֮�෴
	if(root->left==NULL && root->right==NULL){
		if(target==sum){
			return true;
		}else{
			return false;
		}
	}
	//��������Ǹ��ڵ㣬���ڵݹ���������
	bool left=DFS(target,sum,root->left);
	bool right=DFS(target,sum,root->right);
	//��������������������������
	return left || right;
}
 
 







 
