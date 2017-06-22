//寻找线性表中第k小的元素
//暴力解法自然是先从小到大排序，直接取第k个元素，但是此法消耗过大
//更好的解法是利用快排的思想，不是真的要排序，而是用思想，找出基准p，线性表一分为二，此时基准p恰好落在第k小的位子上...

//此快排（移动下标赋值法）非常难以想象，我是找了实例带入才看懂 
int kth_elem(int a[],int low,int high,int k){
	//初始化基准p为第一个节点
	int pivot=a[low];
	//记录一开始的开始和结尾节点下标，因为快排会改变下标所指
	int low_temp=low;
	int high_temp=high;
	//只要下标不重合，就一直迭代
	while(low<high){
		//当下标不重合而且下标符合大的在基准后面就跳过，直到在基准后面发现小的停下
		while(low<high&&a[high]>=pivot) --high;
		//让小的覆盖前面的最低下标，注意，这里第一次覆盖的是基准p，无所谓，因为p已经被记录
		//往后交替覆盖，低的再赋给已经把值赋出去了的高的，所以也无所谓的 
		a[low]=a[high];
		//同上，在低的这边比较排序 
		while(low<high&&a[low]<=pivot) ++low; 
		a[high]=a[low];
	}
	//直到最后，都调整完毕，把开始记录的p赋到中间（此时low是走到中间了的，所以赋给low）
	a[low]=pivot;
	//以上是快排划分算法，以下是根题目相关的递归内容
	if(low==k){
		//手真好，一把找到了，k刚好=划分点 
		return a[low];
	} else if(k<low){
		//k在左边，在左边递归
		return kth_elem(a,low_temp,low-1,k); 
	} else {
		//k在右边，在右边递归
		return kth_elem(a,low+1,high_temp,k); 
	}
} 
