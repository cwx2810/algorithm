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

//将二叉树扁平化处理，其实就是前序遍历二叉树然后让他形成右斜姿态
//只不过以前前序遍历是用数组保存并表示、输出，现在直接用树表示 

void flatten(TreeNode* root) {
    //corner case 没有根节点
    if(!root){
    	return;
	}
	//初始化栈ns，通过它完成前序遍历操作
	vector<TreeNode*> ns;
	//初始化挂载树n 
	TreeNode dummy(0);
	TreeNode* n=&dummy;
	//根节点压栈
	ns.push_back(root);
	
	//当栈不为空时，迭代
	while(!ns.empty()){
		//获取栈顶根节点p 
		TreeNode* p=ns.back();
		//弹出栈顶节点 
		ns.pop_back();
		//将栈顶根节点p接到挂载右子树
		n->right=p;
		//挂载指向p节点
		n=p;
		//如果p有右子树，将其压栈，置p右子树为空（其实是置挂载树冗余为空，下一次迭代接着扁平化添加） 
		if(p->right){
			ns.push_back(p->right);
			p->right=NULL;
		}
		//p左子树同上 
		if(p->left){
			ns.push_back(p->left);
			p->left=NULL;
		}
	}
}



 
 







 
