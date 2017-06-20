//寻找BST中第k小的节点，给每个节点加一个count域，统计以该节点为根的子树节点个数
//由于BST的左小右大的性质，分情况讨论
//一，简单情况，当没有左子树时，则在右子树寻找 
//二，当有左子树时，要判断节点在左子树还是右子树在寻找 
BSTNode *Search_Small(BSTNode*t,int k){
	//corner case
	if(k<1 || k>t->count) return NULL;
	//如果只有右子树 
	if(t->lchild==NULL){
		if(k==1){
			//极端情况k=1 
			return t;
		}else{
			//往右边递归寻找，最小的已经是根节点了，所以往右只需要找第k-1小了 
			Search_Small(t->rchild,k-1);
		}
	}else{
		//左右子树都有
		//极端情况左边刚好有k-1个节点
		if(t->lchild->count==k-1) return t;
		//正常情况，左边有足够的节点，递归找第k小 
		if(t->lchild->count>k-1) return Search_Small(t->lchild,k); 
		//最麻烦的情况，左边不足k-1个节点，第k小还是在右边，左边包含根节点在内已经有count+1个小的节点了，在右边寻找要减去这些 
		if(t->lchild->count<k-1) return Search_Small(t->rchild,k-(t->lchild->count+1)); 
	}
}
