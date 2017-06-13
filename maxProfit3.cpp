#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//股票买卖，限制交易两次，用一次交易的方法，计算前i次，然后再从后往前算一次 

int maxProfit(vector<int>& prices) {
	//corner case 天数小于等于1天
	if(prices.size()<=1) return 0;
	//建立一个保存每一天利润的数组，将其初始化和天数一样大小 
	vector<int> profits;
	profits.resize(prices.size());
	
	//首先正向遍历每天最大利润保存到利润数组中
	//初始化最低价格为第一天价格 
	int minP=prices[0];
	//初始化返回利润
	int sum=0;
	//迭代
	for(int i=1;i<prices.size();i++){
		//迭代最低价格
		minP=min(minP,prices[i-1]);
		//迭代每天最大利润
		profits[i]=max(sum,prices[i]-minP);
		//将此利润赋给总利润
		sum=profits[i];
	}

	//其次逆向遍历最大利润
	//初始化最高价格为最后一天价格
	int maxP=prices[prices.size()-1];
	//初始化另一个返回利润 
	int sum2=0;
	//迭代
	for(int i=prices.size()-2;i>=0;i--){
		//迭代最高价格
		maxP=max(maxP,prices[i+1]);
		//迭代每天最大利润
		sum2=max(sum2,maxP-prices[i]);
		//如果利润存在，将其直接保存到利润数组中，并赋给总利润
		if(sum2>0){
			profits[i]+=sum2;
			sum=max(sum,profits[i]);
		}
	}
	//如果总利润存在，返回总利润，不存在返回0 
	return sum>0?sum:0;
}
