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

//层序遍历二叉树，将其存入二维数组，数组一个元素就是一层
//思路，先建立二维数组，大小由DFS查找树的深度决定，再DFS每一层的元素 
vector<vector<int> > levelOrder(TreeNode* root) {
    //初始化深度
    int depth=getHeight(root);
	//根据深度初始化二维数组
	vector<vector<int> > ret(depth);
	//corner case万一深度为0
	if(depth==0){
		return ret;
	}
	//调用递归压栈函数
	getSolution(ret,root,0);
	//返回二维数组 
	return ret;
}
//建立递归压栈函数，构建二维数组的元素
void getSolution(vector<vector<int> > &ret,TreeNode* root,int level){
	//corner case根节点为空
	if(root==NULL){
		return;
	}
	//压入根节点
	ret[level].push_back(root->val);
	//对左子树递归调用
	getSolution(ret,root->left,level+1);
	//对右子树递归调用 
	getSolution(ret,root->right,level+1);
}
//建立DFS深度函数，得出二叉树的深度 
int getHeight(TreeNode* root){
	//corner case根节点为空
	if(root==NULL){
		return 0;
	}
	//递归初始化左侧深度
	int left=getHeight(root->left);
	//递归初始化右侧深度
	int right=getHeight(root->right);
	//哪边高height就把哪边赋给height，每次递归增加1层高度 
	int height=(left>right?left:right)+1;
	//返回height
	return height;
}


 
