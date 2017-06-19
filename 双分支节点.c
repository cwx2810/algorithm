//求二叉树的所有双分支节点个数
//动态规划，corner case是节点没有儿子，方程分两种情况：
//一种确实是双分支，当前节点的个数是两个孩子双分支节点个数再加自己的1
//一种是单分支，当前节点个数是左孩子双分支个数或右孩子双分支个数，没有自己的1
int DSonNodes(BiTree b){
	//corner case
	if (b==NULL){
		return 0;
	}else if(b->lchild!=NULL && b->rchild!=NULL){
		//有双分支 
		return DSonNodes(b->lchild)+DSonNodes(b->rchild)+1;
	}else{
		//只有单分支 
		return DSonNodes(b->lchild)+DSonNodes(b->rchild);
	}
} 
