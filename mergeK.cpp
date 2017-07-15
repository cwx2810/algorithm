#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�ϲ�k������������飬�������ϲ����м���һ�볤�ȣ�Ȼ���ٽ��Ѿ��ϲ��������ϲ� 
ListNode* mergeKLists(vector<ListNode*>& lists) {
    //Corner case ��������Ϊ��
    if(lists.empty()) return NULL;
	//��ʼ������n��ʾ���鳤��
	int n=lists.size();
	//��n>2������Ҫ�ϲ�ʱ������
	while(n>=2){
		//��ʼ��kΪһ���λ�ӵ��±� 
		int k=(n+1)/2;
		//����ǰһ��Ԫ�أ����úϲ��������ϲ�ǰһ��ͺ�һ���Ԫ�أ��м�ʼ�ռ��k���ϲ��Ľ������ǰһ��Ԫ��
		for(int i=0;i<n/2;i++) lists[i]=merge(lists[i],lists[i+k]);
		//��һ��ѭ��ֻ�õ���ǰһ��Ԫ�أ������ϲ�
		n=k;
	}
	//���ն��ϲ����������һ��Ԫ�أ�����֮
	return lists[0]; 
}
//�����ϲ�������������������
ListNode *merge(ListNode *n1,ListNode *n2){
	//��ʼ��ͷ���͹���ָ��
	ListNode dummy(0);
	ListNode *p=&dummy;
	//���������ʱ������
	while(n1 && n2){
		//�ȽϿ������ĸ�ֵС���͹��أ�ͬʱ�ƶ�����ָ��
		if(n1->val<n2->val){
			p->next=n1;
			p=n1;
			n1=n1->next;
		}else{
			p->next=n2;
			p=n2;
			n2=n2->next;
		}	
	}
	//���ĸ�������ʣ�࣬����֮
	if(n1){
		p->next=n1;
	}else{
		p->next=n2;
	}
	//����ͷ��㣬���Ѿ��ϲ��õ�����
	return dummy.next;
}

