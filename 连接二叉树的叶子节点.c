//����������Ҷ�ӽڵ���������
//˼�룺��һ��Ҷ����headָ����ָ��preָ�򣨼�¼������֮���������Ҷ�ӽڵ㣬��pre��rchildָ�����һ��Ҷ�ӽڵ��rchildָ���
//�������������������

LinkedList head,pre=NULL;
LinkedList InOrder(BiTree bt){
	//�������к��� 
	if(bt){
		//�ݹ�����������������������к��ӣ� 
		InOrder(bt->lchild);
		//������Ҷ�ڵ㣬��������
		if(bt->lchild==NULL&&bt->rchild==NULL){
			//����ǵ�һ��Ҷ�ӽڵ㣬��headָ�򼴿�
			if(pre==NULL){
				head=bt;
				//��ʼ��pre 
				pre=bt;
			} else{
				//���˺����Ҷ�ӽڵ㣬��pre���Һ���ָ��
				pre->rchild=bt;
				//����pre
				pre=bt; 
			}
		}
		//�ݹ�������������������Һ����к��ӣ� 
		InOrder(bt->rchild);
		//���һ��Ҷ�ӽڵ��ÿ�
		pre->rchild=NULL; 
	}
	return head;
} 
