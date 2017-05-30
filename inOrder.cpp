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

//���������������ʹ�õ�������stack����������ߵĸ��ڵ�(��ʵ���Ǳ�����ڵ�)���Ա��ڵõ������� 

vector<int> inorderTraversal(TreeNode* root) {
    //��ʼ������ 
    vector<int> ret;
    //corner case���ڵ�Ϊ��
    if(root==NULL){
    	return ret;
	}
	//��ʼ����������stack
	vector<TreeNode*> nodes;
	//��ʼ�����ڵ�p 
	TreeNode* p=root;
	//p���ڻ���stack��Ϊ�գ�����
	while(p || !nodes.empty()){
		//һֱ�����������������ڵ�ѹ��stack
		while(p){
			nodes.push_back(p);
			p=p->left;
		}
		//���stack��Ϊ�գ���ʼ��p��ȡstack�ڵ㣨�����ڵ㣩������ֵѹ������
		if(!nodes.empty()){
			p=nodes.back();
			ret.push_back(p->val);//�����ڽ����ѹ������Ĺ�����Ҳ�����˸��ڵ㣬���õ��� 
			//�����ڵ㣬��ʼ��pΪ����������ȡ������������ѹ������
			nodes.pop_back();
			p=p->right;
		}	
	}
	//����ret 
	return ret;
}
 
 







 
