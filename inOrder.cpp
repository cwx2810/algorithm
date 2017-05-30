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

//二叉树中序遍历，使用迭代，用stack保存所有左边的根节点(其实就是保存根节点)，以便于得到右子树 

vector<int> inorderTraversal(TreeNode* root) {
    //初始化数组 
    vector<int> ret;
    //corner case根节点为空
    if(root==NULL){
    	return ret;
	}
	//初始化保存树的stack
	vector<TreeNode*> nodes;
	//初始化根节点p 
	TreeNode* p=root;
	//p存在或者stack不为空，迭代
	while(p || !nodes.empty()){
		//一直遍历左子树，将根节点压入stack
		while(p){
			nodes.push_back(p);
			p=p->left;
		}
		//如果stack不为空，初始化p获取stack节点（左侧根节点），将其值压入数组
		if(!nodes.empty()){
			p=nodes.back();
			ret.push_back(p->val);//这里在将左侧压入数组的过程中也包括了根节点，不用担心 
			//弹出节点，初始化p为右子树（获取右子树）继续压入数组
			nodes.pop_back();
			p=p->right;
		}	
	}
	//返回ret 
	return ret;
}
 
 







 
