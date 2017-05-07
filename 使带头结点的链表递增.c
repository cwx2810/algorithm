
//使带头结点的链表递增
//想法：只设计一个节点接在L后面，寻找pre点，使得这个pre满足小于p而他的下一个元素又大于p，插入p到这个pre后面 
LinkList Insert(LinkList &L){
	//构造一个只有一个节点的带头结点链表
	LNode *p=L->next;
	LNode *r=p->next;
	LNode *pre;
	P->next=NULL;
	//移动游标p寻找下一个猎物 
	p=r;
	while(p!=NULL){
		//r要跟着移动记录后面的点防止断链
		r=p->next;
		//从头结点开始遍历链表寻找p的插入点pre
		pre=L;
		while(pre->next!=NULL && pre->next->data<p->data){
			pre=pre->next;
		} 
		//插入p到pre之后
		p->next=pre->next;
		pre->next=p;
		//移动游标p寻找下一个猎物
		p=r; 
	} 
}
