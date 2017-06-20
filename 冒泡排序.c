//冒泡排序
void BubbleSort(ElemType A[],int n){
	//遍历所有元素
	for(i=0;i<n-1;i++){
		//标记每趟排序是否发生交换
		flag=flase;
		//一趟冒泡过程
		for(j=n-1;j>1;j--){
			//前面的比后面的大，逆序，要交换
			if(A[j-1].key>A[j].key){
				swap(A[j-1],A[j]);
				//标记置于已交换 
				flag=true;
			} 
		}
		//一趟过去没有交换，说明是有序的
		if(flag==false) return;
	} 
} 
