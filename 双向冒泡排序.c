//˫��ð������
//���������������Ƚϣ����Ԫ�س��ף�ż�����෴����СԪ��ð��
void BubbleSort(ElemType A[],int n){
	//��ʼ�����½�
	int low=0,high=n-1;
	//��ʼ���Ƿ񽻻����
	bool flag=true;
	//ѭ�����������в���Ϊ�գ���ʶ����Ϊfalse��false˵��û�������ˣ�
	while(low<high&&flag){
		//ÿ��ð�ݳ�ʼ��flagΪfalse
		flag=false;
		//��ǰ���ð�ݣ���ĳ���
		for(i=low;i<high;i++){
			//��������
			if(A[i]>A[i+1]){
				//����
				swap(A[i],A[i+1]);
				//���ѽ���
				flag=true; 
			} 
		} 
		//�����Ͻ磬��ʵ�Ǻ�磬�ճ��׵Ĳ��ù���
		high--;
		//�Ӻ���ǰð��
		for(i=high;i>low;i--){
			//��������
			if(A[i]<A[i-1]){
				//����
				swap(A[i],A[i-1]);
				//���ѽ���
				flag=true; 
			} 
		} 
		//�����½�
		low++; 
	} 
}
