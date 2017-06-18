//连接两个带头结点的循环单链表，使连接后还是循环单链表
//找到a的尾指针，把b的头指针接到后面
LinkList Link(LinkList &A,LinkList &B){
	//初始化工作指针
	LNode *p,*q; 
	//寻找AB的尾节点
	p=A;
	while(p->next!A){
		p=p->next;
	} 
	q=B;
	while(q->next!B){
		q=q->next;
	}
	//将B接到A后面
	p->next=B;
	//将A的头接到B后面组成循环链表 
	q->next=A; 
	//返回
	return A; 
} 
