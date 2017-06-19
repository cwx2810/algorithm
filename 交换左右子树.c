//交换二叉树左右子树
//采用后序遍历的思想，先交换左子树的左右孩子，在交换右子树的左右孩子，最后交换整个左右子树
void swap(BiTree b){
	//迭代到节点为空为止
	if(b){
		//递归交换左右子树
		swap(b->lchild);
		swap(b->rchild);
		//交换节点过程 
		temp=b->lchild;
		b->lchild=b->rchild;
		b->rchild=temp; 
	} 
} 
