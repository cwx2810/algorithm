//������������������
//���ú��������˼�룬�Ƚ��������������Һ��ӣ��ڽ��������������Һ��ӣ���󽻻�������������
void swap(BiTree b){
	//�������ڵ�Ϊ��Ϊֹ
	if(b){
		//�ݹ齻����������
		swap(b->lchild);
		swap(b->rchild);
		//�����ڵ���� 
		temp=b->lchild;
		b->lchild=b->rchild;
		b->rchild=temp; 
	} 
} 
