//删除递增链表中的重复元素
//由于是递增链表，重复元素都是相邻的，直接通过指针判断前后相等则释放后者
void Delete_Same(LinkList& L){
	//初始化扫描指针p
	LNode *p=L->next;
	//初始化释放指针q
	LNode *q;
	//当p的后继不为空时，迭代
	while(p->next!=NULL){
		//初始化q
		q=p->next;
		//找到重复的，释放
		if(p->data==q->data){
			p->next=q->next;
			free(q);
		} else{
			//不重复，移动到下一个 
			p=p->next;
		}
	} 
} 
