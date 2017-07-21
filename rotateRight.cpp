#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//将链表的后k个节点轮转到前面去
//先遍历链表，得到链表长度n和尾节点位子，通过尾节点把链表连成环，遍历前n-k个节点，断开，则断开的下一个节点就是表头 
ListNode* rotateRight(ListNode* head, int k) {
    //corner case链表不存在或给定数不用轮转
    if(!head || k==0) return head;
	//初始化链表长度
	int len=1;
	//初始化工作指针
	ListNode *p=head;
	//遍历出链表长度
	while(p->next){
		p=p->next;
		len++;
	}
	//将链表变成环
	p->next=head;
	//迭代前n-k个节点，注意n-k要取余处理，因为k可能大于n
	for(int i=0;i<len-k%len;i++) p=p->next;
	//初始化新的表头
	head=p->next;
	//断开环
	p->next=NULL;
	//返回头结点 
	return head;
}
