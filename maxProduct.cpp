#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//Ѱ�������г˻�����������
//Ҫ��������������һ�����һ����С����Ϊ�˷��и�����������С��Ҳ����һ���ͱ�����
//��Ҫ���ǳ�0�����������0�����С����0������һ����ʼ���¿�ʼ�� 

int maxProduct(vector<int>& nums) {
    //corner case ��������Ϊ�ջ�ֻ��һ��Ԫ��
    if(nums.size()==0) return 0;
    if(nums.size()==1) return nums[0];
	//��ʼ������ֵ�����ֵ����Сֵ
	int ret=nums[0];
	int maxP=nums[0];
	int minP=nums[0];
	//����
	for(int i=1;i<nums.size();i++){
		//������ʱ����δ�ı�ǰ��max�ı���t
		int temp=maxP;
		//�����ֵ������ǰ������ֵ�͵�ǰԪ�صĶԱȣ��Է���0���֣������������ֵ�͵�ǰ��Сֵ�ȣ��Է��и����������� 
		maxP=max(max(maxP*nums[i],nums[i]),minP*nums[i]);
		//����Сֵ���õ�t���������෴���������ȫ�������С
		minP=min(min(temp*nums[i],nums[i]),minP*nums[i]); 
		//�󷵻�ֵ���Ǻ͵�ǰԪ���������û���ǰ�����Ա� 
		ret=max(maxP,ret);
	}
	//���� 
	return ret;
}
