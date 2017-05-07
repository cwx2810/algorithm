
//链表逆置，采用递归的方法，要想输出链表的值必须先输出后一个节点的值
void R_print(LinkList L){
	if(L->next!=NULL){
		R_print(L->next);
	}
	print(L->data);
} 

