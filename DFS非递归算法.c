//DFS�ǵݹ��㷨
//��Ȼ�ǵݹ飬��Ҫ�õ�ջS�����Ѿ����ʹ��Ľڵ㣬���ñ��visited����Ƿ�������ջ������˾Ͳ��ýڵ�������
void DFS_Non_RC(AGraph& G,int v){
	//��ʼ������
	int w;
	//��ʼ��ջ
	InitStack(S);
	//��ʼ��visited����FALSE
	for(i=0;i<G.vexnum;i++) visited[i]=FALSE;
	//������ջ
	Push(s,v);
	visited[v]=TRUE;
	//����
	while(!IsEmpty(S)){
		//�Ե�һ���ڵ�ֽ�������˳�ջ��Ԫ�أ����ʡ�����֮��Ľڵ㶼�ݹ� 
		k=Pop(S);
		visit(k);
		//�ݹ飬��֮��Ľڵ����ջ�����ʡ���� 
		//��Ϊ��ջ�����ԴӴ�С�������Ҷ˵���˽��еݹ飬ȡ��ʱ��պ�������� 
		for(w=FirstNeighbor(G,k);w>=0;w=NextNeighbor(G,k,w)){
			//�����һ���ڵ㻹û�б����ʣ���ѹջ����� 
			if(!visited[w]){
				Push(S,w);
				visited[w]=TRUE;
			}
		} 
	} 
} 
