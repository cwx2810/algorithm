#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//进入动态规划，第一道股票买卖题，只能进行一次交易 

int maxProfit(vector<int>& prices) {
    //corner case给定数组元素太少不足两天
    if(prices.size()<=1) return 0;
	//初始化最低价格
	int minP=prices[0];
	//初始化利润
	int profit=prices[1]-prices[0];
	
	//迭代
	for(int i=2;i<prices.size();i++){
		//计算最低价格
		minP=min(prices[i-1],minP);
		//计算最大利润
		profit=max(profit,prices[i]-minP);
	}

	//corner case 利润小于0
	if(profit<0) return 0;
	//返回利润 
	return profit;
}
