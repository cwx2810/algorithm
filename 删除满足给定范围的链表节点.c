//ɾ�����������Χ������ڵ� 
//��������������ģ�ֻ�ܰ��ż��
void RangeDelete(LinkList& L,int min,int max){
	//��ʼ��*prΪ��ǰ��*pΪ���
	LNode *pr=L,*p=L->next;
	//��p��Ϊ��ʱ������Ѱ��ɾ��
	while(p!=NULL){
		if(p->data>min && p->data<max){
			pr->next=p->next;
			free(p);
			p=pr->next;
		}else{
			pr=p;
			p=p->next;
		}
	} 
} 
