#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//翻转链表中m~n之间的元素
//链表翻转的通用做法是将后面的元素依次挂载到第一个的元素的前驱后面，因此我们要遍历链表得到前一个元素的前驱 
ListNode* reverseBetween(ListNode* head, int m, int n) {
    //corner case 给定链表为空
    if(!head) return NULL;
	//初始化链表头结点
	ListNode dummy(0);
	dummy.next=head;
	//初始化工作指针
	ListNode* p=&dummy;
	//遍历m之前的链表节点，使工作指针指向m的前驱
	for(int i=1;i<m;i++) p=p->next;
	//初始化指针指向m
	ListNode* pm=p->next;
	//遍历m~n的元素
	for(int i=m;i<n;i++){
		//初始化指针暂存m的后继，把m后继插入第一个m的前驱后面，每次迭代移动m指针
		ListNode *n=pm->next;
		//把m的后继节点隔离掉
		pm->next=n->next;
		//m的后继节点接到第一个元素前驱后面，因为隔离断链了，因此用到暂存的指针
		n->next=p->next;
		p->next=n;
	}
	//迭代翻转完成，返回头结点 
	return dummy.next;
}

