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

//判断一棵树是不是二叉搜索树，使用递归判别节点左子树小右子树大 

bool isValidBST(TreeNode* root) {
    //返回递归函数，传入根节点、初始化允许的最小值、初始化允许的最大值 
    return valid(root,NULL,NULL);
}
//建立递归函数
bool valid(TreeNode* root,TreeNode* minNode,TreeNode* maxNode){
	//corner case 没有根节点
	if(!root){
		return true;
	}
	//如果最小最大节点存在，根节点比最小值小或比最大值大，返回false
	//（当递归到左边最大值就是原根节点，递归到右边最小值就是原根节点）
	if(minNode&&root->val<=minNode->val || maxNode&&root->val>=maxNode->val){
		return false;
	}
	//返回递归判断左右子树	
	return valid(root->left,minNode,root) && valid(root->right,root,maxNode);
}
 



 
 







 
