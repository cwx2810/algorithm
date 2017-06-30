#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//列出集合里面所有的子集合，给定集合可能有重复元素 
//同样走迷宫，区别是遇到重复元素要跳过 
 
//初始化返回集合
vector<vector<int>> ret;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //corner case 给定数组为空
    if(nums.empty()) return ret;
	//先排序
	sort(nums.begin(),nums.end());
	//压空子集
	ret.push_back(vector<int>());
	//初始化一维子集
	vector<int> tmp;
	//调用构造函数
	generate(0,tmp,nums);
	//返回 
	return ret;
}
//创建构造函数，传入集合开始元素下标，一维子集，给定子集 
void generate(int start,vector<int> &tmp,vector<int> &nums){
	//开始下标等于集合长度，遍历完毕，返回
	if(start==nums.size()) return;
	//开始迭代
	for(int i=start;i<nums.size();i++){
		//压栈一维集合
		tmp.push_back(nums[i]);
		//压栈返回集合
		ret.push_back(tmp);
		//深度递归
		generate(i+1,tmp,nums);
		//遍历到头，返回这里，弹栈走另一条路
		tmp.pop_back();
		//跳过相同的元素
		while(i<nums.size()-1&&nums[i]==nums[i+1]) i++;
	}
}
 
