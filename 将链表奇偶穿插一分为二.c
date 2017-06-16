//将带头结点的链表一分为二个带头结点的链表，A中是奇数元素，B中是偶数元素，相对顺序不能变
//把元素交替插到两个拆分链表中
LinkList DisCreate_1(LinkList& A){
	//初始化表B
	B=(LinkList)malloc(sizeof(LNode));
	B->next=NULL;
	//将要采用尾插法，先指定表尾
	LNode *ra=A,*rb=B;
	//准备置空A表，抓紧记录，建立工作指针
	p=A->next;
	A->next=NULL;
	//迭代
	while(p!=NULL){
		//先插A表
		ra->next=p;
		ra=p;
		p=p->next;
		//再插B表 
		rb->next=p;
		rb=p;
		p=p->next;
	} 
	//释放尾指针，返回
	ra->next=NULL;
	rb->next=NULL;
	return B; 
} 
