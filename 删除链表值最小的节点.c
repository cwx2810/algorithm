
//ɾ������ֵ��С�ڵ�
LinkList DeleteMin(LinkList &L){
	//�����ĸ�ָ�룬p��pre�Ǳ����α꣬pmin��premin���𱣴�Ҫɾ������С�ڵ㣬��������󱣴��Ҳ����С�ģ�free֮ 
	LNode *p=L->next;
	LNode *pre=L;
	LNode *pmin=p;
	LNode *premin=pre;
	while(p!=NULL){
		//���p��ֵ��pmin�����С���滻֮ 
		if(p->data<pmin->data){
			pmin=p;
			premin=pre;
		}
		//����������ֱ��������NULL 
		pre=p;
		p=p->next;
	}
	//�ͷŵ� 
	premin->next=pmin->next;
	free(pmin);
	return L;
} 

