//�ж϶������Ƿ�Ϊƽ�������
//�õݹ飬�ȿ��Ǳ߽�������0���ڵ��1���ڵ����������ݹ�������������ж���������ľ���ֵҪС��2
void Judge_AVL(BiTree bt,int &balance,int &h){
	//��ʼ����������ƽ������Լ����������߶�
	int balanceL,balanceR,heightL,heightR;
	//�����ͽ���һ���ڵ�
	if(bt==NULL){
		h=0;
		balance=1;
	} else if(bt->lchild==NULL && bt->rchild==NULL){
		h=1;
		balance=1;
	} else {
		//�ݹ����������Ƿ�ƽ��
		Judge_AVL(bt->lchild,balanceL,heightL);
		Judge_AVL(bt->rchild,balanceR,heightR);
		//������ȣ����㱾������ƽ���ˣ��ݹ���һ�����߶Ȳ� 
		h=(heightL>heightR?heightL:heightR)+1;
		//�߶Ȳ�ľ���ֵ���ܴ���1
		if(abs(heightL,heightR)<2){
			//�ݹ�����������ƽ��ʱ��ƽ��
			balance=balanceL&&balanceR; 
		} else{
			//��һ�߲�ƽ�⣬��ƽ�� 
			balance=0;
		}
	}
} 
