#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//����һ�����飬ÿ��Ԫ�ش��������Ծ��λ�����������ڵ�һ��Ԫ�أ����ܲ����������һ��Ԫ��
//��̰�ķ�����ÿ����Ծ�Ĳ�����ֿ�����Ծһ������һ���жϵ�ǰ���ӵĲ����ǲ��Ǳ�ʣ��Ҫ���Ĳ���Զ���ǵĻ��õ�ǰ��...
//ֱ���������껹û��ͷ��ʧ�� 
bool canJump(vector<int>& nums) {
    //corner case��������Ϊ��
    if(nums.size()==0) true;
	//��ʼ��Ҫ��Ծ�Ĳ�����һ��ʼ�ǵ�һ��Ԫ�� 
	int step=nums[0];
	//�����������飬��1��ʼ��������Ϊ0��λ��ֵ�Ѿ���ʼ�������ڲ������� 
	for(int i=1;i<nums.size();i++){
		//ÿ����һ������һ
		step--;
		//�������С��0����ʧ��
		if(step<0) return false; 
		//�������С�ڵ�ǰ���ӵĲ������滻
		if(step<nums[i]) step=nums[i];
	}
	//����˳��������˵����ͷ�ˣ��ɹ�
	return true; 
}
