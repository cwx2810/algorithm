#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��Ʊ���������ƽ������Σ���һ�ν��׵ķ���������ǰi�Σ�Ȼ���ٴӺ���ǰ��һ�� 

int maxProfit(vector<int>& prices) {
	//corner case ����С�ڵ���1��
	if(prices.size()<=1) return 0;
	//����һ������ÿһ����������飬�����ʼ��������һ����С 
	vector<int> profits;
	profits.resize(prices.size());
	
	//�����������ÿ��������󱣴浽����������
	//��ʼ����ͼ۸�Ϊ��һ��۸� 
	int minP=prices[0];
	//��ʼ����������
	int sum=0;
	//����
	for(int i=1;i<prices.size();i++){
		//������ͼ۸�
		minP=min(minP,prices[i-1]);
		//����ÿ���������
		profits[i]=max(sum,prices[i]-minP);
		//�������󸳸�������
		sum=profits[i];
	}

	//�����������������
	//��ʼ����߼۸�Ϊ���һ��۸�
	int maxP=prices[prices.size()-1];
	//��ʼ����һ���������� 
	int sum2=0;
	//����
	for(int i=prices.size()-2;i>=0;i--){
		//������߼۸�
		maxP=max(maxP,prices[i+1]);
		//����ÿ���������
		sum2=max(sum2,maxP-prices[i]);
		//���������ڣ�����ֱ�ӱ��浽���������У�������������
		if(sum2>0){
			profits[i]+=sum2;
			sum=max(sum,profits[i]);
		}
	}
	//�����������ڣ����������󣬲����ڷ���0 
	return sum>0?sum:0;
}
