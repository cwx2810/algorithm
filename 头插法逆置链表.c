
//头插法翻转链表
LinkList Reverse_1(LinkList &L){
	LNode *p=L->next;//p记录第一个节点 
	LNode *r;
	L->next=NULL;//从头结点开始切断 
	while(p!=NULL){
		r=p->next;//r记录p之后的节点 
		//头插操作，插在L后面 
		p->next=L->next;
		L->next=p;
		p=r;//移动游标p到下一个节点 
	}
	return L;
} 

