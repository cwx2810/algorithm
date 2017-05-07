
//直接翻转链表
//这方法就没头结点什么事了，头插法翻转后头结点是在原链表的尾部元素上，这个直接翻转连头结点一块翻转了 
LinkList Reverse_2(LinkList &L){
	LNode *p=L->next;//L节点只起一个初始化定位作用，真头结点其实是第一个节点 
	LNode *r=p->next;//r记录后面要翻到真第一节点前面的节点 
	LNode *pre;
	p->next=NULL;//从真第一节点后面切断 
	while(r!=NULL){
		//pre、p、r依次移动一格 
		pre=p;
		p=r;
		r=r->next;//刚好r记录下一次要用的新节点 
		p->next=pre;//p转过头接到前面去，屁股朝外面，等着下一个节点接到他后面 
	}
	L->next=p;//直到最后r判空，把头结点接上去 
	return L;
} 

