//Ѱ������������Ĺ����ڵ�
//˼·�������뵽�������������Ȼ��ϳ�Y�ͣ�ֻ�ǳ��ȿ��ܲ����
//ֻ��Ҫ������Ȳ�dist������������곤�Ȳ��������ͬʱ��y������֦Ѿ�����㿪ʼ����
//ֻҪһ��ȣ��Ǻ���Ͷ��ǹ����ڵ�
LinkList SearchCommon(LinkList L1,LinkList L2){
	int L1Length=Length(L1);//�㳤�� 
	int L2Length=Length(L2);
	LNode pLong,pShort;//�����α꣬�ֱ�����ָ������������������һ�ڵ� 
	int dist;//���Ȳ� 
	if(L1Length>L2Length){
		pLong=L1->next;//��ʼ��ָ�� 
		pShort=L2->next; 
		dist=L1length-L2Length;
	}else{
		pLong=L2->next;
		pShort=L1->next;
		dist=L2Length-L1Length;
	}
	while(dist--){
		pLong=pLong->next;//�ѳ����������Ĳ������Ĵ��� 
	}
	while(pLong!=NULL){
		if(pLong==pShort){//�ҵ���һ���Ľڵ� 
			return pLong;
		}else{ 
			pLong=pLong->next;//û�ҵ����������ֱ����һ��Ϊ�� 
			pShort=pShort->next;
		}
	}
	return NULL;//��û�ҵ� 
} 
