//判断二叉树是否相似，动态规划
//相似的意思是都为空，或都只有根节点，或者递归他们的左右子树都相似
int Similar(BiTree T1,BiTree T2){
	//两树皆空
	if(T1==NULL && T2==NULL){
		return 1;
	} else if(T1==NULL || T2==NULL){
		//只有一边为空
		return 0; 
	} else{
		//递归，左左要相似，右右也要相似 
		return Similar(T1->lchild,T2->lchild) && Similar(T1->rchild,T2->rchild); 
	}
} 
