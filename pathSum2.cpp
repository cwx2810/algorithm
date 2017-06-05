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

//�ж϶�������ĳ�����ڵ�-Ҷ�ӽڵ�·��Ϊ����sum 

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    //��ʼ�����صĶ�ά����
    vector<vector<int> > ret;
	//corner case ����Ϊ����
	if(root==NULL){
		return ret;
	}
	//��ʼ��һά��ʱ���飨������������һά����ĺͣ�������ֻ��ѡ���㡰����Ŀ�������͡��ﵽҶ�ڵ㡱˫�ر�׼�����飩 
	vector<int> curr;
	// DFS�������ά���飬һά���飬Ŀ��������ʱ�ͣ����ڵ� 
	DFS(ret,curr,sum,0,root);
	//���ض�ά���� 
	return ret;
}
//����DFS
void DFS(vector<vector<int> >& ret,vector<int> curr,int sum,int tmpsum,TreeNode* root){
	//corner case ����Ϊ����
	if(root==NULL){
		return;
	}
	//��ʼ����ʱ����ÿ����ڵ�ֵ���
	tmpsum+=root->val;
	//��ÿ����ڵ�ֵѹ����ʱһά����
	curr.push_back(root->val);
	
	//�ж���������������ѹ�뷵�ض�ά���� 
	if(sum==tmpsum){
		if(root->left==NULL && root->right==NULL){
			//�����ʱ�͵���Ŀ����
			//������ڵ�����������Ϊ�գ�����Ҷ�ڵ�
			//ѹһά�������ά���飬����
			ret.push_back(curr);
			return;
		}
	}
	//�ݹ�DFS�������� 
	DFS(ret,curr,sum,tmpsum,root->left);
	DFS(ret,curr,sum,tmpsum,root->right);
}



 
 







 
