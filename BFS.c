//�Ƿ���ڶ���i��ĳ��j��·�����ù�����ȱ���

//��ʼ���������
int visited[MAXSIZE]={0};
int Exist_Path_BFS(ALGraph G,int i,int j){
	//��ʼ������
	InitQueue(Q);
	//�������
	EnQueue(Q,i);
	//�����зǿգ������
	while(!IsEmpty(Q)){
		//�Ե�һ�εĽڵ���ϸ������֮��ĵݹ���� 
		//��ͷ������
		DeQueue(Q,u);
		//�����ѷ��ʱ��
		visited[u]=1; 
		//�ݹ�ʣ�µ��ڽӵ�
		for(p=FirstNeighbor(G,i);p;p=NextNeighbor(G,i,p)){
			//��������ڽӵ�
			k=p.adjvex;
			//�ҵ��� 
			if(k==j) return 1;
			//��ƥ�䣬kδ�����ʹ�������ӣ���������һ���ڽӵ���ز� 
			if(!visited[k]) EnQueue(Q,k); 
		} 
	} 
	//�����궼û�ҵ� 
	return 0;
} 
