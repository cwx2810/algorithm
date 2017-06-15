#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//从棋盘左上角到右下角，寻找所有路径，中间有障碍 

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //corner case 给定二维数组为空
    if(obstacleGrid.empty() || obstacleGrid[0].empty()){
    	return 0;
	}
	//初始化路径数量，要考虑障碍
	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	int dp[m][n];
	//具体初始化，先看第一格有没有障碍
	dp[0][0]=(obstacleGrid[0][0]==0?1:0);
	//再初始化第一列和第一行 
	for(int i=1;i<m;i++){
		dp[i][0]=(dp[i-1][0]==1 && obstacleGrid[i][0]==0?1:0);
	} 
	for(int j=1;j<n;j++){
		dp[0][j]=(dp[0][j-1]==1 && obstacleGrid[0][j]==0?1:0);
	}
	//双循环dp，遇到某点有障碍，置其路径数量为0，其余正常递归
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(obstacleGrid[i][j]==1){
				dp[i][j]=0;
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	//返回
	return dp[m-1][n-1];
}
