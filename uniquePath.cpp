#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//从棋盘左上角到右下角，寻找所有路径，动态规划问题 

int uniquePaths(int m, int n) {
    //初始化唯一路径数量
    int dp[m][n];
	//具体初始化，第一行第一列的唯一路径都为1
	for(int i=0;i<m;i++){
		dp[i][0]=1;
	}
	for(int j=0;j<n;j++){
		dp[0][j]=1;
	}
	//双循环，放入dp公式，某一格的唯一路径数量等于上面和左面两格的唯一路径数量之和
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	//返回最后一格的唯一路径数量 
	return dp[m-1][n-1];
}
