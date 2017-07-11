#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//返回两个链表公共节点的开始节点 
//思路：将A链表的结尾连接到B链表的开头，如果没环，则没有公共节点，如果有环，则设置快慢指针找环的起始点就是公共节点的开始节点 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //corner case给定链表为空
    if(!headA || !headB) return NULL;
	//设置工作指针从A的表头开始找到表尾
	ListNode* p=headA;
	while(p->next) p=p->next;
	//将表尾连接到链表B
	p->next=headB;
	//设置表尾指针保存A的表尾位子 
	ListNode* r=p;
	//工作指针恢复指向A的表头，保存链表A的表头位子 
	p=headA;
	//为了不浪费空间，给定的表A的头指针就假设为慢指针，表B的头指针指向表A，表示快指针（因为表A已经连接到表B了，所以不用管表B） 
	headB=headA;
	//当快指针还可以移动，就一直移动迭代找环
	while(headB->next && headB->next->next){
		//分别移动慢、快指针
		headA=headA->next;
		headB=headB->next->next;
		//当追上了，说明有环，跳出循环
		if(headA==headB) break;
	}
	//如果迭代到头，那么没环
	if(!headA->next || !headB->next || !headB->next->next){
		//断开表尾到表B的连接
		r->next=NULL;
		//返回
		return NULL;
	}
	//否则有环，追上的点是重合点，工作指针记录的点是开始点，双指针向中间推进找中点就是环的起始点，也就是公共节点的开始点
	//表A的头指针，也就是慢指针，重新指向工作指针记录的A的表头
	headA=p;
	//当快慢指针不重合时，迭代
	while(headA!=headB){
		//一次移动一格
		headA=headA->next;
		headB=headB->next;
	}
	//迭代结束，断开表尾到表B的连接
	r->next=NULL;
	//返回重合点 
	return headA;
}
