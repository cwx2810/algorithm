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

//�����������������������ά���飬����һ��Ԫ�ؾ���һ�㣬ֻ�������Ԫ�أ��㣩�Ƿ���� 
//˼·���Ƚ�����ά���飬��С��DFS����������Ⱦ�������DFSÿһ���Ԫ�� 
vector<vector<int> > levelOrderBottom(TreeNode* root) {
    //��ʼ�����
    int depth=getHeight(root);
    //������ȳ�ʼ����ά���� 
    vector<vector<int> > ret(depth);
	//corner case���Ϊ0
	if(depth==0){
		return ret;
	}
	//����DFSѹջ������ֻ��������Ǵ����һ�㿪ʼѹ
	getSolution(ret,root,ret.size()-1);
	//���ض�ά���� 
	return ret;
}
//����DFSѹջ����
void getSolution(vector<vector<int> > &ret,TreeNode* root, int level){
	//corner case������ڵ�Ϊ��
	if(root==NULL){
		return;
	}
	//ѹջ���ڵ�Ԫ��ֵ
	ret[level].push_back(root->val);
	//�Ը��ڵ��������ݹ�ѹջ
	getSolution(ret,root->left,level-1);
	//���������ݹ�ѹջ
	getSolution(ret,root->right,level-1);
}
//������ȡ��Ⱥ���
int getHeight(TreeNode* root){
	//corner case������ڵ�Ϊ��
	if(root==NULL){
		return 0;
	}
	//�ݹ��ʼ��������
	int left=getHeight(root->left);
	//�ݹ��ʼ���Ҳ����
	int right=getHeight(root->right);
	//�ı߸߾Ͱ�height�����ıߣ�ÿ�εݹ����+1
	int height=(left>right?left:right)+1;
	//����height 
	return height;
}



 
