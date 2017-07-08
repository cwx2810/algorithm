#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�ж�һ�������Ƿ���ڻ�
//����˫ָ�룬һ��ÿ����������һ��ÿ����һ�������׷���ˣ���Ȼ���ڻ� 
bool hasCycle(ListNode *head) {
    //corner case ͷ�ڵ����ͷ�ڵ�Ϊ��
    if(head==NULL && head->next==NULL) return false;
	//��ʼ����ָ��
	ListNode *fast=head;
	//��ʼ����ָ��
	ListNode *slow=head;
	//ֻҪ�����ƶ��ռ䣬�Ϳ��Ե����ƶ�
	while(fast->next!=NULL && fast->next->next!=NULL){
		//��ָ���ƶ�����
		fast=fast->next->next;
		//��ָ���ƶ�һ��
		slow=slow->next;
		//�����ָ��׷������ָ�룬˵���л�
		if(fast==slow) return true;
	}
	//û���ƶ��ռ��ˣ���ָ�뻹û׷����ָ�룬˵��û�� 
	return false;
}
