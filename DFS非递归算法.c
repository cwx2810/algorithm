//DFS非递归算法
//既然非递归，就要用到栈S保存已经访问过的节点，设置标记visited标记是否曾经入栈，入过了就不让节点再入了
void DFS_Non_RC(AGraph& G,int v){
	//初始化顶点
	int w;
	//初始化栈
	InitStack(S);
	//初始化visited，置FALSE
	for(i=0;i<G.vexnum;i++) visited[i]=FALSE;
	//顶点入栈
	Push(s,v);
	visited[v]=TRUE;
	//迭代
	while(!IsEmpty(S)){
		//对第一个节点分解操作，退出栈顶元素，访问。。对之后的节点都递归 
		k=Pop(S);
		visit(k);
		//递归，对之后的节点的入栈、访问、标记 
		//因为用栈，所以从大到小，即从右端到左端进行递归，取的时候刚好是正向的 
		for(w=FirstNeighbor(G,k);w>=0;w=NextNeighbor(G,k,w)){
			//如果下一个节点还没有被访问，则压栈，标记 
			if(!visited[w]){
				Push(S,w);
				visited[w]=TRUE;
			}
		} 
	} 
} 
