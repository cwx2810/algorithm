#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//判断一个链表是否存在环
//设置双指针，一个每次走两步，一个每次走一步，如果追上了，显然存在环 
bool hasCycle(ListNode *head) {
    //corner case 头节点或真头节点为空
    if(head==NULL && head->next==NULL) return false;
	//初始化快指针
	ListNode *fast=head;
	//初始化慢指针
	ListNode *slow=head;
	//只要还有移动空间，就可以迭代移动
	while(fast->next!=NULL && fast->next->next!=NULL){
		//快指针移动两步
		fast=fast->next->next;
		//慢指针移动一步
		slow=slow->next;
		//如果快指针追上了慢指针，说明有环
		if(fast==slow) return true;
	}
	//没有移动空间了，快指针还没追上慢指针，说明没环 
	return false;
}
