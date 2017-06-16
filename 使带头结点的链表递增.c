
//使带头结点的链表递增排序 
//想法：只设计一个节点p接在L后面，在这个最初链表里寻找pre点，使得刚好p满足接在pre后面递增，而原来pre的后继也正好大于p
//插入p到这个pre后面 
LinkList Insert(LinkList &L){
	//构造一个只有一个节点的带头结点链表
	LNode *p=L->next;
	LNode *r=p->next;//记录p的后继 
	LNode *pre;
	p->next=NULL;//将p后切断 
	//移动游标p指向切断前的p后继 
	p=r;
	while(p!=NULL){
		//r要跟着移动记录后面的点防止断链
		r=p->next;
		//这时候链表有两个，在第一个带头结点的链表从头结点开始遍历链表寻找p的插入点pre
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
