//ǰ�����������������������
//��LeetCode��˼·һ����ͨ��ǰ�������һ��ֵȷ�����ڵ㣬���������һ��Ϊ�����������ߵݹ�
BiTree PreInCreat(ElemType A[],ElemType B[],int s0,int e0,int s1,int e1){//s��e�ֱ������������Ŀ�ʼ��β�±� 
	//��ʼ��
	s0=s1=0;
	e0=e1=n;
	//�������ڵ�
	root=(BitNode*)malloc(sizeof(BitNode));
	root->data=A[s0];
	//�ҵ����ڵ������������е�λ��
	for(i=s1;B[i]!=root->data;i++);
	//��ʼ�������������
	left=i-s1;
	right=e1-i; 
	//�ݹ齨����������ע�����������������ȱ�ʵ��ֵС1�����Ҫע����ڵ��λ�ӣ�������� 
	if(left){
		root->lchild=PreInCreat(A,B,s0+1,s0+left,s1,s1+left-1);
	} else{
		root->lchild=NULL;
	}
	//�ݹ齨�������� 
	if(right){
		root->rchild=PreInCreat(A,B,e0-right+1,e0,e1-right+1,e1);
	} else{
		root->rchild=NULL;
	}
	//���ع�����ɵ��� 
	return root;
} 
