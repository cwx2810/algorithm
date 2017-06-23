#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//求最少用多少完全平方数相加得给定数n 
//用动态规划的思想，记录下曾经加得的最少完全平方数，n每次只增加1，但需要的最少完全平方数的增量△是不固定的
//而动态规划可以很好的跳跃计算，跳过一些暂时算不到的n，先跳到前面的数，增量刚好满足一个最少完全平方数
//我们不妨设这个最小增量是j的平方，这样dp每次的增量就是j*j 
 

int numSquares(int n) {
    //初始化dp数组，记录递归结果
    vector<int> dp(n+1,INT_MAX);
	//corner case 给定数是0
	dp[0]=0;
	//双循环，外层迭代n，内层是真正的增量，在i的基础上每次迭代一个完全平方
	for(int i=0;i<=n;i++){
		for(int j=1;i+j*j<=n;j++){
			//每次这个真正增量增出来的数=min（以前记录的最小值，当场增加的1个完全平方后的值）
			dp[i+j*j]=min(dp[i+j*j],dp[i]+1);
		}
	}
	//返回
	return dp[n]; 
}
 
