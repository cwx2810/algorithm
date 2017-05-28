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

//�ж��ǲ���ƽ�����������DFS�ж�ÿ�������ĸ߶� 

bool isBalanced(TreeNode* root) {
    //corner case ���ڵ�Ϊ����ƽ������� 
    if(root==NULL){
    	return true;
	}
    //��ʼ�����Ƿ�ƽ�⡱Ϊ��ȡ���ĸ߶Ⱥ���
    int isBalanced=getHeight(root);
	//��ǲ����������ĸ߶Ȳ�Ϊ-1��������-1����ƽ�����������֮���� 
	if(isBalanced != -1){
		return true;
	}else{
		return false;
	}
}
//����int���͵Ļ�ȡ���ĸ߶Ⱥ���
int getHeight(TreeNode* root){
	//corner case ���ڵ�Ϊ�գ�����0
	if(root==NULL){
		return 0;
	}
	/*�߼���߶ȱ߼����ֵ*/
	//��ʼ���������ݹ�߶Ⱥ��������Ϊ-1�򷵻�-1
	int leftHeight=getHeight(root->left);
	if(leftHeight == -1){
		return -1;
	}
	//��ʼ���������ݹ�߶Ⱥ��������Ϊ-1�򷵻�-1
	int rightHeight=getHeight(root->right);
	if(rightHeight == -1){
		return -1;
	}
	//��ÿ���ڵ㶼�����������߶ȳ�ʼ���߶Ȳ�ı߸�����߼���һ�����߶�
	int diffHeight=leftHeight>rightHeight?leftHeight-rightHeight:rightHeight-leftHeight;
	if(diffHeight>1){//����߶Ȳ����1������-1
		return -1;
	}
	//���򣨸߶Ȳ���1����0�����ݹ���һ���ٴμ���߶Ȳ� 
	else{
		return diffHeight=(leftHeight>rightHeight?leftHeight:rightHeight)+1;//�͵��ı�û�к����ˣ����ԴӸߵ��Ǳ����¼����� 
	} 	
}







 
