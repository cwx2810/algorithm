#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//股票买卖，不限制交易次数 

int maxProfit(vector<int>& prices) {
	//corner case 天数少于两天，即数组长度小于等于1
	if(prices.size()<=1) return 0;
	//初始化总利润
	int profit=0;
	//迭代
	for(int i=1;i<prices.size();i++){
		//如果第i天大于前一天的，则把这段利润加上
		if(prices[i]>prices[i-1]){
			profit+=prices[i]-prices[i-1];
		}
	}
	//返回利润 
	return profit;
}
