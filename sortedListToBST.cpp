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

//��һ�������������ת����ƽ�������
//˼·���ҵ��м�ڵ㼴���ڵ㣬���߾������������������������м������м�ڵ�
//����ҵ��м�ڵ㣿����fast��slowָ�룬fastÿ����������slowÿ����һ��������fast�ߵ�ͷ��slow���ߵ����м� 

TreeNode* sortedListToBST(ListNode* head) {
    //����build��������������ͷ��β 
    return build(head,NULL);
}
//����build����
TreeNode* build(ListNode* start,ListNode* end){
	//corner case ͷ����β
	if(start==end){
		return NULL;
	}
	//��ʼ��fast��slow��Ϊͷ
	ListNode* fast=start;
	ListNode* slow=start;
	
	//��������fast�����ƶ�ʱ��Ҳ��fast����β��fast����һλҲ����β
	while(fast!=end && fast->next!=end){
		//slow��һ����fast������
		slow=slow->next;
		fast=fast->next->next;
	}
	
	//��ʼ��������������slow��ֵ
	TreeNode* ret=new TreeNode(slow->val);
	//�Զ������������������еݹ�build
	ret->left=build(start,slow);
	ret->right=build(slow->next,end);
	//���ض����� 
	return ret;
}

 
 







 
