//�ж϶������Ƿ����ƣ���̬�滮
//���Ƶ���˼�Ƕ�Ϊ�գ���ֻ�и��ڵ㣬���ߵݹ����ǵ���������������
int Similar(BiTree T1,BiTree T2){
	//�����Կ�
	if(T1==NULL && T2==NULL){
		return 1;
	} else if(T1==NULL || T2==NULL){
		//ֻ��һ��Ϊ��
		return 0; 
	} else{
		//�ݹ飬����Ҫ���ƣ�����ҲҪ���� 
		return Similar(T1->lchild,T2->lchild) && Similar(T1->rchild,T2->rchild); 
	}
} 
