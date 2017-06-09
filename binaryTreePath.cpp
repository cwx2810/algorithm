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

//输出二叉树所有从根节点到叶子节点的路径，用DFS，就是输出形式有点烦人 

vector<string> binaryTreePaths(TreeNode* root) {
    //初始化返回数组
    vector<string> ret;
	//corner case根节点为空
	if(root==nullptr) return ret;
	//初始化path数组
	vector<int> path;
	//调用DFS，传入根节点，path，返回数组
	dfs(root,path,ret);
	//返回返回数组 
	return ret;
}
//构建DFS
void dfs(TreeNode* root,vector<int>& path,vector<string>& ret){
	//corner case根节点为空
	if(root==nullptr) return;
	//path压栈根节点的值
	path.push_back(root->val);
	//如果到达叶子节点，调用转换函数压栈返回数组
	if(root->left==nullptr && root->right==nullptr){
		ret.push_back(generatePath(path));
	} else{
		//没到叶子节点，递归左右子树，注意边递归边弹出用于回溯
		if(root->left!=nullptr){
			dfs(root->left,path,ret);
			path.pop_back();
		}
		if(root->right!=nullptr){
			dfs(root->right,path,ret);
			path.pop_back();
		}
	}
}
//构建转换函数，转换结果为字符串
string generatePath(vector<int> path){
	//初始化字符串
	stringstream ss;
	//遍历路径数组path
	int i;
	for(i=0;i<path.size()-1;i++) ss<<path[i]<<"->";
	//输出最后一个
	ss<<path[i];
	//返回字符串
	return ss.str();	
}
 
 
 



 
 







 
