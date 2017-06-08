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

//二叉搜索树的某两个节点被交换了，要求找到并恢复
//思路，二叉搜索树按中序遍历输出是递增的，因此两两比较找到违背的交换即可
//要求空间复杂度，不能用栈，要用Morris的方式中序遍历
//大意是如果没有左子树好办，直接挨着挨着往右输出
//如果有左子树，就把他旋转成右子树（连接前驱和当前节点）输出，然后再切断连接，输出中间的，再输出右子树，还有这种操作？ 

void recoverTree(TreeNode* root) {
    //初始化一堆变量
	//当前
	TreeNode* cur=0;
	//前驱
	TreeNode* pre=0;
	//记录交换节点
	TreeNode* p1=0;
	TreeNode* p2=0;
	//记录临时前驱
	TreeNode* preCur=0;
	//记录是否找到需要交换的
	bool found=false; 
	
	//corner case根节点不存在
	if(!root){
		return;
	}
	//初始化当前节点为根节点
	cur=root;
	
	//当前节点存在，进入迭代
	while(cur){
		//如果没有左子树，记录p1和p2，同时向右移动当前节点 
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
		}else{//否则有左子树
			//找到当前节点的前驱，即左子树最右边的节点 
			pre=cur->left;
			while(pre->right && pre->right!=cur){
				pre=pre->right;
			}
			//如果前驱没有右子树，则连到当前节点上，当前节点继续向左子树跳，直到跳到头没有左子树
			//（这时候程序其实回溯到了上面当前节点没有左子树的情况，把左子树当成右子树遍历一趟，也就是旋转）
			if(!pre->right){
				pre->right=cur;
				cur=cur->left;
			}else{
			//然后走到每个根节点，回到这里，达到否则（前驱有右子树（当前节点））条件，记录p1p2，切断前驱的右手，同时向右移动当前节点
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
	//交换p1p2
	if(p1 && p2){
		int t=p1->val;
		p1->val=p2->val;
		p2->val=t;
	} 
}
 



 
 







 
