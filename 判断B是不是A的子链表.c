//判断B链表是否是A链表的子链表
//设置两个指针比较两个链表的值，如果相等，指针后移
//如果不等，a退回到当前趟比较的开头后一个（第一个刚试过不符合），b退回到最开头重新匹配
//a到头则匹配失败，b到头则匹配成功
int Pattern(LinkList A,LinkList B){
	//本题假定AB均无头结点
	//初始化AB的指针
	LNode *p=A;
	LNode *q=B;
	//初始化记录指针，记录A的当前趟开头
	LNode *pre=p;
	//当AB中元素没有用尽，迭代
	while(p&&q){
		//如果节点相同，相安无事，同时后移
		if(p->data==q->data){
			p=p->next;
			q=q->next;
		} else{//如果不同，a退回到开头后一个，b退回到最开头 
			pre=pre->next;
			p=pre;
			q=B;
		}
	} 
	//B先结束，是子序列
	if(q==NULL){
		return 1;
	} else{//A先结束，B不是子序列 
		return 0;
	}
} 
