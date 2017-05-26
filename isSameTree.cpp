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

//判断是不是相等树，采用递归

bool isSameTree(TreeNode* p, TreeNode* q) {
    //corner case 两棵树都是空树，当然相等
    if(p==NULL && q==NULL){
    	return true;
	}else if(p==NULL || q==NULL){//或者只有一颗是空树，不相等
		return false;
	}
	//两棵树根节点值相等，则递归他们的对应子树是不是相等
	if(p->val==q->val){
		bool left=isSameTree(p->left,q->left);
		bool right=isSameTree(p->right,q->right);
		return left&&right;
	}
	//都不是，返回false 
	return false;
}






 
