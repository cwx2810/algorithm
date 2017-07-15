#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//合并k个已排序的数组，先两两合并，中间间隔一半长度，然后再将已经合并的两两合并 
ListNode* mergeKLists(vector<ListNode*>& lists) {
    //Corner case 给定数组为空
    if(lists.empty()) return NULL;
	//初始化变量n表示数组长度
	int n=lists.size();
	//当n>2，即需要合并时，迭代
	while(n>=2){
		//初始化k为一半的位子的下标 
		int k=(n+1)/2;
		//迭代前一半元素，调用合并方法，合并前一半和后一半的元素，中间始终间隔k，合并的结果赋给前一半元素
		for(int i=0;i<n/2;i++) lists[i]=merge(lists[i],lists[i+k]);
		//下一个循环只用迭代前一半元素，继续合并
		n=k;
	}
	//最终都合并到了数组第一个元素，返回之
	return lists[0]; 
}
//构建合并方法，传入两个链表
ListNode *merge(ListNode *n1,ListNode *n2){
	//初始化头结点和工作指针
	ListNode dummy(0);
	ListNode *p=&dummy;
	//当链表存在时，迭代
	while(n1 && n2){
		//比较看链表哪个值小，就挂载，同时移动两个指针
		if(n1->val<n2->val){
			p->next=n1;
			p=n1;
			n1=n1->next;
		}else{
			p->next=n2;
			p=n2;
			n2=n2->next;
		}	
	}
	//若哪个链表还有剩余，挂载之
	if(n1){
		p->next=n1;
	}else{
		p->next=n2;
	}
	//返回头结点，即已经合并好的链表
	return dummy.next;
}

