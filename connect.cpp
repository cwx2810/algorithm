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

//��һ����ȫ�������ڵ㶼��next�������ӣ�һ��һ�㣬ÿ��������ҵ������� 

void connect(TreeLinkNode *root) {
    //corner case rootΪ�ղ����� 
    if(!root){
    	return;
	}
    //��ʼ����ǰҪ���Ӳ����p 
    TreeLinkNode* p=root;
	//��ʼ����һ������ߵ�һ��������firstΪ�ղ����� 
	TreeLinkNode* first=NULL;
	//��p���е���
	while(p){
		//���first�����ڣ����ʼ����Ϊ��һ��
		if(!first){
			first=p->left;
		}
	
		//��������next��� 
		//���p��������������������nextΪ������
		if(p->left){
			p->left->next=p->right;
		}else{//���������Ҷ�ڵ㣬��ζ�ŵ��������棬����ѭ��
			break;
		}
		
		//��������next���
		//���p��next�򣬼����Աߵ�������˵�����Һ������ʸ������ұ�
		if(p->next){
			//��p���������������� 
			p->right->next=p->next->left;
			//p���ұ��ƽ�
			p=p->next;
			//���µ�p��������
			continue;
		}else{
			//������û��next˵���������ұߣ�ת��first
			//��first�����ÿ�
			p=first;
			first=NULL;
		}
	}
}
 
 







 
