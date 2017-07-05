#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//给定一个数组，每个元素代表一个加油站（可以走的格子数），一开始tank没油，问从哪里开始走能走到头
//此题怎么感觉和跳跃游戏很像，不同在于跳跃游戏每个数组元素值就是跳跃步数，而加油站题每站耗油和加油量是不相关的 
//只需要判断到某一个加油站的剩余油量再加这个加油站的油能不能到下一个加油站，不能到则这个加油站和之前的加油站都不能当起点 
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //初始化剩余油量
    int sum=0;
	//初始化总剩余油量，用以计算corner case，就是根本加油站就没有足够的油
	int total=0; 
	//初始化返回的加油站
	int ret=0;
	//遍历所有加油站
	for(int i=0;i<gas.size();i++){
		//剩余油量为此站加的油减去耗的油
		sum+=gas[i]-cost[i];
		//剩余油量不足以到下一站了，说明返回的加油站在下一站以及更后面
		if(sum<0){
			ret=i+1;
			//剩余油量重新开始计算
			sum=0;
		}
		//总剩余油量其实就是不清零的剩余油量
		total+=gas[i]-cost[i];
	}
	//corner case 总剩余油量不足，返回错误
	if(total<0){
		return -1;
	}else{
		//否则，总剩余油量充足，单剩余油量又足够前进，那么算出返回的加油站就是结果
		return ret;
	}
}
