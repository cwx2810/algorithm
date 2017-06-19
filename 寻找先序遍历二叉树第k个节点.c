//求先序遍历二叉树中第k个节点

//初始化标记节点，从1，即节点开始寻找 
int i=1; 
ElemType PreNode(BiTree b,int k){
	//corner case
	if(b==NULL){
		return '#';
	}
	//如果标记达到了k，则找到了
	if(i==k) return b->data;
	//没找到，下一个节点
	i++;
	//在左子树中递归寻找
	ch=PreNode(b->lchild,k);
	//如在左边，返回
	if(ch!='#') return ch;
	//在右子树中递归寻找，这次一定在了，不可能不在
	return PreNode(b->rchild,k); 
}
