#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//判断一个链表是否存在环，给出环的开始节点 
//设置双指针，一个每次走两步，一个每次走一步，如果追上了，显然存在环 
//那么如何得到环的开始节点？画个图可以看出来，环的开始节点一定在起点和重合点的中间 
ListNode *detectCycle(ListNode *head) {
    //corner case 给定链表为空
    if(head==NULL || head->next==NULL) return NULL;
	//初始化快慢指针
	ListNode* fast=head;
	ListNode* slow=head;
	//只要指针还有空间移动却没追上，一直迭代
	while(fast->next!=NULL && fast->next->next!=NULL){
		//移动快慢指针
		fast=fast->next->next;
		slow=slow->next;
		//如果追上了，则有环，环的开始节点在中间，所以把慢指针移回去还是构成双指针往中间走 
		if(fast==slow){
			//设置慢指针为初始节点
			slow=head;
			//只要快慢没有碰头，就一直往中间一格一格移动，寻找中点 
			while(fast!=slow){
				fast=fast->next;
				slow=slow->next; 
			}
			//碰头了，返回慢指针或快指针
			return slow;
		}
	} 
	//迭代完了都没有追上，则没有环
	return NULL; 
}
