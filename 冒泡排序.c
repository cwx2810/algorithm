//ð������
void BubbleSort(ElemType A[],int n){
	//��������Ԫ��
	for(i=0;i<n-1;i++){
		//���ÿ�������Ƿ�������
		flag=flase;
		//һ��ð�ݹ���
		for(j=n-1;j>1;j--){
			//ǰ��ıȺ���Ĵ�����Ҫ����
			if(A[j-1].key>A[j].key){
				swap(A[j-1],A[j]);
				//��������ѽ��� 
				flag=true;
			} 
		}
		//һ�˹�ȥû�н�����˵���������
		if(flag==false) return;
	} 
} 
