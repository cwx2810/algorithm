//将两个递增的单链表合并为一个递减的单链表 
//两两比较，合并为递减，采用头插法，比较结束后大概率有一个链表非空，别忘了将它头插入链表
void MergeList(LinkList& La,LinkList& Lb){
	//初始化工作指针，暂存指针
	LNode *pa=La->next,*pb=Lb->next,*r;
	//不用外部空间，直接把合并链表保存在La，现在初始化之
	La->next=NULL;
	//当两个链表不为空时，迭代
	while(pa&&pb){
		//如果a中的小，头插a
		if(pa->data<pb->data){
			//r暂存a的后继，避免断链
			r=pa->next;
			//头插
			pa->next=La->next;
			La->next=pa;
			//通过r恢复pa，为下一次比较做准备 
			pa=r; 
		} else{//如果b中的小，头插b 
			r=pb->next;
			pb->next=La->next;
			La->next=pb;
			pb=r;
		}
		//处理剩下的非空链表，如果a剩下，统一归并到b处理
		if(pa){
			pb=pa;
		} 
		while(pb){
			r=pb->next;
			pb->next=La->next;
			La->next=pb;
			pb=r;
		}
		//释放空的Lb
		free(Lb); 
	} 
} 
