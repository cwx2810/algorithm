//找出链表倒数第k个节点 
//设置两个指针pq，开始都指向第一个节点，先让p移动到第k个位子，然后pq同时移动，此时pq间的差距就是k，当p走到头时q就指向了倒数第k 
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *link;
}LNode,LinkList;
int Search_k(LinkList L,int k){
	//初始化指针
	LNode *p=L->next,*q=L->next;
	//初始化计数器
	int count=0;
	//迭代到p走到头
	while(p!=NULL){
		//如果count<k，只移动p
		if(count<k){
			count++;
		} else{//如果count=k了，则同时移动 
			q=q->next;
		}
		p=p->next;
	} 
	//走到最后count还小于k，corner case
	if(count<k){
		return 0;
	} else{//否则查找成功 
		printf("%d",q->data);
		return 1;
	}
}
