//�ҳ���������k���ڵ� 
//��������ָ��pq����ʼ��ָ���һ���ڵ㣬����p�ƶ�����k��λ�ӣ�Ȼ��pqͬʱ�ƶ�����ʱpq��Ĳ�����k����p�ߵ�ͷʱq��ָ���˵�����k 
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *link;
}LNode,LinkList;
int Search_k(LinkList L,int k){
	//��ʼ��ָ��
	LNode *p=L->next,*q=L->next;
	//��ʼ��������
	int count=0;
	//������p�ߵ�ͷ
	while(p!=NULL){
		//���count<k��ֻ�ƶ�p
		if(count<k){
			count++;
		} else{//���count=k�ˣ���ͬʱ�ƶ� 
			q=q->next;
		}
		p=p->next;
	} 
	//�ߵ����count��С��k��corner case
	if(count<k){
		return 0;
	} else{//������ҳɹ� 
		printf("%d",q->data);
		return 1;
	}
}
