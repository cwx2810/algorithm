#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���������Ͻǵ����½ǣ�Ѱ������·������̬�滮���� 

int uniquePaths(int m, int n) {
    //��ʼ��Ψһ·������
    int dp[m][n];
	//�����ʼ������һ�е�һ�е�Ψһ·����Ϊ1
	for(int i=0;i<m;i++){
		dp[i][0]=1;
	}
	for(int j=0;j<n;j++){
		dp[0][j]=1;
	}
	//˫ѭ��������dp��ʽ��ĳһ���Ψһ·������������������������Ψһ·������֮��
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	//�������һ���Ψһ·������ 
	return dp[m-1][n-1];
}
