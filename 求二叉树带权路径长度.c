//计算二叉树带权路径长度 
//采用先序遍历思想递归，若达到叶节点，则累加路径权之积的和，若没到叶节点，对左右子树调用递归，深度加一
int WPL(BiTree root){
	return wpl_preOrder(root,0);
} 
int wpl_preOrder(BiTree root,int deep){
	//初始化带权路径
	static int wpl=0;
	//若为叶节点，累计wpl
	if(root->lchild==NULL && root->rchild==NULL) wpl+=deep*root->weight;//深度 X 权值 
	//左子树不为空，对左子树遍历，深度加一 
	if(root->lchild!=NULL) wpl_preOrder(root->lchild,deep+1);
	//右子树不为空，对右子树遍历，深度加一 
	if(root->rchild!=NULL) wpl_preOrder(root->rchild,deep+1);
	//返回带权路径长度
	return wpl; 
}
