//双向冒泡排序
//奇数趟正向两两比较，最大元素沉底，偶数趟相反，最小元素冒泡
void BubbleSort(ElemType A[],int n){
	//初始化上下界
	int low=0,high=n-1;
	//初始化是否交换标记
	bool flag=true;
	//循环条件，序列不能为空，标识不能为false（false说明没有逆序了）
	while(low<high&&flag){
		//每趟冒泡初始化flag为false
		flag=false;
		//从前向后冒泡，大的沉底
		for(i=low;i<high;i++){
			//发生逆序
			if(A[i]>A[i+1]){
				//交换
				swap(A[i],A[i+1]);
				//置已交换
				flag=true; 
			} 
		} 
		//更新上界，其实是后界，刚沉底的不用管了
		high--;
		//从后向前冒泡
		for(i=high;i>low;i--){
			//发生逆序
			if(A[i]<A[i-1]){
				//交换
				swap(A[i],A[i-1]);
				//置已交换
				flag=true; 
			} 
		} 
		//更新下界
		low++; 
	} 
}
