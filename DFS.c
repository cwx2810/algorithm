//�Ƿ���ڶ���i��ĳ��j��·������������ȱ���

//��ʼ�����ʱ��
int visited[MAXSIZE]={0};
int Exit_Path_DFS(ALGraph G,int i,int j){
	//��ʼ���ڵ����
	int p;
	//corner case Ҫ���j���Ƕ���
	if(i==j){
		return 1;
	} else{
		//���õ�һ���ڵ���ʱ��
		visited[i]=1;
		//�ݹ��������ڽӵ�
		for(p=FirstNeighbor(G,i);p>=0;p=NextNeighbor(G,i,p)){
			//����ڵ�û�з��ʹ����ҿ�����������������������ҵ�·��
			if(!visited[k]&&Exist_Path_DFS(G,p,j)) return 1; 
		} 
	}
	//�Ҳ��� 
	return 0;
}
