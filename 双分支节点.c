//�������������˫��֧�ڵ����
//��̬�滮��corner case�ǽڵ�û�ж��ӣ����̷����������
//һ��ȷʵ��˫��֧����ǰ�ڵ�ĸ�������������˫��֧�ڵ�����ټ��Լ���1
//һ���ǵ���֧����ǰ�ڵ����������˫��֧�������Һ���˫��֧������û���Լ���1
int DSonNodes(BiTree b){
	//corner case
	if (b==NULL){
		return 0;
	}else if(b->lchild!=NULL && b->rchild!=NULL){
		//��˫��֧ 
		return DSonNodes(b->lchild)+DSonNodes(b->rchild)+1;
	}else{
		//ֻ�е���֧ 
		return DSonNodes(b->lchild)+DSonNodes(b->rchild);
	}
} 
