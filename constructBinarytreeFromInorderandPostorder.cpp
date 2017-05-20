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

//用中序和后序遍历构造二叉树
//思路，用后序遍历末尾元素得到根节点，
//在中序遍历中找到此节点并拆分为左右两边，左侧的元素为左子树，右侧的为右子树
//将后序遍历减去末节点后一分为二，元素和中序遍历一一对应，在两边递归进行，查找末节点，拆分

//初始化哈希表，便于查找中序遍历的中间节点
unordered_map<int,int> m;
//总建造函数，传入中序、后序遍历数组 
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
	//corner case 后序遍历为空
	if(postorder.empty()){
		return NULL;
	}
	//初始化哈希表键值对，键为中序遍历元素，值为下标，观察得知这里m只是一个辅助查找手段 
	for(int i=0;i<inorder.size();i++){
		m[inorder[i]]=i;
	}
	//return递归函数
	return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
}
 

//递归函数，传参中序、中序开始结尾下标、后序、后序开始结尾下标
TreeNode* build(vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
	//corner case 开始大于结尾，意为中序后序为空
	if(s0>e0 || s1>e1){
		return NULL;
	}
	//初始化根节点为后序遍历末节点
	TreeNode *root = new TreeNode(postorder[e1]); 
	//初始化两个重要参数
	//一个是mid，记录中间节点下标以便在中序遍历数组中的计算，
	//初始化为哈希表（中序遍历）中，根据后序遍历末尾值（也就是根节点）查找而来的下标 
	int mid=m[postorder[e1]];
	//一个是num，记录二分后单边长度，以便在后序遍历数组中的计算，初始化为中序遍历中的中间下标减去开始下标
	int num=mid-s0;
	//构建root的左右孩子，对根节点的左右孩子递归调用递归函数
	root->left=build(inorder,s0,mid-1,postorder,s1,s1+num-1);//中间的mid是root，要单独拿出来考虑的 
	root->right=build(inorder,mid+1,e0,postorder,s1+num,e1-1);//结尾的e1是root，要单独拿出来考虑的 
	//返回根节点，即返回了建立好的二叉树 	
	return root;
}

 
