
//�������ã����õݹ�ķ�����Ҫ����������ֵ�����������һ���ڵ��ֵ
void R_print(LinkList L){
	if(L->next!=NULL){
		R_print(L->next);
	}
	print(L->data);
} 

