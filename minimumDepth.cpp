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



//��������ĺ��ӵ���С��� 
//�������������ݹ���level 

//����ȫ�ַ������ 
int num;
int minDepth(TreeNode* root){
	//corner case
	if(!root){
		return 0;
	}
	//��ʼ�����Ϊ���
	num=numeric_limits<int>::max();
	//����travel��������������ȣ����ϸı�num 
	travel(root,1);
	//���� 
	return num;
}
//travel����
void travel(TreeNode *node,int level){
	//û�����Һ��ӣ����Ѿ�����ĳ�����ӣ�����Сֵ
	if(!node->left && !node->right){
		num=min(num,level);
		return;
	}
	//�к��ӣ���ݹ��㺢�ӵ���Сֵ
	if(node->left){
		travel(node->left,level+1);
	} 
	if(node->right){
		travel(node->right,level+1);
	}
} 
