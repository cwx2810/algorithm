//判断是否是完全二叉树
//设置二叉树为满二叉树，空节点用空表示，层次遍历，当遍历到每层的空节点时看后面是否有非空节点，如果有则不是完全二叉树
bool IsComplete(BiTree T){
	//初始化队列，存放二叉树的每一层 
	InitQueue(Q);
	//corner case 空二叉树是完全二叉树
	if(!T) return 1;
	//根节点入队
	EnQueue(Q,T);
	//队列不为空就迭代
	while(!IsEmpty(Q)){
		//取根节点
		DeQueue(Q,p);
		//节点非空（非空就是有左右子树），将其左右子树入队，从这里入队形式可以看出入队后队列里这块都是保存的一层的节点 
		if(p){
			EnQueue(Q,p->lchild);
			EnQueue(Q,p->rchild); 
		} else {
			//节点为空（没有子树），检查其后有么有非空节点
			while(!IsEmpty(Q)){
				DeQueue(Q,p);//队列里离得近的都是保存的一层的，所以这里取的也是同一层的往右一直取 
				if(p){//如果后面竟然出现了有子树的节点，那么肯定不是完全二叉树 
					return 0;
				}
			} 
		}
	}
	return 1; 
} 
