#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int missingNumber(vector<int>& nums);

int main(){
	int A[]={0,1,2,4,5,6};
	vector<int> nums(A,A+6);
	int result=missingNumber(nums);
	cout<<result;
}



//�ҵ�˳�������ж�ʧ��Ԫ��
//�ȽϿ�ķ���������ȷ�����������Ԫ�غ������������Ԫ�غ���Ƚϣ���ͬ���Ƕ�ʧ��Ԫ��
//����cpu���������XOR����ȽϿ죬�������ķ������ԴﵽOn��ʱ�临�Ӷȣ�O1�Ŀռ临�Ӷ� 
bool isPowerOfTwo(int n){
	
}
