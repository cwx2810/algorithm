//删除满足给定范围的链表节点 
//由于链表是无序的，只能挨着检查
void RangeDelete(LinkList& L,int min,int max){
	//初始化*pr为当前，*p为后继
	LNode *pr=L,*p=L->next;
	//当p不为空时，迭代寻找删除
	while(p!=NULL){
		if(p->data>min && p->data<max){
			pr->next=p->next;
			free(p);
			p=pr->next;
		}else{
			pr=p;
			p=p->next;
		}
	} 
} 
