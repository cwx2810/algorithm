#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//对链表进行切分，给定一个值，使得链表左边比这个值小，右边大于等于这个值
//用暴力的想法，弄两个链表，遍历原链表的值，合适的挂载到相应的链表，最后把后一个链表挂载到前一个链表即可 
ListNode* partition(ListNode* head, int x) {
	//corner case 给定链表为空 
	if(!head) return head;
    //初始化两个头结点，两个工作指针
    ListNode dummy1(0),dummy2(0);
    ListNode *p1=&dummy1;
    ListNode *p2=&dummy2;
	//初始化给定链表的工作指针
	ListNode *p=head;
	//当给定链表存在时，迭代，和给定x比较
	while(p){
		//如果比x小，挂载到p1，移动两个工作指针 
		if(p->val<x){
			p1->next=p;
			p1=p1->next;
			p=p->next;
		}else{
			//反之，挂载到p2，移动两个工作指针
			p2->next=p;
			p2=p2->next;
			p=p->next;
		}
	}
	//后一个链表表尾置空，下面三行操作考虑到了p2或p1为空的情况 
	p2->next=NULL;
	//挂载到前一个链表
	p1->next=dummy2.next;
	//返回前一个链表
	return dummy1.next; 
}
