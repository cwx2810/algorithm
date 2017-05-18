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



//求二叉树的最大深度 
//遍历二叉树，递归求level 

//定义全局返回值 
int num;
int maxDepth(TreeNode* root) {
    //corner case根节点不存在
    if(!root){
    	return 0;
	}
	//初始化num为最小值
	num=numeric_limits<int>::min();
	//调用travel函数，从根节点开始递归
	travel(root,1);
	//返回num 
	return num;
}
//travel函数
void travel(TreeNode *node,int level){
	//如果没有左右子树，则是根节点，返回num
	if(!node->left && !node->right){
		num=max(num,level);
		return;
	}
	//如果有左右子树，则递归 
	if(node->left){
		travel(node->left,level+1);
	}
	if(node->right){
		travel(node->right,level+1);
	}
}

