#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�����������÷��ε�˼�� 
ListNode* sortList(ListNode* head) {
    //corner case �������ڻ�ֵ������
    if(!head || !head->next) return head;
	//��ʼ������ָ��
	ListNode *fast=head;
	ListNode *slow=head;
	//ͨ������ָ��õ��м��
	while(fast->next && fast->next->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	//�����������룬fast��¼��һ��ͷ���
	fast=slow->next;
	//����slow����
	slow->next=NULL;
	//���úϲ����������������������߷ֱ�����
	return merge(sortList(head),sortList(fast)); 
}
//�����ϲ�������������������
ListNode *merge(ListNode *l1,ListNode* l2){
	//corner caseһ���������ڻ򶼲�����
	if(!l1){
		return l2;
	}else if(!l2){
		return l1;
	}else if(!l1 && !l2){
		return NULL;
	}
	//��ʼ��ͷ���͹���ָ��
	ListNode dummy(0);
	ListNode *p=&dummy;
	//��������������ʱ������
	while(l1 && l2){
		//�ı�Ԫ��С�͹����ıߵ�Ԫ�أ�ͬʱ�ƶ�����ָ��
		if(l1->val<l2->val){
			p->next=l1;
			l1=l1->next;
			p=p->next;
		}else{
			p->next=l2;
			l2=l2->next;
			p=p->next;
		}
		//���ʣ��ĳ������ֱ�ӹ��ص�����
		if(l1){
			p->next=l1;
		}else{
			p->next=l2;
		}
	}
	//����ͷ���
	return dummy.next; 
}
