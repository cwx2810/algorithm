//已知满二叉树的前序遍历，转换为后序遍历
//用递归，分一半，先转换左边，再转换右边，递归转换左边的左边...每次交换根节点，最后递归到最底下两个节点左右交换
//当然这个交换是写在程序前面的，后面摆递归，脑补一下，实在不好解释= =！
void PreToPost(ElemType pre[],int s1,int e1,ElemType post[],int s2,int e2){
	//初始化一半的位子 
	int half;
	//给定树不空（存在），迭代 
	if(e1>s1){
		//根与根的交换 
		post[e2]=pre[s1];
		//计算一半
		half=(e1-s1)/2;
		//递归交换两种遍历的左边，注意跳过根节点（s1+1） 
		PreToPost(pre,s1+1,s1+half,post,s2,s2+half-1) 
		//递归交换两种遍历的右边，注意跳过根节点（e2-1） 
		PreToPost(pre,s1+half+1,e1,post,s2+half,e2-1); 
	}
} 
