#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//������ÿk���ڵ����һ�η�ת
//Ҫ��¼ÿ�η�ת�����һ���ڵ㣬��Ϊ��ʹ��һ�η�ת�����ǰ���ڵ� 
ListNode* reverseKGroup(ListNode* head, int k) {
    //corner case����Ϊ�գ�k̫С
    if(!head || k<2) return head;
	//��ʼ��ͷ���
	ListNode dummy(0);
	dummy.next=head;
	//��ʼ������ָ��
	ListNode *p=&dummy;
	//��ʼ��ǰ��ָ��
	ListNode *pre=&dummy;
	//�����������нڵ㣬������ָ�����ʱ������
	while(p){
		//��ÿ�η�ת������һ���ڵ�Ĺ���ָ��p��Ϊ��һ�ֵ�����ǰ��ָ��
		pre=p;
		//������һ��k���ڵ�
		for(int i=0;i<k;i++){
			//ÿ������k�е�һ���ڵ㣬���ù���ָ��ָ������ڵ�
			p=p->next;
			//������ָ�벻����ʱ��˵���ڵ��Ѿ�����k���ˣ��޷���ת�ˣ���������������ͷ���
			if(!p) return dummy.next;
		}
		//����������k���ڵ㣬��ʱ����ָ��ָ��k���ڵ��е����һ���ڵ㣬ǰ��ָ��ָ��k���ڵ�ǰ���һ���ڵ㣬���÷�ת����
		p=reverse(pre,p->next);
	}
	//��������������ͷ��� 
	return dummy.next;
}
//������ת����������k���ڵ��ǰ���ڵ㣬k���ڵ�ĺ�̽ڵ�
ListNode *reverse(ListNode *pre,ListNode* end){
	//��ʼ������ָ��Ϊk���ڵ��еĵ�һ���ڵ�
	ListNode *p=pre->next;
	//������ָ��û���߳�k���ڵ�ʱ������
	while(p->next!=end){
		//�ݴ湤��ָ��ĺ�̽ڵ�
		ListNode *n=p->next;
		//�����̽ڵ�
		p->next=n->next;
		//������뵽��һ��λ��
		n->next=pre->next;
		pre->next=n;
	}
	//������ϣ�����ָ���ʱָ�����k���ڵ��е����һ���ڵ㣬����֮����Ϊ��һ��k���ڵ��ǰ���ڵ� 
	return p;
}


