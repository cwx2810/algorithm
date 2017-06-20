#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//任意给定数n表示节点数，求有多少二叉树排列方式
//以根节点分界，假设左边有m种排列，右边有n中排列，则共有mn种排列 
//设dp[i]为有i个节点时二叉树个数，则递归方程为dpi=dpj*dp(i-j-1)，其中j是左子树个数 
 

int numTrees(int n) {
    //初始化dp数组
    vector<int> dp(n+1,0);
	//边界条件，只有0个节点，一个节点时，二叉树只有一种排列方式 
	dp[0]=1;
	dp[1]=1;
	//迭代dp方程
	//节点数从2个开始，增加到n个
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			//左子树的节点数必定是小于i的
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	//返回求得排列个数
	return dp[n]; 
}
