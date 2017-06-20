//判断二叉树是否为平衡二叉树
//用递归，先考虑边界条件有0个节点和1个节点的树，而后递归遍历左右子树判断左右相减的绝对值要小于2
void Judge_AVL(BiTree bt,int &balance,int &h){
	//初始化左右子树平衡变量以及左右子树高度
	int balanceL,balanceR,heightL,heightR;
	//空树和仅有一个节点
	if(bt==NULL){
		h=0;
		balance=1;
	} else if(bt->lchild==NULL && bt->rchild==NULL){
		h=1;
		balance=1;
	} else {
		//递归左右子树是否平衡
		Judge_AVL(bt->lchild,balanceL,heightL);
		Judge_AVL(bt->rchild,balanceR,heightR);
		//更新深度，计算本层满足平衡了，递归下一层计算高度差 
		h=(heightL>heightR?heightL:heightR)+1;
		//高度差的绝对值不能大于1
		if(abs(heightL,heightR)<2){
			//递归左右子树都平衡时总平衡
			balance=balanceL&&balanceR; 
		} else{
			//有一边不平衡，则不平衡 
			balance=0;
		}
	}
} 
