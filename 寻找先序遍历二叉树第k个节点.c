//����������������е�k���ڵ�

//��ʼ����ǽڵ㣬��1�����ڵ㿪ʼѰ�� 
int i=1; 
ElemType PreNode(BiTree b,int k){
	//corner case
	if(b==NULL){
		return '#';
	}
	//�����Ǵﵽ��k�����ҵ���
	if(i==k) return b->data;
	//û�ҵ�����һ���ڵ�
	i++;
	//���������еݹ�Ѱ��
	ch=PreNode(b->lchild,k);
	//������ߣ�����
	if(ch!='#') return ch;
	//���������еݹ�Ѱ�ң����һ�����ˣ������ܲ���
	return PreNode(b->rchild,k); 
}
