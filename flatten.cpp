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

//����������ƽ��������ʵ����ǰ�����������Ȼ�������γ���б��̬
//ֻ������ǰǰ������������鱣�沢��ʾ�����������ֱ��������ʾ 

void flatten(TreeNode* root) {
    //corner case û�и��ڵ�
    if(!root){
    	return;
	}
	//��ʼ��ջns��ͨ�������ǰ���������
	vector<TreeNode*> ns;
	//��ʼ��������n 
	TreeNode dummy(0);
	TreeNode* n=&dummy;
	//���ڵ�ѹջ
	ns.push_back(root);
	
	//��ջ��Ϊ��ʱ������
	while(!ns.empty()){
		//��ȡջ�����ڵ�p 
		TreeNode* p=ns.back();
		//����ջ���ڵ� 
		ns.pop_back();
		//��ջ�����ڵ�p�ӵ�����������
		n->right=p;
		//����ָ��p�ڵ�
		n=p;
		//���p��������������ѹջ����p������Ϊ�գ���ʵ���ù���������Ϊ�գ���һ�ε������ű�ƽ����ӣ� 
		if(p->right){
			ns.push_back(p->right);
			p->right=NULL;
		}
		//p������ͬ�� 
		if(p->left){
			ns.push_back(p->left);
			p->left=NULL;
		}
	}
}



 
 







 
