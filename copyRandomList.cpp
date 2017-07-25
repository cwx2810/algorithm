#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���һ������randomָ������� 
RandomListNode *copyRandomList(RandomListNode *head) {
    //corner case ��������Ϊ��
    if(!head) return NULL;
	//��ʼ��������ͷ���
	RandomListNode dummy(0);
	//����ָ��ָ��������ͷ���
	RandomListNode *p=&dummy;
	//��ʼ��ָ��ָ��������ͷ���
	RandomListNode *h=head; 
	//��ʼ����ϣ���¼ӳ���ϵ
	map<RandomListNode*,RandomListNode*> m;
	//����������Ԫ��ʱ����������ָ��
	while(h){
		//�����µ�������ڵ㱣���������Ԫ��
		RandomListNode *node=new RandomListNode(h->label);
		//�ӵ�ͷ������
		p->next=node;
		//�ƶ���������ָ�뵽�µı�β
		p=node;
		//����randomָ�뵽��������ʱ������ֻ������randomָ�� 
		node->random=h->random;
		//��¼ӳ���ϵ����ͨ����ϣ���еľɽڵ����ӳ�䵽�½ڵ� 
		m[h]=node;
		//�ƶ�������ָ��
		h=h->next;
	}
	//����������������ָ��û���ˣ��������ã���������ָ��ָ���������һ��Ԫ�� 
	h=dummy.next;
	//��ָ�����ʱ������������
	while(h){
		//����������randomָ����ڣ���ָ���ϣ���ﱣ���ӳ�䣬��ָ���½ڵ��random
		if(h->random) h->random=m[h->random]; 
		//�ƶ�ָ��
		h=h->next;
	}
	//����������ͷ��� 
	return dummy.next;
}
