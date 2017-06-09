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

//������������дӸ��ڵ㵽Ҷ�ӽڵ��·������DFS�����������ʽ�е㷳�� 

vector<string> binaryTreePaths(TreeNode* root) {
    //��ʼ����������
    vector<string> ret;
	//corner case���ڵ�Ϊ��
	if(root==nullptr) return ret;
	//��ʼ��path����
	vector<int> path;
	//����DFS��������ڵ㣬path����������
	dfs(root,path,ret);
	//���ط������� 
	return ret;
}
//����DFS
void dfs(TreeNode* root,vector<int>& path,vector<string>& ret){
	//corner case���ڵ�Ϊ��
	if(root==nullptr) return;
	//pathѹջ���ڵ��ֵ
	path.push_back(root->val);
	//�������Ҷ�ӽڵ㣬����ת������ѹջ��������
	if(root->left==nullptr && root->right==nullptr){
		ret.push_back(generatePath(path));
	} else{
		//û��Ҷ�ӽڵ㣬�ݹ�����������ע��ߵݹ�ߵ������ڻ���
		if(root->left!=nullptr){
			dfs(root->left,path,ret);
			path.pop_back();
		}
		if(root->right!=nullptr){
			dfs(root->right,path,ret);
			path.pop_back();
		}
	}
}
//����ת��������ת�����Ϊ�ַ���
string generatePath(vector<int> path){
	//��ʼ���ַ���
	stringstream ss;
	//����·������path
	int i;
	for(i=0;i<path.size()-1;i++) ss<<path[i]<<"->";
	//������һ��
	ss<<path[i];
	//�����ַ���
	return ss.str();	
}
 
 
 



 
 







 
