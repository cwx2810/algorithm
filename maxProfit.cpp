#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���붯̬�滮����һ����Ʊ�����⣬ֻ�ܽ���һ�ν��� 

int maxProfit(vector<int>& prices) {
    //corner case��������Ԫ��̫�ٲ�������
    if(prices.size()<=1) return 0;
	//��ʼ����ͼ۸�
	int minP=prices[0];
	//��ʼ������
	int profit=prices[1]-prices[0];
	
	//����
	for(int i=2;i<prices.size();i++){
		//������ͼ۸�
		minP=min(prices[i-1],minP);
		//�����������
		profit=max(profit,prices[i]-minP);
	}

	//corner case ����С��0
	if(profit<0) return 0;
	//�������� 
	return profit;
}
