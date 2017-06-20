//折半插入排序，适用于顺序存储，查找时较快 
void InsertSort(ElemType A[],int n){
	//初始化节点下标i
	int i;
	//初始化插入位子
	int j;
	//初始化查找范围，中间节点
	int low,high,mid;
	//依次插入2~n个节点
	for(i=2;i<=n;i++){
		//将插入节点转成哨兵
		A[0]=A[i];
		//初始化查找范围
		low=1;high=i-1;
		//折半查找
		while(low<=high){
			//取中间点
			mid=(low+high)/2;
			//值比中间点小，查找左边
			if(A[mid].key>A[0].key){
				high=mid-1;
			} else{
				//否则查找右边
				low=mid+1; 
			}
		} 
		//后移元素，空出插入位子
		for(j=i-1;j>=high;--j) A[j+1]=A[j];
		//插入
		A[high+1]=A[0]; 
	} 
} 
