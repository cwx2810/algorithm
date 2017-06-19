//前序遍历和中序遍历构造二叉树
//和LeetCode的思路一样，通过前序遍历第一个值确定根节点，将中序遍历一分为二，再在两边递归
BiTree PreInCreat(ElemType A[],ElemType B[],int s0,int e0,int s1,int e1){//s和e分别是先序和中序的开始结尾下标 
	//初始化
	s0=s1=0;
	e0=e1=n;
	//建立根节点
	root=(BitNode*)malloc(sizeof(BitNode));
	root->data=A[s0];
	//找到根节点在中序序列中的位子
	for(i=s1;B[i]!=root->data;i++);
	//初始化左右子树宽度
	left=i-s1;
	right=e1-i; 
	//递归建立左子树，注意求出的左右子树宽度比实际值小1，因此要注意根节点的位子，合理计算 
	if(left){
		root->lchild=PreInCreat(A,B,s0+1,s0+left,s1,s1+left-1);
	} else{
		root->lchild=NULL;
	}
	//递归建立右子树 
	if(right){
		root->rchild=PreInCreat(A,B,e0-right+1,e0,e1-right+1,e1);
	} else{
		root->rchild=NULL;
	}
	//返回构建完成的树 
	return root;
} 
