#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//链表二分、反转右边、再合并 
void reorderList(ListNode* head) {
    //corner case 没有或只有一个节点
    if(!head || !head->next) return;
	//初始化快慢指针
	ListNode *fast=head;
	ListNode *slow=head;
	//快慢指针同时起步，慢指针走到中间
	while(fast->next && fast->next->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	//初始化快指针为后半链表的头结点
	fast=slow->next;
	//切掉后半链表
	slow->next=NULL;
	//反转后半链表，此时快指针（视为工作指针）指向第一个节点，需要头结点，初始化之，并连接到第一个节点
	ListNode dummy(0);
	dummy.next=fast; 
	//当快指针的下一个节点存在时，迭代（不用担心最后一个节点不翻转，你想，翻转意味着第一个节点到了最后，是正常的）
	while(fast->next){
		//记录工作指针的后继节点
		ListNode *n=fast->next;
		//隔离后继节点
		fast->next=n->next;
		//将其插入到第一个位子
		n->next=dummy.next;
		dummy.next=n;
	}
	//迭代完毕，重新初始化慢指针为前半链表头结点，快指针为后半链表头结点
	slow=head;
	fast=dummy.next;
	//前后每个节点依次合并，当快慢指针存在时
	while(slow){
		if(fast){
			//暂存前半和后半链表的第二个节点
			ListNode *n=slow->next;
			ListNode *nn=fast->next;
			//前半第一个连后半第一个
			slow->next=fast;
			//后半第一个连前半第二个
			fast->next=n;
			//移动快慢指针到暂存指针上，继续合并
			slow=n;
			fast=nn;
		}else{
			//否则，退出 
			break;
		}
	}
}
