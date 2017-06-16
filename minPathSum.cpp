#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//从棋盘左上角到右下角，寻找最小的路径和 

int minPathSum(vector<vector<int>>& grid) {
    //corner case 给定二维数组为空
    if(grid.empty() || grid[0].empty()){
    	return 0;
	}
	//初始化行的个数（第一维数组）
	int row=grid.size();
	//初始化列的个数（第二维数组）
	int col=grid[0].size(); 
	//初始化dp为行列
	int dp[row][col];
	//初始化左上角原点
	dp[0][0]=grid[0][0];
	//初始化每行第一个元素
	for(int i=1;i<row;i++){
		dp[i][0]=dp[i-1][0]+grid[i][0];
	}
	//初始化每列第一个元素
	for(int j=1;j<col;j++){
		dp[0][j]=dp[0][j-1]+grid[0][j];
	}
	//双循环求最小dp，这里动态规划方程比较的是上方格子和左边格子哪个小，再加上当前格子 
	for(int i=1;i<row;i++){
		for(int j=1;j<col;j++){
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}
	//返回 
	return dp[row-1][col-1];
}
