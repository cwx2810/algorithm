#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//ɾ���������ظ�Ԫ�أ�����ˮ���ͬС�죬ֻ������������ظ��Ľڵ㱾��Ҳɾ��������Ҫ���һ��preָ���¼ǰ��Ľڵ�λ�� 
ListNode* deleteDuplicates(ListNode* head) {
    //corner case �����ڵ�Ϊ��
    if(!head) return NULL;
	//��ʼ��head��pre
	ListNode dummy(0);
	dummy.next=head;
	//��ʼ��pre
	ListNode *pre=&dummy;
	//��ʼ������ָ��
	ListNode *p=head;
	//��������һ���ڵ�ʱ������
	while(p && p->next){
		//������ظ���ͬʱ�ƶ�pre��p
		if(p->val!=p->next->val){
			pre=p;
			p=p->next;
		}else{
			//����ظ���������������ͼ���������ظ���
			//�ȱ���õ�ǰ�ڵ�����¸��ڵ㣬���ڱ���ʱ���ϱȽ�
			int cur=p->val;
			ListNode *n=p->next->next;
			//�����¸��ڵ����ʱ�����Ա���
			while(n){
				//������ظ��ˣ�������������ʱ�����¸��ڵ��ǵ�һ����ͬ�Ľڵ�
				if(n->val!=cur) break;
				//�����һֱ����
				n=n->next;
			}
			//�������Ժ���pre����һ��ֱ��ָ������е����¸��ڵ㣬����һ����ͬ�Ľڵ�
			pre->next=n; 
			//���õ�ǰ����ָ��Ϊ���¸��ڵ�
			p=n;
		}
	}
	//�����������������ز����ظ������� 
	return dummy.next;
}
