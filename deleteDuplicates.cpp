#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//ɾ���������ظ�Ԫ�أ�LeetCode�о�Ȼ������ˮ�⡭�� 
ListNode* deleteDuplicates(ListNode* head) {
    //corner case ���������
    if(!head) return NULL;
	//��ʼ��int�������������������Ԫ��ֵ
	int cur=head->val;
	//��ʼ������ָ��
	ListNode* p=head;
	//��p����������ʱ������
	while(p && p->next){
		//�����һ���ڵ�ֵ�͵�ǰ�����
		if(cur!=p->next->val){
			//�ı�int����Ϊ��һ���ڵ�ֵ
			cur=p->next->val;
			//�ƶ�����ָ��
			p=p->next;
		}else{
			//����ɾ����һ���ڵ�
			p->next=p->next->next;
		}
	}
	//������ɣ����ز����ظ�Ԫ�ص�����
	return head; 
}
