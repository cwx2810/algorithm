#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

//将一个已排序的数组(上一次是链表)转换成平衡二叉树
//数组找中间更快，直接除二便是 

TreeNode* sortedArrayToBST(vector<int>& nums) {
    //返回构建函数，传入数组，起始下标和结尾下标 
    return build(nums,0,nums.size());
}
//建立构建函数
TreeNode* build(vector<int>& nums,int start,int end){
	//corner case 起始下标>=结尾下标，数组越界或为空
	if(start>=end){
		return NULL;
	}
	//初始化中间下标
	int mid=(start+end)/2;
	//初始化返回二叉树，传入数组中间值 
	TreeNode* ret=new TreeNode(nums[mid]);
	//递归初始化左子树和右子树
	ret->left=build(nums,start,mid);
	ret->right=build(nums,mid+1,end);
	//返回二叉树 	
	return ret;
}


 
 







 
