
//ʹ��ͷ�����������
//�뷨��ֻ���һ���ڵ����L���棬Ѱ��pre�㣬ʹ�����pre����С��p��������һ��Ԫ���ִ���p������p�����pre���� 
LinkList Insert(LinkList &L){
	//����һ��ֻ��һ���ڵ�Ĵ�ͷ�������
	LNode *p=L->next;
	LNode *r=p->next;
	LNode *pre;
	P->next=NULL;
	//�ƶ��α�pѰ����һ������ 
	p=r;
	while(p!=NULL){
		//rҪ�����ƶ���¼����ĵ��ֹ����
		r=p->next;
		//��ͷ��㿪ʼ��������Ѱ��p�Ĳ����pre
		pre=L;
		while(pre->next!=NULL && pre->next->data<p->data){
			pre=pre->next;
		} 
		//����p��pre֮��
		p->next=pre->next;
		pre->next=p;
		//�ƶ��α�pѰ����һ������
		p=r; 
	} 
}
