//�۰��������������˳��洢������ʱ�Ͽ� 
void InsertSort(ElemType A[],int n){
	//��ʼ���ڵ��±�i
	int i;
	//��ʼ������λ��
	int j;
	//��ʼ�����ҷ�Χ���м�ڵ�
	int low,high,mid;
	//���β���2~n���ڵ�
	for(i=2;i<=n;i++){
		//������ڵ�ת���ڱ�
		A[0]=A[i];
		//��ʼ�����ҷ�Χ
		low=1;high=i-1;
		//�۰����
		while(low<=high){
			//ȡ�м��
			mid=(low+high)/2;
			//ֵ���м��С���������
			if(A[mid].key>A[0].key){
				high=mid-1;
			} else{
				//��������ұ�
				low=mid+1; 
			}
		} 
		//����Ԫ�أ��ճ�����λ��
		for(j=i-1;j>=high;--j) A[j+1]=A[j];
		//����
		A[high+1]=A[0]; 
	} 
} 
