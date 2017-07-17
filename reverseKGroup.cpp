#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//对链表每k个节点进行一次翻转
//要记录每次翻转的最后一个节点，因为它使下一次翻转链表的前驱节点 
ListNode* reverseKGroup(ListNode* head, int k) {
    //corner case链表为空，k太小
    if(!head || k<2) return head;
	//初始化头结点
	ListNode dummy(0);
	dummy.next=head;
	//初始化工作指针
	ListNode *p=&dummy;
	//初始化前驱指针
	ListNode *pre=&dummy;
	//遍历链表所有节点，当工作指针存在时，迭代
	while(p){
		//将每次翻转完的最后一个节点的工作指针p作为新一轮迭代的前驱指针
		pre=p;
		//迭代新一轮k个节点
		for(int i=0;i<k;i++){
			//每迭代到k中的一个节点，就让工作指针指向这个节点
			p=p->next;
			//当工作指针不存在时，说明节点已经不够k个了，无法翻转了，遍历结束，返回头结点
			if(!p) return dummy.next;
		}
		//遍历完所有k个节点，此时工作指针指向k个节点中的最后一个节点，前驱指针指向k个节点前面的一个节点，调用翻转方法
		p=reverse(pre,p->next);
	}
	//遍历结束，返回头结点 
	return dummy.next;
}
//创建翻转方法，传入k个节点的前驱节点，k个节点的后继节点
ListNode *reverse(ListNode *pre,ListNode* end){
	//初始化工作指针为k个节点中的第一个节点
	ListNode *p=pre->next;
	//当工作指针没有走出k个节点时，迭代
	while(p->next!=end){
		//暂存工作指针的后继节点
		ListNode *n=p->next;
		//隔离后继节点
		p->next=n->next;
		//将其插入到第一个位子
		n->next=pre->next;
		pre->next=n;
	}
	//迭代完毕，工作指针此时指向的是k个节点中的最后一个节点，返回之，作为下一轮k个节点的前驱节点 
	return p;
}


