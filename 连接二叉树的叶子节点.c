//将二叉树的叶子节点连成链表
//思想：第一个叶子由head指向，令指针pre指向（记录）他，之后遍历到的叶子节点，用pre的rchild指向，最后一个叶子节点的rchild指向空
//遍历采用中序遍历即可

LinkedList head,pre=NULL;
LinkedList InOrder(BiTree bt){
	//给定树有孩子 
	if(bt){
		//递归中序遍历左子树（若左孩子有孩子） 
		InOrder(bt->lchild);
		//若到达叶节点，进行连接
		if(bt->lchild==NULL&&bt->rchild==NULL){
			//如果是第一个叶子节点，用head指向即可
			if(pre==NULL){
				head=bt;
				//初始化pre 
				pre=bt;
			} else{
				//到了后面的叶子节点，用pre的右孩子指向
				pre->rchild=bt;
				//更新pre
				pre=bt; 
			}
		}
		//递归中序遍历右子树（若右孩子有孩子） 
		InOrder(bt->rchild);
		//最后一个叶子节点置空
		pre->rchild=NULL; 
	}
	return head;
} 
