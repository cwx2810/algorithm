//�����������Ȩ·������ 
//�����������˼��ݹ飬���ﵽҶ�ڵ㣬���ۼ�·��Ȩ֮���ĺͣ���û��Ҷ�ڵ㣬�������������õݹ飬��ȼ�һ
int WPL(BiTree root){
	return wpl_preOrder(root,0);
} 
int wpl_preOrder(BiTree root,int deep){
	//��ʼ����Ȩ·��
	static int wpl=0;
	//��ΪҶ�ڵ㣬�ۼ�wpl
	if(root->lchild==NULL && root->rchild==NULL) wpl+=deep*root->weight;//��� X Ȩֵ 
	//��������Ϊ�գ�����������������ȼ�һ 
	if(root->lchild!=NULL) wpl_preOrder(root->lchild,deep+1);
	//��������Ϊ�գ�����������������ȼ�һ 
	if(root->rchild!=NULL) wpl_preOrder(root->rchild,deep+1);
	//���ش�Ȩ·������
	return wpl; 
}
