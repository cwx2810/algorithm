#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���������������ڵ�Ŀ�ʼ�ڵ� 
//˼·����A����Ľ�β���ӵ�B����Ŀ�ͷ�����û������û�й����ڵ㣬����л��������ÿ���ָ���һ�����ʼ����ǹ����ڵ�Ŀ�ʼ�ڵ� 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //corner case��������Ϊ��
    if(!headA || !headB) return NULL;
	//���ù���ָ���A�ı�ͷ��ʼ�ҵ���β
	ListNode* p=headA;
	while(p->next) p=p->next;
	//����β���ӵ�����B
	p->next=headB;
	//���ñ�βָ�뱣��A�ı�βλ�� 
	ListNode* r=p;
	//����ָ��ָ�ָ��A�ı�ͷ����������A�ı�ͷλ�� 
	p=headA;
	//Ϊ�˲��˷ѿռ䣬�����ı�A��ͷָ��ͼ���Ϊ��ָ�룬��B��ͷָ��ָ���A����ʾ��ָ�루��Ϊ��A�Ѿ����ӵ���B�ˣ����Բ��ùܱ�B�� 
	headB=headA;
	//����ָ�뻹�����ƶ�����һֱ�ƶ������һ�
	while(headB->next && headB->next->next){
		//�ֱ��ƶ�������ָ��
		headA=headA->next;
		headB=headB->next->next;
		//��׷���ˣ�˵���л�������ѭ��
		if(headA==headB) break;
	}
	//���������ͷ����ôû��
	if(!headA->next || !headB->next || !headB->next->next){
		//�Ͽ���β����B������
		r->next=NULL;
		//����
		return NULL;
	}
	//�����л���׷�ϵĵ����غϵ㣬����ָ���¼�ĵ��ǿ�ʼ�㣬˫ָ�����м��ƽ����е���ǻ�����ʼ�㣬Ҳ���ǹ����ڵ�Ŀ�ʼ��
	//��A��ͷָ�룬Ҳ������ָ�룬����ָ����ָ���¼��A�ı�ͷ
	headA=p;
	//������ָ�벻�غ�ʱ������
	while(headA!=headB){
		//һ���ƶ�һ��
		headA=headA->next;
		headB=headB->next;
	}
	//�����������Ͽ���β����B������
	r->next=NULL;
	//�����غϵ� 
	return headA;
}
