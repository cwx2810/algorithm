//建立大根堆算法
//总的思路就是在子树中找大的节点上浮 

void BuildMaxHeap(ElemType A[],int len){
	//i为根节点，从根节点起遍历反复调整堆，找到较小的i，和下面大的对调，也就是向下调整i 
	for(int i=len/2;i>0;i--) AdjustDown(A,i,len); 
} 
void AdjustDown(ELemType A[],int k,int len){
	//缓存当前传入节点k
	A[0]=A[k];
	//遍历k的儿子
	for(i=2*k;i<=len;i=i*2){
		//遍历的儿子中如果较小就跳过，找到较大的那个
		if(i<len&&A[i]<A[i+1]) i++;
		if(A[i]<=A[0]){
			//如果取到的下标对应的值都比老爹小，跳出循环
			break; 
		}else{
			//如果有筛选出比老爹大的儿子，把儿子调整到爸爸的位子上 
			A[k]=A[i];
			//接着i往下遍历 
			k=i; 
		}
	} 
	//缓存的原先在最顶上的值，现在放到他合适的位子
	A[k]=A[0]; 
}
