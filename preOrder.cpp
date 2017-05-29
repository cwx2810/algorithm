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

//������ǰ�������ʹ�õ�������stack���������� 

vector<int> preorderTraversal(TreeNode* root) {
    //��ʼ���������� 
    vector<int> ret;
	//corner case ���ڵ�Ϊ�գ�ֱ�ӷ��ؿ�����
	if(root==NULL){
		return ret;
	}
	//��ʼ��stack������
	vector<TreeNode*> nodes;
	//���ڵ�ѹ��stack
	nodes.push_back(root);
	//��stack��Ϊ��ʱ������ 
	while(!nodes.empty()){
		//ȡջ�����ڵ㽫��ֵѹ������
		TreeNode* n=nodes.back();
		ret.push_back(n->val);
		//����ջ�����ڵ�
		nodes.pop_back();
		//����ýڵ�������������ѹջ���棬ѭ����������������
		if(n->right){//ǰ��������ȷ���������û������Ҫ��ѹջ�����������������պ�������ѹջ���Ȳ���������������������� 
			nodes.push_back(n->right);
		}
		//ͬ����ѭ������������ 
		if(n->left){
			nodes.push_back(n->left);
		}
	}
	//����ѭ������������
	return ret;
}
 
 







 
