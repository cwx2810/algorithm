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

//�������ڵ㶼��next�������ӣ�����ȫ������Ҫ������һ��ÿ���б�������һ����last 

void connect(TreeLinkNode *root) {
    //corner case û�и��ڵ�
    if(!root){
    	return;
	}
	//��ʼ����ǰ������p����һ���һ�����ʵ���first����һ�η��ʵ���last
	TreeLinkNode* p=root;
	TreeLinkNode* first=NULL;
	TreeLinkNode* last=NULL;
	//����p����
	while(p){
		//���first������Ϊ�գ�����֮�������������п���
		if(!first){
			if(p->left){
				first=p->left;
			}else if(p->right){
				first=p->right;
			}
		}
		//���������������last������last��nextΪleft������last
		if(p->left){
			if(last){
				last->next=p->left;
			}
			last=p->left;
		}
		//���������������last������last��nextΪright������last
		if(p->right){
			if(last){
				last->next=p->right;
			}
			last=p->right;
		}
		//���p��next��ת��next��û����ת����һ�㣬�ÿ�first��last
		if(p->next){
			p=p->next;
		}else{
			p=first;
			last=NULL;
			first=NULL;
		}
	}
}
 
 







 
