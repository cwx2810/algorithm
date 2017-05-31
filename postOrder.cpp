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

//二叉树后续遍历，先压右子树再压左子树入栈，保证访问顺序是左右中
//出栈有不同，如果是叶子直接出，如果是根节点则要判断其是不是第一次访问，如果是则说明到了新的一边，要把这边的子树压栈访问 

vector<int> postorderTraversal(TreeNode* root) {
    //初始化返回数组
    vector<int> ret;
	//corner case 根节点为空
	if(root==NULL){
		return ret;
	}
	//初始化保存树的栈
	vector<TreeNode*> nodes;
	//初始化pre节点用来记录是不是第一次访问
	TreeNode* pre=NULL; 
	//将根节点压栈
	nodes.push_back(root);
	
	//若栈不为空，则迭代
	while(!nodes.empty()){
		//取栈顶元素为p
		TreeNode* p=nodes.back();
		//如果p的两边都为空（即为叶节点）或者 pre记录过节点已经不为空了，且pre刚好等于p的左子树或右子树 
		if((p->left==NULL && p->right==NULL) || (pre!=NULL && (pre==p->left || pre==p->right))){
			//将p的值压入数组
			ret.push_back(p->val);
			//弹出栈顶，准备访问下一个栈中节点 
			nodes.pop_back();
			//p赋给pre，记pre为上一次出栈的节点 
			pre=p;
		}else{
		//若非如此，就是既非叶节点，又通过pre发现了这个节点与上一个无关，则先压栈他的右子树，再压栈左子树，按新节点迭代访问
			if(p->right!=NULL){
				nodes.push_back(p->right);
			}
			if(p->left!=NULL){
				nodes.push_back(p->left);
			}
		}
	}
	//迭代完返回数组 
	return ret;
}
 
 







 
