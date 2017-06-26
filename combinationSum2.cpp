#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//找到给定数组中的所有数字组合使得组合的sum=target，组合要升序，target要是正数，不可重复取数
//这题和combinationSum一模一样，唯一区别是在每次迭代前加一条判断所取数是否重复，重复则要跳过 
 

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //初始化二维返回数组
    vector<vector<int> > ret;
	//corner case数组为空或target不是正数
	if(candidates.size()==0||target<0) return ret;
	//初始化一维数字组合
	vector<int> curr;
	//先排序
	sort(candidates.begin(),candidates.end());
	//递归回溯
	BackTracking(ret,curr,candidates,target,0);
	//返回 
	return ret;
}
//创建回溯算法，传入返回二维数组，一维数字组合，给定数组，target，递归深度
void BackTracking(vector<vector<int> > &ret,vector<int> curr,vector<int> candidates,int target,int level){
	//target减到刚好为0，满足条件，压栈返回
	if(target==0){
		ret.push_back(curr);
		return;
	}
	//target减到小于0，不满足条件，返回
	else if(target<0){
		return;
	}
	//迭代给定数组
	for(int i=level;i<candidates.size();++i){
		//每迭代接收一个数，target就减去这个数
		target-=candidates[i];
		//压栈此数
		curr.push_back(candidates[i]);
		//继续往更深递归
		BackTracking(ret,curr,candidates,target,i+1);
		//如果不满足条件，返回到这里，弹栈
		curr.pop_back();
		//把target加回来
		target+=candidates[i];
		//判断所取数是否重复，若重复则跳过
		while(i<candidates.size()-1&&candidates[i]==candidates[i+1]) ++i;
	}
}
 

 
 
