//���������ɾ����ͷ����ѭ���������е���С�ڵ�
//����ûʲô��˼��ûʲô��˵��
void Del_All(LinkList &L){
	//��ʼ������ָ��
	LNode *p,*pre;
	//��ʼ��ָ����Сֵ��ָ��
	LNode *minp,*minpre;
	//����û�б�ɾ��ʱ������
	while(L->next!=L){
		//��ʼ��
		p=L->next;
		pre=L;
		minp=p;
		minpre=pre;
		//ѭ��һ�ˣ�������С�ڵ�
		while(p!=L){
			if(p->data<minp->data){
				minp=p;
				minpre=pre;
			}
			pre=p;
			p=p->next;
		} 
		//�����С�ڵ� 
		printf("%d",minp->data);
		//�ͷ�
		minpre->next=minp->next;
		free(minp);
	} 
 	//����ͷ�ͷ�ڵ�
	free(L); 
} 
