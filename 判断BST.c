//判断树是否是BST
//对于BST用中序遍历刚好是递增的，如果不是，自然就不是BST

//定义全局变量指向中序遍历节点前驱
KeyType predt=-32767; 
int JudgeBST(BiTree bt){
	//初始化左右子树返回值
	int b1,b2;
	//corner case空树
	if(bt==NULL){
		return 1;
	}else{
		//递归判断左子树
		b1=JudgeBST(bt->lchild);
		//递归条件，前面判断过左子树不是二叉搜索树——所以等于0了，或还没判断过当场判断——前驱比当前大，则不是二叉搜索树 
		if(b1==0 || predt>=bt->data) return 0;
		//更新前驱节点
		predt=bt->data;
		//判断右子树 
		b2=JudgeBST(bt->rchild);
		//要走完整个树才能判断，因此最后返回右子树的返回值即可，左子树如果不符合在前面就返回0了 
		return b2; 
	}
} 
