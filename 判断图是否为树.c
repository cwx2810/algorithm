//判断无向图是否为树 
//是树的条件是n个顶点的图是有n-1条边的连通图，就是不能成环，要能通过深度优先搜索走完所有节点和边才行 
bool isTree(Graph& G){
	//访问标记初始化（均设置为未访问过） 
	for(i=1;i<=G.vexnum;i++) visited[i]=FALSE;
	//初始化顶点数和边数
	int Vnum=0,Enum=0;
	//DFS，顺便统计访问过的顶点数和边数
	DFS(G,1,Vnum,Enum,visited);
	if(Vnum==G.vexnum && Enum==2*(G.vexnum-1)){
		//符合是树的条件
		return true; 
	} else {
		//不符合
		return false; 
	}
}
void DFS(Graph& G,int v,int &Vnum,int &Enum,int visited[]){
	//每访问一个节点，标记之
	visited[v]=TRUE;
	//顶点数+1
	Vnum++;
	//是否能取到邻接点，证明是否连通，是否有边，先试着取一哈
	int w=FirstNeighbor(G,v);
	//取到了，记边数，递归的往下取
	while(w!=-1){
		Enum++;
		//该邻接点未曾访问过，递归访问之 
		if(!visited[w]) DFS(G,w,Vnum,Enum,visited);
		//取新的w邻接点
		w=NextNeighbor(G,v,w); 
	} 
}
