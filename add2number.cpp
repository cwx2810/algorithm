#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//将两个链表看成两个数，把它们相加变成一个数倒序保存在链表中
//分析：不管进多少位，反应到数上就是中间的都变成单个数，进位都会积累到最高位也就是最后一个数上，提前保存他即可 
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	//初始化头结点和工作指针
	ListNode dummy(0);
	ListNode *p=&dummy;
	//初始化暂存进位的变量
	int cn=0;
	//当两个链表存在时，迭代
	while(l1 || l2){
		//初始化算出的每一位的值，也就是进位+两个给定数组当前元素的值
		int val=cn+(l1?l1->val:0)+(l2?l2->val:0);
		//算出下一个进位
		cn=val/10;
		//取余，添加进新建链表空间 
		val=val%10;
		p->next=new ListNode(val);
		//移动指针到新的表尾
		p=p->next;
		//移动给定链表指针，因为不确定一开始两个链表是否都有元素，因此要如果一下
		if(l1) l1=l1->next;
		if(l2) l2=l2->next; 
	}
	//迭代完成，处理进位，有多的进位就添加到表尾也就是最高位上
	if(cn!=0) p->next=new ListNode(cn);
	//返回链表
	return dummy.next; 
}
