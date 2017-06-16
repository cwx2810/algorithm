#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���������Ͻǵ����½ǣ�Ѱ����С��·���� 

int minPathSum(vector<vector<int>>& grid) {
    //corner case ������ά����Ϊ��
    if(grid.empty() || grid[0].empty()){
    	return 0;
	}
	//��ʼ���еĸ�������һά���飩
	int row=grid.size();
	//��ʼ���еĸ������ڶ�ά���飩
	int col=grid[0].size(); 
	//��ʼ��dpΪ����
	int dp[row][col];
	//��ʼ�����Ͻ�ԭ��
	dp[0][0]=grid[0][0];
	//��ʼ��ÿ�е�һ��Ԫ��
	for(int i=1;i<row;i++){
		dp[i][0]=dp[i-1][0]+grid[i][0];
	}
	//��ʼ��ÿ�е�һ��Ԫ��
	for(int j=1;j<col;j++){
		dp[0][j]=dp[0][j-1]+grid[0][j];
	}
	//˫ѭ������Сdp�����ﶯ̬�滮���̱Ƚϵ����Ϸ����Ӻ���߸����ĸ�С���ټ��ϵ�ǰ���� 
	for(int i=1;i<row;i++){
		for(int j=1;j<col;j++){
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}
	//���� 
	return dp[row-1][col-1];
}
