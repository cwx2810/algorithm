#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//����������з֣�����һ��ֵ��ʹ��������߱����ֵС���ұߴ��ڵ������ֵ
//�ñ������뷨��Ū������������ԭ�����ֵ�����ʵĹ��ص���Ӧ���������Ѻ�һ��������ص�ǰһ�������� 
ListNode* partition(ListNode* head, int x) {
	//corner case ��������Ϊ�� 
	if(!head) return head;
    //��ʼ������ͷ��㣬��������ָ��
    ListNode dummy1(0),dummy2(0);
    ListNode *p1=&dummy1;
    ListNode *p2=&dummy2;
	//��ʼ����������Ĺ���ָ��
	ListNode *p=head;
	//�������������ʱ���������͸���x�Ƚ�
	while(p){
		//�����xС�����ص�p1���ƶ���������ָ�� 
		if(p->val<x){
			p1->next=p;
			p1=p1->next;
			p=p->next;
		}else{
			//��֮�����ص�p2���ƶ���������ָ��
			p2->next=p;
			p2=p2->next;
			p=p->next;
		}
	}
	//��һ�������β�ÿգ��������в������ǵ���p2��p1Ϊ�յ���� 
	p2->next=NULL;
	//���ص�ǰһ������
	p1->next=dummy2.next;
	//����ǰһ������
	return dummy1.next; 
}
