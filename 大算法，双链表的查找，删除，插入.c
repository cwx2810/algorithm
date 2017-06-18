//大算法，双链表的查找，删除，插入
//双链表每个节点除了前驱后继和值域，再加入一个记录访问频度的域，设计一个算法调整节点到合适的位子
//调整规则按照频度递减，即访问次数越多的节点越靠近头结点
//当调用访问节点函数时，判断他的频度，把他调整到同一频度节点的最前面
DLinkList Locata(DLinkList &L,ElemType e){
	//初始化工作指针
	DNode *p=L->next;
	//初始化p的前驱指针（插入位子）
	DNode *q;
	//首先查找等于给定值x的节点位子 
	while(p&&p->data!=x){
		p=p->next;
	}
	//如果找不到，则corner case了
	if(!p){
		exit(0);
	} else{//找到了，继续判断 
		//首先频度要++
		p->freq++;
		//初始化q
		q=p->pred; 
		//将p删掉
		p->next->pred=p->pred;
		p->pred->next=p->next;
		//找到插入位子，即q往前遍历，找到第一个频度比p大的节点
		while(q!=L && q->freq<=p->freq){
			q=q->pred;
		} 
		//将p插入，连接四条线
		p->next=q->next;
		q->next->pred=p;
		p->pred=q;
		q->next=p; 
	}
	//返回查找并调整过位子后的等于x的节点 
	return p;
} 
