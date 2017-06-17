//生成两个带头结点的递增的单链表的公共节点为新链表 
//和寻找两个链表公共元素不同的是，这次链表是递增，当两两比较不等时，只需移动小的值的节点
//若相等，则创建值相等的新节点尾插法建链表，两个指针同时后移，直到一个链表结束
void Get_Common(LinkList A,LinkList B){
	//初始化工作指针p，q，新链表头尾指针s，r 
	LNode *p=A->next,*q=B->next,*s,*r;
	//初始化新链表
	LinkList C=(LinkList)malloc(sizeof(LNode));
	r=C;
	//没到两个链表结束就一直遍历
	while(p!=NULL && q!=NULL){
		//无非就三种情况，a的元素小，b的元素小，相等，前两种后移，后一种插入，分别讨论之
		if(p->data<q->data){
			p=p->next;
		} else if(p->data>q->data){
			q=q->next;
		} else {
			//新产生节点s
			s=(LNode *)malloc(sizeof(LNode));
			s->data=p->data;
			//尾插s
			r->next=s;
			r=s;
			//后移节点
			p=p->next;
			q=q->next; 
		}
	} 
	//尾节点置空
	r->next=NULL; 
} 
