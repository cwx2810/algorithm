//�ǵݹ���������߶�
//�ò�α����ķ�������levelΪ�߶ȣ�lastΪÿ�����һ���ڵ㣬��ÿ�����ʱָ����last���ʱ��level+1��lastָ����һ�����ҽڵ�
//����û��̫����������++rear,++front,last=rear��Щ 
int Btdepth(BiTree T){
	//corner case
	if(!T) return 0;
	//��ʼ��ÿ��Ŀ�ͷ�ͽ�βָ��
	int front=-1,rear=-1;
	//��ʼ��level��last
	int level=0,last=0;
	//��ʼ������Q
	BiTree Q[MaxSize];
	//���ڵ���ӣ�����ָ�룬����Ԫ�� 
	Q[++rear]=T;
	//��ʼ������ָ�� 
	BiTree p;
	//ֻҪ���в��գ�����
	while(front<rear){
		//��ʼ��pΪ���е�һ��Ԫ�أ������ڵ���� 
		p=Q[++front];
		//p�����Һ������
		if(p->lchild) Q[++rear]=p->lchild;
		if(p->rchild) Q[++rear]=p->rchild;
		//��front�ߵ�lastʱ
		if(front==last){
			//����+1 
			level++;
			//lastָ���²� 
			last=rear;
		} 
	} 
	return level;
} 
