#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//������֡���ת�ұߡ��ٺϲ� 
void reorderList(ListNode* head) {
    //corner case û�л�ֻ��һ���ڵ�
    if(!head || !head->next) return;
	//��ʼ������ָ��
	ListNode *fast=head;
	ListNode *slow=head;
	//����ָ��ͬʱ�𲽣���ָ���ߵ��м�
	while(fast->next && fast->next->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	//��ʼ����ָ��Ϊ��������ͷ���
	fast=slow->next;
	//�е��������
	slow->next=NULL;
	//��ת���������ʱ��ָ�루��Ϊ����ָ�룩ָ���һ���ڵ㣬��Ҫͷ��㣬��ʼ��֮�������ӵ���һ���ڵ�
	ListNode dummy(0);
	dummy.next=fast; 
	//����ָ�����һ���ڵ����ʱ�����������õ������һ���ڵ㲻��ת�����룬��ת��ζ�ŵ�һ���ڵ㵽������������ģ�
	while(fast->next){
		//��¼����ָ��ĺ�̽ڵ�
		ListNode *n=fast->next;
		//�����̽ڵ�
		fast->next=n->next;
		//������뵽��һ��λ��
		n->next=dummy.next;
		dummy.next=n;
	}
	//������ϣ����³�ʼ����ָ��Ϊǰ������ͷ��㣬��ָ��Ϊ�������ͷ���
	slow=head;
	fast=dummy.next;
	//ǰ��ÿ���ڵ����κϲ���������ָ�����ʱ
	while(slow){
		if(fast){
			//�ݴ�ǰ��ͺ������ĵڶ����ڵ�
			ListNode *n=slow->next;
			ListNode *nn=fast->next;
			//ǰ���һ��������һ��
			slow->next=fast;
			//����һ����ǰ��ڶ���
			fast->next=n;
			//�ƶ�����ָ�뵽�ݴ�ָ���ϣ������ϲ�
			slow=n;
			fast=nn;
		}else{
			//�����˳� 
			break;
		}
	}
}
