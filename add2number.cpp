#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//����������������������������ӱ��һ�������򱣴���������
//���������ܽ�����λ����Ӧ�����Ͼ����м�Ķ���ɵ���������λ������۵����λҲ�������һ�����ϣ���ǰ���������� 
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	//��ʼ��ͷ���͹���ָ��
	ListNode dummy(0);
	ListNode *p=&dummy;
	//��ʼ���ݴ��λ�ı���
	int cn=0;
	//�������������ʱ������
	while(l1 || l2){
		//��ʼ�������ÿһλ��ֵ��Ҳ���ǽ�λ+�����������鵱ǰԪ�ص�ֵ
		int val=cn+(l1?l1->val:0)+(l2?l2->val:0);
		//�����һ����λ
		cn=val/10;
		//ȡ�࣬��ӽ��½�����ռ� 
		val=val%10;
		p->next=new ListNode(val);
		//�ƶ�ָ�뵽�µı�β
		p=p->next;
		//�ƶ���������ָ�룬��Ϊ��ȷ��һ��ʼ���������Ƿ���Ԫ�أ����Ҫ���һ��
		if(l1) l1=l1->next;
		if(l2) l2=l2->next; 
	}
	//������ɣ������λ���ж�Ľ�λ����ӵ���βҲ�������λ��
	if(cn!=0) p->next=new ListNode(cn);
	//��������
	return dummy.next; 
}
