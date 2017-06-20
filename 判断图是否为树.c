//�ж�����ͼ�Ƿ�Ϊ�� 
//������������n�������ͼ����n-1���ߵ���ͨͼ�����ǲ��ܳɻ���Ҫ��ͨ��������������������нڵ�ͱ߲��� 
bool isTree(Graph& G){
	//���ʱ�ǳ�ʼ����������Ϊδ���ʹ��� 
	for(i=1;i<=G.vexnum;i++) visited[i]=FALSE;
	//��ʼ���������ͱ���
	int Vnum=0,Enum=0;
	//DFS��˳��ͳ�Ʒ��ʹ��Ķ������ͱ���
	DFS(G,1,Vnum,Enum,visited);
	if(Vnum==G.vexnum && Enum==2*(G.vexnum-1)){
		//��������������
		return true; 
	} else {
		//������
		return false; 
	}
}
void DFS(Graph& G,int v,int &Vnum,int &Enum,int visited[]){
	//ÿ����һ���ڵ㣬���֮
	visited[v]=TRUE;
	//������+1
	Vnum++;
	//�Ƿ���ȡ���ڽӵ㣬֤���Ƿ���ͨ���Ƿ��бߣ�������ȡһ��
	int w=FirstNeighbor(G,v);
	//ȡ���ˣ��Ǳ������ݹ������ȡ
	while(w!=-1){
		Enum++;
		//���ڽӵ�δ�����ʹ����ݹ����֮ 
		if(!visited[w]) DFS(G,w,Vnum,Enum,visited);
		//ȡ�µ�w�ڽӵ�
		w=NextNeighbor(G,v,w); 
	} 
}
