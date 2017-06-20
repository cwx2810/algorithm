//是否存在顶点i到某点j的路径，用深度优先遍历

//初始化访问标记
int visited[MAXSIZE]={0};
int Exit_Path_DFS(ALGraph G,int i,int j){
	//初始化节点序号
	int p;
	//corner case 要求的j就是顶点
	if(i==j){
		return 1;
	} else{
		//设置第一个节点访问标记
		visited[i]=1;
		//递归检测后面的邻接点
		for(p=FirstNeighbor(G,i);p>=0;p=NextNeighbor(G,i,p)){
			//如果节点没有访问过并且可以深度优先搜索到，则能找到路径
			if(!visited[k]&&Exist_Path_DFS(G,p,j)) return 1; 
		} 
	}
	//找不到 
	return 0;
}
