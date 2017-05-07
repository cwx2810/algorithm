
//删除链表值最小节点
LinkList DeleteMin(LinkList &L){
	//构造四个指针，p和pre是遍历游标，pmin和premin负责保存要删除的最小节点，遍历到最后保存的也是最小的，free之 
	LNode *p=L->next;
	LNode *pre=L;
	LNode *pmin=p;
	LNode *premin=pre;
	while(p!=NULL){
		//如果p的值比pmin保存的小，替换之 
		if(p->data<pmin->data){
			pmin=p;
			premin=pre;
		}
		//继续遍历，直到遍历到NULL 
		pre=p;
		p=p->next;
	}
	//释放掉 
	premin->next=pmin->next;
	free(pmin);
	return L;
} 

