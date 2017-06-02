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

//二叉树节点都用next横向连接，比完全二叉树要多设置一个每层中遍历的上一个树last 

void connect(TreeLinkNode *root) {
    //corner case 没有根节点
    if(!root){
    	return;
	}
	//初始化当前遍历树p，下一层第一个访问的树first，上一次访问的树last
	TreeLinkNode* p=root;
	TreeLinkNode* first=NULL;
	TreeLinkNode* last=NULL;
	//进入p迭代
	while(p){
		//如果first不存在为空，设置之，左右子树都有可能
		if(!first){
			if(p->left){
				first=p->left;
			}else if(p->right){
				first=p->right;
			}
		}
		//如果有左子树，有last则设置last的next为left，重设last
		if(p->left){
			if(last){
				last->next=p->left;
			}
			last=p->left;
		}
		//如果有右子树，有last则设置last的next为right，重设last
		if(p->right){
			if(last){
				last->next=p->right;
			}
			last=p->right;
		}
		//如果p有next，转到next，没有则转到下一层，置空first和last
		if(p->next){
			p=p->next;
		}else{
			p=first;
			last=NULL;
			first=NULL;
		}
	}
}
 
 







 
