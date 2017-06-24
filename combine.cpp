#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//在n个数中选k个数进行组合，去除重复的，用递归 
 

vector<vector<int>> combine(int n, int k) {
    //初始化返回数组
    vector<vector<int> > ret;
	//corner case 给定数n非正
	if(n<=0) return ret;
	//初始化一维数组组合
	vector<int> curr; 
	//DFS 
	DFS(ret,curr,n,k,1);
	//返回 
	return ret;
}
//构建DFS，传入二维返回数组，一维k个数的组合数组，n，k，DFS深度
void DFS(vector<vector<int> > &ret,vector<int> curr,int n,int k,int level){
	//当一维组合满足等于k个的时候，压入二维数组，返回（之所以可以直接返回，是因为一直在递归）
	if(curr.size()==k){
		ret.push_back(curr);
		return;
	}
	//一维组合大于k，直接返回，这里剪枝条件是考虑到节省递归时间
	if(curr.size()>k){
		return;
	}
	//遍历1~n层 
	for(int i=level;i<=n;++i){
		//将遍历到的数压入一维数组
		curr.push_back(i);
		//递归DFS，进去判断是不是超过k了
		DFS(ret,curr,n,k,i+1);
		//超过k会返回这里，弹栈
		curr.pop_back();
	}
}
 
 
