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

//把二叉树每条路径的所有元素转换成一个数字，输出所有路径数字的和 

int sumNumbers(TreeNode* root) {
        //初始化栈
        vector<int> arr;
    	//初始化sum
    	int sum=0;
    	//调用dfs，传入根节点，栈，sum
    	DFS(root,arr,sum);
    	//返回sum 
    	return sum;
    }
    //构建栈元素转sum函数
    int vec2sum(vector<int>& arr){
    	//初始化临时num
    	int num=0;
    	//遍历栈中所有元素，每次sum十倍加下一个
    	for(auto n : arr) {
    		num=num*10+n;
    	}
    	//返回最终数	
    	return num;
    }
//构建dfs
void DFS(TreeNode* root,vector<int>& arr,int& sum){
	//corner case 根节点为空
	if(root==nullptr){
		return;
	}
	//根节点压栈
	arr.push_back(root->val);
	//到达叶子节点，用数组转换数字计算一路上的sum
	if(root->left==nullptr && root->right==nullptr){
		sum+=vec2sum(arr);
	}else{
		//反之没到叶子节点，左右子树递归dfs
		if(root->left!=nullptr){
			DFS(root->left,arr,sum);
		}
		if(root->right!=nullptr){
			DFS(root->right,arr,sum);
		}
	}
	//弹出栈顶
	arr.pop_back();
}
