//非递归求二叉树高度
//用层次遍历的方法，记level为高度，last为每层最后一个节点，当每层出队时指针与last相等时，level+1，last指向下一层最右节点
//这题没看太懂，尤其是++rear,++front,last=rear这些 
int Btdepth(BiTree T){
	//corner case
	if(!T) return 0;
	//初始化每层的开头和结尾指针
	int front=-1,rear=-1;
	//初始化level和last
	int level=0,last=0;
	//初始化队列Q
	BiTree Q[MaxSize];
	//根节点入队，先提指针，在入元素 
	Q[++rear]=T;
	//初始化工作指针 
	BiTree p;
	//只要队列不空，迭代
	while(front<rear){
		//初始化p为队列第一个元素，即根节点出队 
		p=Q[++front];
		//p的左右孩子入队
		if(p->lchild) Q[++rear]=p->lchild;
		if(p->rchild) Q[++rear]=p->rchild;
		//当front走到last时
		if(front==last){
			//层数+1 
			level++;
			//last指向下层 
			last=rear;
		} 
	} 
	return level;
} 
