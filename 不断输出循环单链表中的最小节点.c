//不断输出并删除带头结点的循环单链表中的最小节点
//这题没什么意思，没什么好说的
void Del_All(LinkList &L){
	//初始化工作指针
	LNode *p,*pre;
	//初始化指向最小值的指针
	LNode *minp,*minpre;
	//当表没有被删空时，迭代
	while(L->next!=L){
		//初始化
		p=L->next;
		pre=L;
		minp=p;
		minpre=pre;
		//循环一趟，查找最小节点
		while(p!=L){
			if(p->data<minp->data){
				minp=p;
				minpre=pre;
			}
			pre=p;
			p=p->next;
		} 
		//输出最小节点 
		printf("%d",minp->data);
		//释放
		minpre->next=minp->next;
		free(minp);
	} 
 	//最后释放头节点
	free(L); 
} 
