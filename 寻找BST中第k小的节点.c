//Ѱ��BST�е�kС�Ľڵ㣬��ÿ���ڵ��һ��count��ͳ���Ըýڵ�Ϊ���������ڵ����
//����BST����С�Ҵ�����ʣ����������
//һ�����������û��������ʱ������������Ѱ�� 
//��������������ʱ��Ҫ�жϽڵ���������������������Ѱ�� 
BSTNode *Search_Small(BSTNode*t,int k){
	//corner case
	if(k<1 || k>t->count) return NULL;
	//���ֻ�������� 
	if(t->lchild==NULL){
		if(k==1){
			//�������k=1 
			return t;
		}else{
			//���ұߵݹ�Ѱ�ң���С���Ѿ��Ǹ��ڵ��ˣ���������ֻ��Ҫ�ҵ�k-1С�� 
			Search_Small(t->rchild,k-1);
		}
	}else{
		//������������
		//���������߸պ���k-1���ڵ�
		if(t->lchild->count==k-1) return t;
		//���������������㹻�Ľڵ㣬�ݹ��ҵ�kС 
		if(t->lchild->count>k-1) return Search_Small(t->lchild,k); 
		//���鷳���������߲���k-1���ڵ㣬��kС�������ұߣ���߰������ڵ������Ѿ���count+1��С�Ľڵ��ˣ����ұ�Ѱ��Ҫ��ȥ��Щ 
		if(t->lchild->count<k-1) return Search_Small(t->rchild,k-(t->lchild->count+1)); 
	}
}
