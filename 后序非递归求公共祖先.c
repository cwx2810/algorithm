//后序遍历非递归算法求两个节点最近的公共祖先 
//上一次做的一样的题是把两个节点的位子直接给出了，因此用除二算祖先的方法方便省事
//这次pq任意指向两个节点，因此要先遍历找到pq，p在q前面，因此找到p时将p的栈复制一份，继续找q
//找到q后此时栈中和刚才复制的辅助栈中分别是q和p的祖先元素，这时从栈顶开始比较，第一个匹配的就是最近的祖先
typedef struct{
	BiTree t;
	int tag;
}stack; 
//上面先定义类型，下面初始化两个栈
stack s[],s1[]; 
BiTree Ancestor(BiTree root,BiTNode *p,BiTNode *q){
	//初始化栈指针，树节点指针
	top=0,bt=root;
	//还是该算法同样的套路，只要节点有孩子，或者节点孩子消耗光了但是栈中有元素，就迭代
	while(bt!=NULL||top>0){
		//一路向左入栈
		while(bt!=NULL&&bt!=p&&bt!=q){
			//这里再放一个内循环意在在循坏里面解决节点直接一通到底，不参与外面大循环 
			while(bt!=NULL){
				s[++top].t=bt;
				s[top].tag=0;
				bt=bt->lchild;
			}
		} 
		//同样这里先跳过，执行下一个while，即向右一通到底，再回来执行主算法
		//当左右都走到底了
		while(top!=0&&s[top].tag=1){
			//假定p在q的左侧，先找到p，复制栈
			if(s[top].t==p){
				for(i=1;i<=top;i++){
					s1[i]=s[i];
					top1=top;
				}
			} 
			//继续找，找到q
			if(s[top].t==q){
				//两个栈向匹配，本栈是大栈，在外面，复制栈使小栈，在里面
				for(i=top;i>0;i--){
					for(j=top1;j>0;j--){
						//遍历到第一个相等的就是最近的祖先
						if(s1[j].t==s[i].t) return s[i].t; 
					}
				}
				//退栈 
				top--;
			} 
		} 
		//当左边走到底了，节点没有孩子，但栈不为空，这时退一步往右边找
		while(top!=0){
			s[top].tag=1;
			bt=s[top].t->rchild;
		} 
	} 
}
