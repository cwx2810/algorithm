#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�ж�һ�������Ƿ���ڻ����������Ŀ�ʼ�ڵ� 
//����˫ָ�룬һ��ÿ����������һ��ÿ����һ�������׷���ˣ���Ȼ���ڻ� 
//��ô��εõ����Ŀ�ʼ�ڵ㣿����ͼ���Կ����������Ŀ�ʼ�ڵ�һ���������غϵ���м� 
ListNode *detectCycle(ListNode *head) {
    //corner case ��������Ϊ��
    if(head==NULL || head->next==NULL) return NULL;
	//��ʼ������ָ��
	ListNode* fast=head;
	ListNode* slow=head;
	//ֻҪָ�뻹�пռ��ƶ�ȴû׷�ϣ�һֱ����
	while(fast->next!=NULL && fast->next->next!=NULL){
		//�ƶ�����ָ��
		fast=fast->next->next;
		slow=slow->next;
		//���׷���ˣ����л������Ŀ�ʼ�ڵ����м䣬���԰���ָ���ƻ�ȥ���ǹ���˫ָ�����м��� 
		if(fast==slow){
			//������ָ��Ϊ��ʼ�ڵ�
			slow=head;
			//ֻҪ����û����ͷ����һֱ���м�һ��һ���ƶ���Ѱ���е� 
			while(fast!=slow){
				fast=fast->next;
				slow=slow->next; 
			}
			//��ͷ�ˣ�������ָ����ָ��
			return slow;
		}
	} 
	//�������˶�û��׷�ϣ���û�л�
	return NULL; 
}
