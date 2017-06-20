//是否存在顶点i到某点j的路径，用广度优先遍历

//初始化标记数组
int visited[MAXSIZE]={0};
int Exist_Path_BFS(ALGraph G,int i,int j){
	//初始化队列
	InitQueue(Q);
	//顶点入队
	EnQueue(Q,i);
	//若队列非空，则迭代
	while(!IsEmpty(Q)){
		//对第一次的节点详细操作，之后的递归操作 
		//队头结点出队
		DeQueue(Q,u);
		//设置已访问标记
		visited[u]=1; 
		//递归剩下的邻接点
		for(p=FirstNeighbor(G,i);p;p=NextNeighbor(G,i,p)){
			//检查所有邻接点
			k=p.adjvex;
			//找到咯 
			if(k==j) return 1;
			//不匹配，k未被访问过，先入队，用作求下一层邻接点的素材 
			if(!visited[k]) EnQueue(Q,k); 
		} 
	} 
	//迭代完都没找到 
	return 0;
} 
