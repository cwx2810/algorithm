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



//��������������� 
//�������������ݹ���level 

//����ȫ�ַ���ֵ 
int num;
int maxDepth(TreeNode* root) {
    //corner case���ڵ㲻����
    if(!root){
    	return 0;
	}
	//��ʼ��numΪ��Сֵ
	num=numeric_limits<int>::min();
	//����travel�������Ӹ��ڵ㿪ʼ�ݹ�
	travel(root,1);
	//����num 
	return num;
}
//travel����
void travel(TreeNode *node,int level){
	//���û���������������Ǹ��ڵ㣬����num
	if(!node->left && !node->right){
		num=max(num,level);
		return;
	}
	//�����������������ݹ� 
	if(node->left){
		travel(node->left,level+1);
	}
	if(node->right){
		travel(node->right,level+1);
	}
}

