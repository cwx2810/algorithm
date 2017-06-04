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

//��һ�������������(��һ��������)ת����ƽ�������
//�������м���죬ֱ�ӳ������� 

TreeNode* sortedArrayToBST(vector<int>& nums) {
    //���ع����������������飬��ʼ�±�ͽ�β�±� 
    return build(nums,0,nums.size());
}
//������������
TreeNode* build(vector<int>& nums,int start,int end){
	//corner case ��ʼ�±�>=��β�±꣬����Խ���Ϊ��
	if(start>=end){
		return NULL;
	}
	//��ʼ���м��±�
	int mid=(start+end)/2;
	//��ʼ�����ض����������������м�ֵ 
	TreeNode* ret=new TreeNode(nums[mid]);
	//�ݹ��ʼ����������������
	ret->left=build(nums,start,mid);
	ret->right=build(nums,mid+1,end);
	//���ض����� 	
	return ret;
}


 
 







 
