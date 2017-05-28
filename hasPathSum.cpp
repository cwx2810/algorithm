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

//判断有没有路径上元素的和为给定sum，用dfs 

bool hasPathSum(TreeNode* root, int sum) {
    //corner case root为空
    if(root==NULL){
    	return false;
	}
	//返回DFS，传入目标数，零时和，树
	return DFS(sum,0,root); 
}
//初始化DFS
bool DFS(int target,int sum,TreeNode* root){
	//corner case root为空
	if(root==NULL){
		return false;
	}
	//初始化sum为每次遍历到的那一层的节点值之和
	sum+=root->val;
	//如果左右子树都为空，即到了叶节点，sum等于目标数则为真，反之亦反
	if(root->left==NULL && root->right==NULL){
		if(target==sum){
			return true;
		}else{
			return false;
		}
	}
	//以上算的是根节点，现在递归左右子树
	bool left=DFS(target,sum,root->left);
	bool right=DFS(target,sum,root->right);
	//返回左子树成立或右子树成立
	return left || right;
}
 
 







 
