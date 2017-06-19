//寻找节点p在线索二叉树后序遍历的前驱
//分三种情况，一是p有左右孩子，则孩子是他的前驱
//二是p没有孩子，如果有左兄弟，则左兄弟是前驱，没有左兄弟，找祖先的第一个遇到的做兄弟做前驱
//三是p是根节点或单支树，则他无论如何没有前驱
BiThrTree InPostPre(BiThrTree t,BiThrTree p){
	//初始化前驱节点 
	BiThrTree q;
	//p有右孩子，优先考虑 
	if(p->rtag==0){
		q=p->rchild;
	} else if(p->ltag==0){//其次考虑p有左孩子 
		q=p->lchild;
	} else if(p->lchild==NULL){//p连左孩子都没有，孤寡老人 
		q=NULL;
	}else{
		//没有孩子又不是根节点，找祖先的左孩子当前驱咯
		//顺着祖先的线索顺藤摸瓜往上走
		while(p->ltag==1&&p->lchild!=NULL){
			p=p->lchild;
		} 
		if(p->ltag==0){
			//找到瓜啦，有一个祖先有左孩子
			q=p->lchild; 
		}else {
			//摸到顶了还没有祖先有左孩子，说明最底下那个孩子是个孤儿，仅有单支树，无前驱
			q=NULL; 
		}
	}
	return q;
} 
