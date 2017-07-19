#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//对链表排序，用分治的思想 
ListNode* sortList(ListNode* head) {
    //corner case 链表不存在或不值得排序
    if(!head || !head->next) return head;
	//初始化快慢指针
	ListNode *fast=head;
	ListNode *slow=head;
	//通过快慢指针得到中间点
	while(fast->next && fast->next->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	//将链表拆成两半，fast记录后一半头结点
	fast=slow->next;
	//砍掉slow后面
	slow->next=NULL;
	//调用合并函数和排序函数对左右两边分别排序
	return merge(sortList(head),sortList(fast)); 
}
//构建合并函数，传入两个链表
ListNode *merge(ListNode *l1,ListNode* l2){
	//corner case一个链表不存在或都不存在
	if(!l1){
		return l2;
	}else if(!l2){
		return l1;
	}else if(!l1 && !l2){
		return NULL;
	}
	//初始化头结点和工作指针
	ListNode dummy(0);
	ListNode *p=&dummy;
	//当两个链表都存在时，迭代
	while(l1 && l2){
		//哪边元素小就挂载哪边的元素，同时移动两个指针
		if(l1->val<l2->val){
			p->next=l1;
			l1=l1->next;
			p=p->next;
		}else{
			p->next=l2;
			l2=l2->next;
			p=p->next;
		}
		//最后剩下某个链表，直接挂载到后面
		if(l1){
			p->next=l1;
		}else{
			p->next=l2;
		}
	}
	//返回头结点
	return dummy.next; 
}
