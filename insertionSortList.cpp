#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//����Ĳ������� 
//����ǰn���ڵ����򣬰ѵ�n+1���ڵ������ʵ�λ�Ӽ��� 
ListNode* insertionSortList(ListNode* head) {
    //Corner case ����Ϊ�ջ�ֵ������
    if(!head || !head->next) return head;
	//��ʼ��ͷ��㡢����ָ�롢��ǰ�ڵ�ָ��
	ListNode dummy(0);
	ListNode *p=&dummy;
	ListNode *cur=head;
	//����ǰָ�����ʱ������
	while(cur){
		//ÿ�ν�p�ƶ���ͷ��㣬����ǰn������ڵ㣬Ѱ�Ҳ���λ��
		p=&dummy; 
		//ֱ���ҵ��׸��ȵ�ǰ�ڵ��Ľڵ㣬ֹͣ����������ָ�붨�������һ���ȵ�ǰ�ڵ�С�Ľڵ�
		while(p->next && p->next->val<=cur->val) p=p->next;
		//��ʱ�洢��һ���ȵ�ǰ�ڵ��Ľڵ�
		ListNode *n=p->next;
		//����ָ��������Ҫ����ĵ�ǰ�ڵ�
		p->next=cur;
		//�ƶ���ǰ�ڵ�ָ�뵽��һ���ڵ㣬��Ϊ���ϵ�ǰ�ڵ�ָ�뵽��һ���ڵ������Ҫ������
		cur=cur->next;
		//�����������ϣ�������ڵ������ݴ�ĵ�һ���Ȳ���ڵ��Ľڵ�
		p->next->next=n;
	}
	//��������������ͷ���
	return dummy.next; 
}
