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

//二叉树前序遍历，使用迭代，用stack保存右子树 

vector<int> preorderTraversal(TreeNode* root) {
    //初始化返回数组 
    vector<int> ret;
	//corner case 根节点为空，直接返回空数组
	if(root==NULL){
		return ret;
	}
	//初始化stack保存树
	vector<TreeNode*> nodes;
	//根节点压入stack
	nodes.push_back(root);
	//当stack不为空时，迭代 
	while(!nodes.empty()){
		//取栈顶树节点将其值压入数组
		TreeNode* n=nodes.back();
		ret.push_back(n->val);
		//弹出栈顶树节点
		nodes.pop_back();
		//如果该节点有右子树，则压栈保存，循环操作所有左子树
		if(n->right){//前序遍历是先访问左子树没错，但是要先压栈保存右子树，这样刚好左子树压栈后先操作左子树，后操作右子树 
			nodes.push_back(n->right);
		}
		//同样，循环操作右子树 
		if(n->left){
			nodes.push_back(n->left);
		}
	}
	//跳出循环，返回数组
	return ret;
}
 
 







 
