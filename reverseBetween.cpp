#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��ת������m~n֮���Ԫ��
//����ת��ͨ�������ǽ������Ԫ�����ι��ص���һ����Ԫ�ص�ǰ�����棬�������Ҫ��������õ�ǰһ��Ԫ�ص�ǰ�� 
ListNode* reverseBetween(ListNode* head, int m, int n) {
    //corner case ��������Ϊ��
    if(!head) return NULL;
	//��ʼ������ͷ���
	ListNode dummy(0);
	dummy.next=head;
	//��ʼ������ָ��
	ListNode* p=&dummy;
	//����m֮ǰ������ڵ㣬ʹ����ָ��ָ��m��ǰ��
	for(int i=1;i<m;i++) p=p->next;
	//��ʼ��ָ��ָ��m
	ListNode* pm=p->next;
	//����m~n��Ԫ��
	for(int i=m;i<n;i++){
		//��ʼ��ָ���ݴ�m�ĺ�̣���m��̲����һ��m��ǰ�����棬ÿ�ε����ƶ�mָ��
		ListNode *n=pm->next;
		//��m�ĺ�̽ڵ�����
		pm->next=n->next;
		//m�ĺ�̽ڵ�ӵ���һ��Ԫ��ǰ�����棬��Ϊ��������ˣ�����õ��ݴ��ָ��
		n->next=p->next;
		p->next=n;
	}
	//������ת��ɣ�����ͷ��� 
	return dummy.next;
}

