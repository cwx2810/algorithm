#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//删除链表中重复元素，LeetCode中居然有这种水题…… 
ListNode* deleteDuplicates(ListNode* head) {
    //corner case 给定链表空
    if(!head) return NULL;
	//初始化int变量保存遍历到的链表元素值
	int cur=head->val;
	//初始化工作指针
	ListNode* p=head;
	//当p还能往下走时，迭代
	while(p && p->next){
		//如果下一个节点值和当前不相等
		if(cur!=p->next->val){
			//改变int变量为下一个节点值
			cur=p->next->val;
			//移动工作指针
			p=p->next;
		}else{
			//否则，删除下一个节点
			p->next=p->next->next;
		}
	}
	//迭代完成，返回不含重复元素的链表
	return head; 
}
