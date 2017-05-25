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

//判断是不是镜像树，采用递归

bool isSymmetric(TreeNode* root) {
    //corner case根节点为空，空树也是镜像树
    if(root==NULL){
    	return true;
	}
	//调用递归，传入左右子树
	return Helper(root->left,root->right); 
}
//建立递归函数
bool Helper(TreeNode* left,TreeNode* right){
	//corner case左右都为空，即只有根同样是镜像树
	if(left==NULL&&right==NULL){
		return true;
	}else if(left==NULL||right==NULL){	//或者单边为空那就不是了
		return false;
	}
	//递归要求1：左右节点值相等
	bool cond1=left->val==right->val;
	//递归要求2：递归左子树的左子树，右子树的右子树相等
	bool cond2=Helper(left->left,right->right);
	//递归要求3：递归左子树的右子树，右子树的左子树相等
	bool cond3=Helper(left->right,right->left);
	//返回同时满足三个递归要求 	
	return cond1&&cond2&&cond3;
}






 
