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

//������������ĳ�����ڵ㱻�����ˣ�Ҫ���ҵ����ָ�
//˼·�������������������������ǵ����ģ���������Ƚ��ҵ�Υ���Ľ�������
//Ҫ��ռ临�Ӷȣ�������ջ��Ҫ��Morris�ķ�ʽ�������
//���������û���������ð죬ֱ�Ӱ��Ű����������
//��������������Ͱ�����ת��������������ǰ���͵�ǰ�ڵ㣩�����Ȼ�����ж����ӣ�����м�ģ���������������������ֲ����� 

void recoverTree(TreeNode* root) {
    //��ʼ��һ�ѱ���
	//��ǰ
	TreeNode* cur=0;
	//ǰ��
	TreeNode* pre=0;
	//��¼�����ڵ�
	TreeNode* p1=0;
	TreeNode* p2=0;
	//��¼��ʱǰ��
	TreeNode* preCur=0;
	//��¼�Ƿ��ҵ���Ҫ������
	bool found=false; 
	
	//corner case���ڵ㲻����
	if(!root){
		return;
	}
	//��ʼ����ǰ�ڵ�Ϊ���ڵ�
	cur=root;
	
	//��ǰ�ڵ���ڣ��������
	while(cur){
		//���û������������¼p1��p2��ͬʱ�����ƶ���ǰ�ڵ� 
		if(!cur->left){
			if(preCur && preCur->val>cur->val){
				if(!found){
					p1=preCur;
					found=true;
				}
				p2=cur;
			}
			preCur=cur;
			cur=cur->right;
		}else{//������������
			//�ҵ���ǰ�ڵ��ǰ���������������ұߵĽڵ� 
			pre=cur->left;
			while(pre->right && pre->right!=cur){
				pre=pre->right;
			}
			//���ǰ��û������������������ǰ�ڵ��ϣ���ǰ�ڵ����������������ֱ������ͷû��������
			//����ʱ�������ʵ���ݵ������浱ǰ�ڵ�û�������������������������������������һ�ˣ�Ҳ������ת��
			if(!pre->right){
				pre->right=cur;
				cur=cur->left;
			}else{
			//Ȼ���ߵ�ÿ�����ڵ㣬�ص�����ﵽ����ǰ��������������ǰ�ڵ㣩����������¼p1p2���ж�ǰ�������֣�ͬʱ�����ƶ���ǰ�ڵ�
				if(preCur->val>cur->val){
					if(!found){
						p1=preCur;
						found=true;
					}
					p2=cur;
				}
				preCur=cur;
				pre->right=NULL;
				cur=cur->right;
			}
		}
	}
	//����p1p2
	if(p1 && p2){
		int t=p1->val;
		p1->val=p2->val;
		p2->val=t;
	} 
}
 



 
 







 
