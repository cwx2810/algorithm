
//ʹ��ͷ��������������� 
//�뷨��ֻ���һ���ڵ�p����L���棬��������������Ѱ��pre�㣬ʹ�øպ�p�������pre�����������ԭ��pre�ĺ��Ҳ���ô���p
//����p�����pre���� 
LinkList Insert(LinkList &L){
	//����һ��ֻ��һ���ڵ�Ĵ�ͷ�������
	LNode *p=L->next;
	LNode *r=p->next;//��¼p�ĺ�� 
	LNode *pre;
	p->next=NULL;//��p���ж� 
	//�ƶ��α�pָ���ж�ǰ��p��� 
	p=r;
	while(p!=NULL){
		//rҪ�����ƶ���¼����ĵ��ֹ����
		r=p->next;
		//��ʱ���������������ڵ�һ����ͷ���������ͷ��㿪ʼ��������Ѱ��p�Ĳ����pre
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
