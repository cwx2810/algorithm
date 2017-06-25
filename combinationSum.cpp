#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//找到给定数组中的所有数字组合使得组合的sum=target，组合要升序，target要是正数，可以重复取数
//上一题是规定k个数组合，用压栈数量和k比较，这一次是给定组合的sum，直接压栈算sum，sum和0比较、递归，满足条件的压入ret 
 

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //初始化返回二维数组
    vector<vector<int> > ret;
	//corner case给定数组为空或者target不是正数
	if(candidates.size()==0||target<0){
		return ret;
	}
	//初始化组合一维数组
	vector<int> curr;
	//先对给定数组排序
	sort(candidates.begin(),candidates.end());
	//递归函数
	BackTracking(ret,curr,candidates,target,0);
	//返回 
	return ret;
}
//创建递归函数，传入返回二维数组，组合一维数组，给定数组，给定target，递归深度
void BackTracking(vector<vector<int> > &ret,vector<int> curr,vector<int> candidates,int target,int level){
	//每次操作数组，一维数组加进去一个，target减一个，如果刚好减到等于0，说明进入数组的数满足等于target
	if(target==0){
		ret.push_back(curr);
	}
	//如果减到小于0，不满足，直接返回，不考虑大于0，大于0说明数组没吸收够，继续往深里递归
	else if(target<0){
		return;
	}
	//递归给定数组
	for(int i=level;i<candidates.size();++i){
		//target每次吸收当前数组值，下一次就不考虑他了，所以每次减去当前数组值
		target-=candidates[i];
		//压栈当前数值
		curr.push_back(candidates[i]);
		//深度递归，再次吸收当前i的值，直到吸收后小于0，返回到这里，执行下一句
		BackTracking(ret,curr,candidates,target,i);
		//当小于0，说明吸收错了，弹出栈顶
		curr.pop_back();
		//把target也加回来，迭代下一个i
		target+=candidates[i]; 
	}
}

 
 
