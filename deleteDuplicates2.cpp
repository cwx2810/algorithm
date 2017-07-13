#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//删除链表中重复元素，和最水题大同小异，只不过这次连带重复的节点本身也删除，所以要设计一个pre指针记录前面的节点位子 
ListNode* deleteDuplicates(ListNode* head) {
    //corner case 给定节点为空
    if(!head) return NULL;
	//初始化head的pre
	ListNode dummy(0);
	dummy.next=head;
	//初始化pre
	ListNode *pre=&dummy;
	//初始化工作指针
	ListNode *p=head;
	//当存在下一个节点时，遍历
	while(p && p->next){
		//如果不重复，同时移动pre和p
		if(p->val!=p->next->val){
			pre=p;
			p=p->next;
		}else{
			//如果重复，继续遍历，试图跳过所有重复的
			//先保存好当前节点和下下个节点，用于遍历时不断比较
			int cur=p->val;
			ListNode *n=p->next->next;
			//当下下个节点存在时，可以遍历
			while(n){
				//如果不重复了，跳出迭代，此时的下下个节点是第一个不同的节点
				if(n->val!=cur) break;
				//否则就一直迭代
				n=n->next;
			}
			//跳出来以后让pre的下一个直接指向迭代中的下下个节点，即第一个不同的节点
			pre->next=n; 
			//重置当前工作指针为下下个节点
			p=n;
		}
	}
	//整个遍历结束，返回不带重复的链表 
	return dummy.next;
}
