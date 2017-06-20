//快速排序
//设定基准，快速分治
void QuickSort(ElemType A[],int low,int high){
	//递归跳出条件
	if(low<high){
		//划分 
		int pivotpos=Partition(A,low,high);
		//根据划分递归左右两边
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high); 
	} 
} 
