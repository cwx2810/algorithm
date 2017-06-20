//在BST中查找指定节点层次
//一个迭代查找就是一层，设置计数器n，没查找一轮n+1，直到查到为止，返回n即可
int level(BiTree bt,BSTNode *p){
	//初始化查找次数计数器
	int n=0;
	//初始化树
	BiTree t=bt;
	//只要树不为空，初始化n为1层，从1开始查找
	if(bt!=NULL){
		n++;
		//没找到，就判断并在左右子树查找
		while(t->data!=p->data){
			if(t->data<p->data){
				t=t->rchild;
			}else{
				t=t->lchild;
			}
			//进入孩子了，层数自然要加一 
			n++;
		} 
	} 
	//返回最终层数
	return n; 
}
