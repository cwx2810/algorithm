#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//������ĺ�k���ڵ���ת��ǰ��ȥ
//�ȱ��������õ�������n��β�ڵ�λ�ӣ�ͨ��β�ڵ���������ɻ�������ǰn-k���ڵ㣬�Ͽ�����Ͽ�����һ���ڵ���Ǳ�ͷ 
ListNode* rotateRight(ListNode* head, int k) {
    //corner case�������ڻ������������ת
    if(!head || k==0) return head;
	//��ʼ��������
	int len=1;
	//��ʼ������ָ��
	ListNode *p=head;
	//������������
	while(p->next){
		p=p->next;
		len++;
	}
	//�������ɻ�
	p->next=head;
	//����ǰn-k���ڵ㣬ע��n-kҪȡ�ദ����Ϊk���ܴ���n
	for(int i=0;i<len-k%len;i++) p=p->next;
	//��ʼ���µı�ͷ
	head=p->next;
	//�Ͽ���
	p->next=NULL;
	//����ͷ��� 
	return head;
}
