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

//判断是不是平衡二叉树，用DFS判断每个子树的高度 

bool isBalanced(TreeNode* root) {
    //corner case 根节点为空是平衡二叉树 
    if(root==NULL){
    	return true;
	}
    //初始化“是否平衡”为获取树的高度函数
    int isBalanced=getHeight(root);
	//令凡是不满足条件的高度差为-1，不等于-1则是平衡二叉树，反之则不是 
	if(isBalanced != -1){
		return true;
	}else{
		return false;
	}
}
//构建int类型的获取树的高度函数
int getHeight(TreeNode* root){
	//corner case 根节点为空，返回0
	if(root==NULL){
		return 0;
	}
	/*边计算高度边计算差值*/
	//初始化左子树递归高度函数，如果为-1则返回-1
	int leftHeight=getHeight(root->left);
	if(leftHeight == -1){
		return -1;
	}
	//初始化右子树递归高度函数，如果为-1则返回-1
	int rightHeight=getHeight(root->right);
	if(rightHeight == -1){
		return -1;
	}
	//对每个节点都用左右子树高度初始化高度差，哪边高用这边减另一边树高度
	int diffHeight=leftHeight>rightHeight?leftHeight-rightHeight:rightHeight-leftHeight;
	if(diffHeight>1){//如果高度差大于1，返回-1
		return -1;
	}
	//否则（高度差是1或者0），递归下一层再次计算高度差 
	else{
		return diffHeight=(leftHeight>rightHeight?leftHeight:rightHeight)+1;//低的哪边没有孩子了，所以从高的那边往下继续走 
	} 	
}







 
