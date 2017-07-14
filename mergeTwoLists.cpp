#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//合并两个已经排序的链表，又是大水题 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //初始化dummy作为头结点 
    ListNode dummy(0);
	//工作指针指向dummy
	ListNode* p=&dummy;
	//当给定两个链表不为空时，迭代
	while(l1 && l2){
		//哪个节点小，就挂载，同时移动p到挂载完的链表最后，同时给定链表中挂载后的节点就不要了，移动到下个节点
		if(l1->val<l2->val){
			p->next=l1;
			p=l1;
			l1=l1->next;
		}else{
			p->next=l2;
			p=l2;
			l2=l2->next;
		}
	}
	//最后哪个链表有剩余，都挂载到最后
	if(l1){
		p->next=l1;
	}else{
		p->next=l2;
	}
	//返回头结点
	return dummy.next; 
}
