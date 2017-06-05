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

//判断二叉树的某条根节点-叶子节点路径为给定sum 

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    //初始化返回的二维数组
    vector<vector<int> > ret;
	//corner case 给定为空树
	if(root==NULL){
		return ret;
	}
	//初始化一维临时数组（他保存了所有一维数组的和，在里面只挑选满足“等于目标数”和“达到叶节点”双重标准的数组） 
	vector<int> curr;
	// DFS，传入二维数组，一维数组，目标数，零时和，根节点 
	DFS(ret,curr,sum,0,root);
	//返回二维数组 
	return ret;
}
//构建DFS
void DFS(vector<vector<int> >& ret,vector<int> curr,int sum,int tmpsum,TreeNode* root){
	//corner case 给定为空树
	if(root==NULL){
		return;
	}
	//初始化临时和是每层根节点值相加
	tmpsum+=root->val;
	//将每层根节点值压到临时一维数组
	curr.push_back(root->val);
	
	//判断满足条件的数组压入返回二维数组 
	if(sum==tmpsum){
		if(root->left==NULL && root->right==NULL){
			//如果临时和等于目标数
			//如果根节点左右子树都为空，到达叶节点
			//压一维数组入二维数组，返回
			ret.push_back(curr);
			return;
		}
	}
	//递归DFS左右子树 
	DFS(ret,curr,sum,tmpsum,root->left);
	DFS(ret,curr,sum,tmpsum,root->right);
}



 
 







 
