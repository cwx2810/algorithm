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

//������������������ѹ��������ѹ��������ջ����֤����˳����������
//��ջ�в�ͬ�������Ҷ��ֱ�ӳ�������Ǹ��ڵ���Ҫ�ж����ǲ��ǵ�һ�η��ʣ��������˵�������µ�һ�ߣ�Ҫ����ߵ�����ѹջ���� 

vector<int> postorderTraversal(TreeNode* root) {
    //��ʼ����������
    vector<int> ret;
	//corner case ���ڵ�Ϊ��
	if(root==NULL){
		return ret;
	}
	//��ʼ����������ջ
	vector<TreeNode*> nodes;
	//��ʼ��pre�ڵ�������¼�ǲ��ǵ�һ�η���
	TreeNode* pre=NULL; 
	//�����ڵ�ѹջ
	nodes.push_back(root);
	
	//��ջ��Ϊ�գ������
	while(!nodes.empty()){
		//ȡջ��Ԫ��Ϊp
		TreeNode* p=nodes.back();
		//���p�����߶�Ϊ�գ���ΪҶ�ڵ㣩���� pre��¼���ڵ��Ѿ���Ϊ���ˣ���pre�պõ���p���������������� 
		if((p->left==NULL && p->right==NULL) || (pre!=NULL && (pre==p->left || pre==p->right))){
			//��p��ֵѹ������
			ret.push_back(p->val);
			//����ջ����׼��������һ��ջ�нڵ� 
			nodes.pop_back();
			//p����pre����preΪ��һ�γ�ջ�Ľڵ� 
			pre=p;
		}else{
		//������ˣ����Ǽȷ�Ҷ�ڵ㣬��ͨ��pre����������ڵ�����һ���޹أ�����ѹջ��������������ѹջ�����������½ڵ��������
			if(p->right!=NULL){
				nodes.push_back(p->right);
			}
			if(p->left!=NULL){
				nodes.push_back(p->left);
			}
		}
	}
	//�����귵������ 
	return ret;
}
 
 







 
