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

//将一个已排序的链表转换成平衡二叉树
//思路，找到中间节点即根节点，两边就是左右子树，在左右子树中继续找中间节点
//如何找到中间节点？设置fast和slow指针，fast每次走两步，slow每次走一步，这样fast走到头，slow就走到了中间 

TreeNode* sortedListToBST(ListNode* head) {
    //返回build函数，传入链表头和尾 
    return build(head,NULL);
}
//构建build函数
TreeNode* build(ListNode* start,ListNode* end){
	//corner case 头等于尾
	if(start==end){
		return NULL;
	}
	//初始化fast和slow都为头
	ListNode* fast=start;
	ListNode* slow=start;
	
	//迭代，当fast还能移动时，也即fast不是尾，fast后面一位也不是尾
	while(fast!=end && fast->next!=end){
		//slow走一步，fast走两步
		slow=slow->next;
		fast=fast->next->next;
	}
	
	//初始化二叉树，传入slow的值
	TreeNode* ret=new TreeNode(slow->val);
	//对二叉树的左右子树进行递归build
	ret->left=build(start,slow);
	ret->right=build(slow->next,end);
	//返回二叉树 
	return ret;
}

 
 







 
