//��������
//�趨��׼�����ٷ���
void QuickSort(ElemType A[],int low,int high){
	//�ݹ���������
	if(low<high){
		//���� 
		int pivotpos=Partition(A,low,high);
		//���ݻ��ֵݹ���������
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high); 
	} 
} 
