//归并两个递增链表的公共节点
//与寻找公共节点并生成新链表不同的是，这次要破坏原链表，直接在链表A中生成
//采用归并的思想，设置两个指针，当元素同时出现在两个集合中时，保留一个，其余释放，一个链表到头后释放多出来的另一个链表
LinkList Union(LinkList &la,LinkList &lb){
	//初始化指针
	pa=la->next;
	pb=lb->next;
	//初始化合并节点的前驱指针
	pc=la;
	//当两个链表中有元素时，迭代
	while(pa&&pb){
		//找到相同的元素
		if(pa->data==pb->data){
			//a中节点连接到合并节点
			pc->next=pa;
			//合并节点指向新的前驱
			pc=pa;
			//两个链表节点后移，释放b中已经用过的相同元素
			pa=pa->next;
			u=pb;
			pb=pb->next;
			free(u); 
		} else if(pa->data<pb->data){//a中节点小于b中节点，a中指针后移，释放a中节点 
			u=pa;
			pa=pa->next;
			free(u);
		} else{//对b<a的情况同理 
			u=pb;
			pb=pb->next;
			free(u);
		}
	} 
	//遍历结束，当唯独a中剩下节点时，free之
	while(pa){
		u=pa;
		pa=pa->next;
		free(u);
	} 
	//唯独b中剩下节点同样free之
	while(pb){
		u=pb;
		pb=pb->next;
		free(u);
	} 
	//置合并链表尾指针为空
	pc->next=NULL;
	//释放链表b的头结点，完全释放链表b
	free(lb); 
	//返回
	return la; 
} 
