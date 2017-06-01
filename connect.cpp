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

//对一个完全二叉树节点都用next横向连接，一层一层，每层从左至右迭代连接 

void connect(TreeLinkNode *root) {
    //corner case root为空不存在 
    if(!root){
    	return;
	}
    //初始化当前要连接层的树p 
    TreeLinkNode* p=root;
	//初始化下一层最左边第一个左子树first为空不存在 
	TreeLinkNode* first=NULL;
	//对p进行迭代
	while(p){
		//如果first不存在，则初始化它为下一层
		if(!first){
			first=p->left;
		}
	
		//左子树的next情况 
		//如果p有左子树，则左子树的next为右子树
		if(p->left){
			p->left->next=p->right;
		}else{//否则，其必是叶节点，意味着到了最下面，跳出循环
			break;
		}
		
		//右子树的next情况
		//如果p有next域，即有旁边的树，则说明其右孩子有资格连接右边
		if(p->next){
			//对p的右子树进行连接 
			p->right->next=p->next->left;
			//p往右边推进
			p=p->next;
			//对新的p继续迭代
			continue;
		}else{
			//否则，其没有next说明到了最右边，转到first
			//对first重新置空
			p=first;
			first=NULL;
		}
	}
}
 
 







 
