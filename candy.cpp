#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//小孩排队领糖果，每人至少一个，等级高的总是比邻居多，求最少要多少糖果 
//先每人分配一个，从左到右，遍历到的比前一个等级高，就多给一个，再从右到左，遍历到的比前一个等级高，糖果又比前一个少
//就给到比前一个还多一个为止 
int candy(vector<int>& ratings) {
    //初始化每人发的糖果数组
    vector<int> candys;
	//初始化数组，大小等于给定数组，每人先平均给一个
	candys.resize(ratings.size(),1);
	//从左至右遍历
	for(int i=1;i<ratings.size();i++){
		//如果当前等级高，则比前一个多一个糖果
		if(ratings[i]>ratings[i-1]) candys[i]=candys[i-1]+1;
	}
	//从右至左遍历
	for(int i=ratings.size()-2;i>=0;i--){
		//如果当前等级高，并且比前一个糖果少，则糖果给至比前一个多一个
		if(ratings[i]>ratings[i+1] && candys[i]<=candys[i+1]) candys[i]=candys[i+1]+1;
	}
	//初始化返回糖果总数量
	int ret=0;
	//遍历糖果数组，赋给总数量
	for(int i=0;i<candys.size();i++) ret+=candys[i];
	//返回 
	return ret;
}
