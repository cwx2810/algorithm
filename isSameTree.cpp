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

//�ж��ǲ�������������õݹ�

bool isSameTree(TreeNode* p, TreeNode* q) {
    //corner case ���������ǿ�������Ȼ���
    if(p==NULL && q==NULL){
    	return true;
	}else if(p==NULL || q==NULL){//����ֻ��һ���ǿ����������
		return false;
	}
	//���������ڵ�ֵ��ȣ���ݹ����ǵĶ�Ӧ�����ǲ������
	if(p->val==q->val){
		bool left=isSameTree(p->left,q->left);
		bool right=isSameTree(p->right,q->right);
		return left&&right;
	}
	//�����ǣ�����false 
	return false;
}






 
