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

//������ͺ���������������
//˼·���ú������ĩβԪ�صõ����ڵ㣬
//������������ҵ��˽ڵ㲢���Ϊ�������ߣ�����Ԫ��Ϊ���������Ҳ��Ϊ������
//�����������ȥĩ�ڵ��һ��Ϊ����Ԫ�غ��������һһ��Ӧ�������ߵݹ���У�����ĩ�ڵ㣬���

//��ʼ����ϣ�����ڲ�������������м�ڵ�
unordered_map<int,int> m;
//�ܽ��캯�����������򡢺���������� 
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
	//corner case �������Ϊ��
	if(postorder.empty()){
		return NULL;
	}
	//��ʼ����ϣ���ֵ�ԣ���Ϊ�������Ԫ�أ�ֵΪ�±꣬�۲��֪����mֻ��һ�����������ֶ� 
	for(int i=0;i<inorder.size();i++){
		m[inorder[i]]=i;
	}
	//return�ݹ麯��
	return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
}
 

//�ݹ麯����������������ʼ��β�±ꡢ���򡢺���ʼ��β�±�
TreeNode* build(vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
	//corner case ��ʼ���ڽ�β����Ϊ�������Ϊ��
	if(s0>e0 || s1>e1){
		return NULL;
	}
	//��ʼ�����ڵ�Ϊ�������ĩ�ڵ�
	TreeNode *root = new TreeNode(postorder[e1]); 
	//��ʼ��������Ҫ����
	//һ����mid����¼�м�ڵ��±��Ա���������������еļ��㣬
	//��ʼ��Ϊ��ϣ������������У����ݺ������ĩβֵ��Ҳ���Ǹ��ڵ㣩���Ҷ������±� 
	int mid=m[postorder[e1]];
	//һ����num����¼���ֺ󵥱߳��ȣ��Ա��ں�����������еļ��㣬��ʼ��Ϊ��������е��м��±��ȥ��ʼ�±�
	int num=mid-s0;
	//����root�����Һ��ӣ��Ը��ڵ�����Һ��ӵݹ���õݹ麯��
	root->left=build(inorder,s0,mid-1,postorder,s1,s1+num-1);//�м��mid��root��Ҫ�����ó������ǵ� 
	root->right=build(inorder,mid+1,e0,postorder,s1+num,e1-1);//��β��e1��root��Ҫ�����ó������ǵ� 
	//���ظ��ڵ㣬�������˽����õĶ����� 	
	return root;
}

 
