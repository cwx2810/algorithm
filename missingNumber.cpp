#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findPeakElement(vector<int>& nums);

int main(){
	int A[]={1,2,3,1};
	vector<int> nums(A,A+4);
	int result=findPeakElement(nums);
	cout<<result;
}



//�ҵ�˳�������ж�ʧ��Ԫ��
//�ȽϿ�ķ���������ȷ�����������Ԫ�غ������������Ԫ�غ���Ƚϣ���ͬ���Ƕ�ʧ��Ԫ��
//����cpu���������XOR����ȽϿ죬�������ķ������ԴﵽOn��ʱ�临�Ӷȣ�O1�Ŀռ临�Ӷ� 
int missingNumber(vector<int>& nums){
	//��ʼ��x
	//�����ȷ����
	//����������
	//����x 
}
