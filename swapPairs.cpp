#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//������������Ԫ�أ�ֻ��Ҫ�õ�������ǰ���ڵ� 
ListNode* swapPairs(ListNode* head) {
    //corner case ����ͷ������ڵ�Ϊ�գ����ܽ���
    if(!head || !head->next) return head;
	//��ʼ��ͷ���͹���ָ��
	ListNode dummy(0);
	dummy.next=head;
	ListNode *p=&dummy;
	//������ָ��ָ���ǰ����ǰ������������ڵ㶼����ʱ�����Խ���
	while(p && p->next && p->next->next){
		//�ݴ�ǰ������������ڵ�
		ListNode *n=p->next;
		ListNode *nn=p->next->next;
		//ǰ�����ڶ����ڵ�
		p->next=nn;
		//��һ���ڵ�����̽ڵ�
		n->next=nn->next;
		//�ڶ����ڵ�����һ���ڵ�
		nn->next=n;
		//����ָ������ƶ����񣬵����µ�ǰ��
		p=p->next->next;
	}
	//ֱ��û�к����ڽ����ģ���������������ͷ��� 
	return dummy.next;
}
