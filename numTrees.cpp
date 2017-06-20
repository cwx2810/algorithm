#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���������n��ʾ�ڵ��������ж��ٶ��������з�ʽ
//�Ը��ڵ�ֽ磬���������m�����У��ұ���n�����У�����mn������ 
//��dp[i]Ϊ��i���ڵ�ʱ��������������ݹ鷽��Ϊdpi=dpj*dp(i-j-1)������j������������ 
 

int numTrees(int n) {
    //��ʼ��dp����
    vector<int> dp(n+1,0);
	//�߽�������ֻ��0���ڵ㣬һ���ڵ�ʱ��������ֻ��һ�����з�ʽ 
	dp[0]=1;
	dp[1]=1;
	//����dp����
	//�ڵ�����2����ʼ�����ӵ�n��
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			//�������Ľڵ����ض���С��i��
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	//����������и���
	return dp[n]; 
}
