#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�ϲ������Ѿ�������������Ǵ�ˮ�� 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //��ʼ��dummy��Ϊͷ��� 
    ListNode dummy(0);
	//����ָ��ָ��dummy
	ListNode* p=&dummy;
	//��������������Ϊ��ʱ������
	while(l1 && l2){
		//�ĸ��ڵ�С���͹��أ�ͬʱ�ƶ�p����������������ͬʱ���������й��غ�Ľڵ�Ͳ�Ҫ�ˣ��ƶ����¸��ڵ�
		if(l1->val<l2->val){
			p->next=l1;
			p=l1;
			l1=l1->next;
		}else{
			p->next=l2;
			p=l2;
			l2=l2->next;
		}
	}
	//����ĸ�������ʣ�࣬�����ص����
	if(l1){
		p->next=l1;
	}else{
		p->next=l2;
	}
	//����ͷ���
	return dummy.next; 
}
