//寻找两个单链表的公共节点
//思路：不难想到，这两个链表必然组合成Y型，只是长度可能不相等
//只需要算出长度差dist，长链表遍历完长度差，两个链表同时从y的两个枝丫顶部点开始遍历
//只要一相等，那后面就都是公共节点
LinkList SearchCommon(LinkList L1,LinkList L2){
	int L1Length=Length(L1);//算长度 
	int L2Length=Length(L2);
	LNode pLong,pShort;//两个游标，分别用来指向两个长短链表的真第一节点 
	int dist;//长度差 
	if(L1Length>L2Length){
		pLong=L1->next;//初始化指针 
		pShort=L2->next; 
		dist=L1length-L2Length;
	}else{
		pLong=L2->next;
		pShort=L1->next;
		dist=L2Length-L1Length;
	}
	while(dist--){
		pLong=pLong->next;//把长链表多出来的部分消耗殆尽 
	}
	while(pLong!=NULL){
		if(pLong==pShort){//找到了一样的节点 
			return pLong;
		}else{ 
			pLong=pLong->next;//没找到往后遍历，直到下一个为空 
			pShort=pShort->next;
		}
	}
	return NULL;//真没找到 
} 
