
//ͷ�巨��ת����
LinkList Reverse_1(LinkList &L){
	LNode *p=L->next;//p��¼��һ���ڵ� 
	LNode *r;
	L->next=NULL;//��ͷ��㿪ʼ�ж� 
	while(p!=NULL){
		r=p->next;//r��¼p֮��Ľڵ� 
		//ͷ�����������L���� 
		p->next=L->next;
		L->next=p;
		p=r;//�ƶ��α�p����һ���ڵ� 
	}
	return L;
} 

