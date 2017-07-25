#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//深拷贝一个带有random指针的链表 
RandomListNode *copyRandomList(RandomListNode *head) {
    //corner case 给定链表为空
    if(!head) return NULL;
	//初始化新链表头结点
	RandomListNode dummy(0);
	//工作指针指向新链表头结点
	RandomListNode *p=&dummy;
	//初始化指针指向老链表头结点
	RandomListNode *h=head; 
	//初始化哈希表记录映射关系
	map<RandomListNode*,RandomListNode*> m;
	//当老链表还有元素时，迭代链表指针
	while(h){
		//建立新的新链表节点保存老链表的元素
		RandomListNode *node=new RandomListNode(h->label);
		//接到头结点后面
		p->next=node;
		//移动新链表工作指针到新的表尾
		p=node;
		//拷贝random指针到新链表，此时新链表只是有了random指针 
		node->random=h->random;
		//记录映射关系，即通过哈希表中的旧节点可以映射到新节点 
		m[h]=node;
		//移动老链表指针
		h=h->next;
	}
	//迭代结束，老链表指针没用了，废物利用，令老链表指针指向新链表第一个元素 
	h=dummy.next;
	//当指针存在时，迭代新链表
	while(h){
		//如果新链表的random指针存在，则指向哈希表里保存的映射，即指向新节点的random
		if(h->random) h->random=m[h->random]; 
		//移动指针
		h=h->next;
	}
	//返回新链表头结点 
	return dummy.next;
}
