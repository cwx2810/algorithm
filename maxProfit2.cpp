#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��Ʊ�����������ƽ��״��� 

int maxProfit(vector<int>& prices) {
	//corner case �����������죬�����鳤��С�ڵ���1
	if(prices.size()<=1) return 0;
	//��ʼ��������
	int profit=0;
	//����
	for(int i=1;i<prices.size();i++){
		//�����i�����ǰһ��ģ��������������
		if(prices[i]>prices[i-1]){
			profit+=prices[i]-prices[i-1];
		}
	}
	//�������� 
	return profit;
}
