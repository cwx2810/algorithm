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



//求二叉树的孩子的最小深度 
//遍历二叉树，递归求level 

//定义全局返回深度 
int num;
int minDepth(TreeNode* root){
	//corner case
	if(!root){
		return 0;
	}
	//初始化深度为最大
	num=numeric_limits<int>::max();
	//调用travel遍历二叉树求深度，不断改变num 
	travel(root,1);
	//返回 
	return num;
}
//travel函数
void travel(TreeNode *node,int level){
	//没有左右孩子，则已经到了某个孩子，求最小值
	if(!node->left && !node->right){
		num=min(num,level);
		return;
	}
	//有孩子，则递归算孩子的最小值
	if(node->left){
		travel(node->left,level+1);
	} 
	if(node->right){
		travel(node->right,level+1);
	}
} 
