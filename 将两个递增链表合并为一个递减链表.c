//将两个递增的单链表合并为一个递减的单链表 
//两两比较，合并为递减，采用头插法，比较结束后大概率有一个链表非空，别忘了将它头插入链表
void MergeList(LinkList& La,LinkList& Lb){
	//初始化工作指针，暂存指针
	LNode *pa=La->next,*pb=Lb->next,*r;
	//不用外部空间，直接把合并链表保存在La，现在初始化之
	La->next=NULL;
	//当两个链表不为空时，迭代
	while(pa&&pb){
		
	} 
} 
