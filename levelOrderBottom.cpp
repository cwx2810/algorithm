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

//层序遍历二叉树，将其存入二维数组，数组一个元素就是一层，只不过这次元素（层）是反向的 
//思路，先建立二维数组，大小由DFS查找树的深度决定，再DFS每一层的元素 
vector<vector<int> > levelOrderBottom(TreeNode* root) {
    //初始化深度
    int depth=getHeight(root);
    //根据深度初始化二维数组 
    vector<vector<int> > ret(depth);
	//corner case深度为0
	if(depth==0){
		return ret;
	}
	//调用DFS压栈函数，只不过这次是从最后一层开始压
	getSolution(ret,root,ret.size()-1);
	//返回二维数组 
	return ret;
}
//构建DFS压栈函数
void getSolution(vector<vector<int> > &ret,TreeNode* root, int level){
	//corner case如果根节点为空
	if(root==NULL){
		return;
	}
	//压栈根节点元素值
	ret[level].push_back(root->val);
	//对根节点左子树递归压栈
	getSolution(ret,root->left,level-1);
	//对右子树递归压栈
	getSolution(ret,root->right,level-1);
}
//构建获取深度函数
int getHeight(TreeNode* root){
	//corner case如果根节点为空
	if(root==NULL){
		return 0;
	}
	//递归初始化左侧深度
	int left=getHeight(root->left);
	//递归初始化右侧深度
	int right=getHeight(root->right);
	//哪边高就把height赋给哪边，每次递归层深+1
	int height=(left>right?left:right)+1;
	//返回height 
	return height;
}



 
