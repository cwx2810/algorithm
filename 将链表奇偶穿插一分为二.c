//����ͷ��������һ��Ϊ������ͷ��������A��������Ԫ�أ�B����ż��Ԫ�أ����˳���ܱ�
//��Ԫ�ؽ���嵽�������������
LinkList DisCreate_1(LinkList& A){
	//��ʼ����B
	B=(LinkList)malloc(sizeof(LNode));
	B->next=NULL;
	//��Ҫ����β�巨����ָ����β
	LNode *ra=A,*rb=B;
	//׼���ÿ�A��ץ����¼����������ָ��
	p=A->next;
	A->next=NULL;
	//����
	while(p!=NULL){
		//�Ȳ�A��
		ra->next=p;
		ra=p;
		p=p->next;
		//�ٲ�B�� 
		rb->next=p;
		rb=p;
		p=p->next;
	} 
	//�ͷ�βָ�룬����
	ra->next=NULL;
	rb->next=NULL;
	return B; 
} 
