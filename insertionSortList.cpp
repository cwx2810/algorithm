#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//链表的插入排序 
//假设前n个节点有序，把地n+1个节点插入合适的位子即可 
ListNode* insertionSortList(ListNode* head) {
    //Corner case 链表为空或不值得排序
    if(!head || !head->next) return head;
	//初始化头结点、工作指针、当前节点指针
	ListNode dummy(0);
	ListNode *p=&dummy;
	ListNode *cur=head;
	//当当前指针存在时，迭代
	while(cur){
		//每次将p移动到头结点，迭代前n个有序节点，寻找插入位子
		p=&dummy; 
		//直到找到首个比当前节点大的节点，停止迭代，工作指针定格于最后一个比当前节点小的节点
		while(p->next && p->next->val<=cur->val) p=p->next;
		//临时存储第一个比当前节点大的节点
		ListNode *n=p->next;
		//工作指针连接上要插入的当前节点
		p->next=cur;
		//移动当前节点指针到下一个节点，因为马上当前节点指针到下一个节点那里就要断链了
		cur=cur->next;
		//将那里连接上，即插入节点连接暂存的第一个比插入节点大的节点
		p->next->next=n;
	}
	//迭代结束，返回头结点
	return dummy.next; 
}
