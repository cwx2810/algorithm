//����������ͷ����ѭ��������ʹ���Ӻ���ѭ��������
//�ҵ�a��βָ�룬��b��ͷָ��ӵ�����
LinkList Link(LinkList &A,LinkList &B){
	//��ʼ������ָ��
	LNode *p,*q; 
	//Ѱ��AB��β�ڵ�
	p=A;
	while(p->next!A){
		p=p->next;
	} 
	q=B;
	while(q->next!B){
		q=q->next;
	}
	//��B�ӵ�A����
	p->next=B;
	//��A��ͷ�ӵ�B�������ѭ������ 
	q->next=A; 
	//����
	return A; 
} 
