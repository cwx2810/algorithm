#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//两两交换链表元素，只需要拿到交换的前驱节点 
ListNode* swapPairs(ListNode* head) {
    //corner case 链表头结点或二节点为空，不能交换
    if(!head || !head->next) return head;
	//初始化头结点和工作指针
	ListNode dummy(0);
	dummy.next=head;
	ListNode *p=&dummy;
	//当工作指针指向的前驱和前驱后面的两个节点都存在时，可以交换
	while(p && p->next && p->next->next){
		//暂存前驱后面的两个节点
		ListNode *n=p->next;
		ListNode *nn=p->next->next;
		//前驱连第二个节点
		p->next=nn;
		//第一个节点连后继节点
		n->next=nn->next;
		//第二个节点连第一个节点
		nn->next=n;
		//工作指针向后移动两格，到达新的前驱
		p=p->next->next;
	}
	//直到没有和用于交换的，迭代结束，返回头结点 
	return dummy.next;
}
