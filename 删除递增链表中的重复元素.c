//ɾ�����������е��ظ�Ԫ��
//�����ǵ��������ظ�Ԫ�ض������ڵģ�ֱ��ͨ��ָ���ж�ǰ��������ͷź���
void Delete_Same(LinkList& L){
	//��ʼ��ɨ��ָ��p
	LNode *p=L->next;
	//��ʼ���ͷ�ָ��q
	LNode *q;
	//��p�ĺ�̲�Ϊ��ʱ������
	while(p->next!=NULL){
		//��ʼ��q
		q=p->next;
		//�ҵ��ظ��ģ��ͷ�
		if(p->data==q->data){
			p->next=q->next;
			free(q);
		} else{
			//���ظ����ƶ�����һ�� 
			p=p->next;
		}
	} 
} 
