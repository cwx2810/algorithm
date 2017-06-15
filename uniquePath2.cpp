#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���������Ͻǵ����½ǣ�Ѱ������·�����м����ϰ� 

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //corner case ������ά����Ϊ��
    if(obstacleGrid.empty() || obstacleGrid[0].empty()){
    	return 0;
	}
	//��ʼ��·��������Ҫ�����ϰ�
	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	int dp[m][n];
	//�����ʼ�����ȿ���һ����û���ϰ�
	dp[0][0]=(obstacleGrid[0][0]==0?1:0);
	//�ٳ�ʼ����һ�к͵�һ�� 
	for(int i=1;i<m;i++){
		dp[i][0]=(dp[i-1][0]==1 && obstacleGrid[i][0]==0?1:0);
	} 
	for(int j=1;j<n;j++){
		dp[0][j]=(dp[0][j-1]==1 && obstacleGrid[0][j]==0?1:0);
	}
	//˫ѭ��dp������ĳ�����ϰ�������·������Ϊ0�����������ݹ�
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(obstacleGrid[i][j]==1){
				dp[i][j]=0;
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	//����
	return dp[m-1][n-1];
}
