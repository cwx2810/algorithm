//删除顺序表中所有值在s和t之间的元素
//思路：传统想法是找到符合的值就删除，然后后面所有元素前移，但这样要移动大量元素
//更好的方法是，让所有在s和t之间的元素移动到最后再一次性删除
//用k记录当前元素是否满足在s和t之间，若满足，k++，若不满足，则将其向前移动k个元素，就刚好到后面那堆符合条件的k个元素之前了
bool Del_s_t(sqList &L,ElemType s,ElemType t){
	//初始化遍历变量i和计数器k
	int i,k=0;
	//corner case
	if(L.length==0 || s>=t) return false;
	//遍历顺序表
	for(i=0;i<L.length;i++){
		//满足条件
		if(L.data[i]>=s && L.data[i]<=t){
			//计数器+1 
			k++;
		} else{
			//向前移动k个位子
			L.data[i-k]=L.data[i]; 
		}
	} 
	//一次删干净
	L.length-=k;
	return true; 
} 
