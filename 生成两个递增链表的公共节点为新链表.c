//����������ͷ���ĵ����ĵ�����Ĺ����ڵ�Ϊ������ 
//��Ѱ������������Ԫ�ز�ͬ���ǣ���������ǵ������������Ƚϲ���ʱ��ֻ���ƶ�С��ֵ�Ľڵ�
//����ȣ��򴴽�ֵ��ȵ��½ڵ�β�巨����������ָ��ͬʱ���ƣ�ֱ��һ���������
void Get_Common(LinkList A,LinkList B){
	//��ʼ������ָ��p��q��������ͷβָ��s��r 
	LNode *p=A->next,*q=B->next,*s,*r;
	//��ʼ��������
	LinkList C=(LinkList)malloc(sizeof(LNode));
	r=C;
	//û���������������һֱ����
	while(p!=NULL && q!=NULL){
		//�޷Ǿ����������a��Ԫ��С��b��Ԫ��С����ȣ�ǰ���ֺ��ƣ���һ�ֲ��룬�ֱ�����֮
		if(p->data<q->data){
			p=p->next;
		} else if(p->data>q->data){
			q=q->next;
		} else {
			//�²����ڵ�s
			s=(LNode *)malloc(sizeof(LNode));
			s->data=p->data;
			//β��s
			r->next=s;
			r=s;
			//���ƽڵ�
			p=p->next;
			q=q->next; 
		}
	} 
	//β�ڵ��ÿ�
	r->next=NULL; 
} 
