#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//Ѱ�������к����������飬�����ö�̬�滮dp��ʾ���ͣ���ݹ��ʾ��һ�����ֵ�ͣ���ǰ�����뵱ǰ����һ������Ԫ�صĺ��ĸ��� 

int maxSubArray(vector<int>& nums) {
    //��ʼ��Ԫ�غ�
    int sum=0;
	//��ʼ���������ֵΪ��Сint�� 
	int m=INT_MIN;
	//����
	for(int i=0;i<nums.size();i++){
		//Ԫ�غ�������Ԫ���ۼ�
		sum+=nums[i];
		//m��ÿ���ۼӺ�Ƚϳ������ֵ
		m=max(m,sum);
		//����ۼӺ�С��0������0������һ��Ԫ�ؼ�����ʼ�ۼ�
		if(sum<0){
			sum=0;
		}
	}
	//����
	return m; 
}
