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

//层序遍历二叉树，将其存入二维数组，数组一个元素就是一层，以zigzag的方式排布 

//初始化二维数组 
vector<vector<int> > ret;
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    //初始化构建函数，传入root和level
    build(root,1);
    //翻转二维数组，注意遍历是从第二行开始，每次i+2，因为zigzag是隔一行翻转一次 
    for(int i=1;i<ret.size();i=i+2){
    	reverse(ret[i].begin(),ret[i].end());//reverse传入要翻转的容器的头和尾 
	}
	//返回二维数组 
	return ret;
}
//构建函数
void build(TreeNode* root,int level){
	//corner case没有根节点
	if(!root){
		return;
	}
	//如果数组大小小于层数数量，说明没有把所有层都压进去，则压栈第一维 
	if(ret.size()<level){//压到level-1要停止，再压一次刚好压到level层 
		ret.push_back(vector<int>());
	}
	//给数组第二维压入元素值
	ret[level-1].push_back(root->val);//ret从零开始，level-1才是其下标 
	//如果有左子树，递归调用构建函数
	if(root->left){
		build(root->left,level+1);
	}
	//如果有右子树，递归调用构建函数
	if(root->right){
		build(root->right,level+1);
	}
}




 
