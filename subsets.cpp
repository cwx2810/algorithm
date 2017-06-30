#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//列出集合里面所有的子集合
//用遍历-回溯的方法，就像小时候玩仙剑3走迷宫，取出第一个元素，则剩下元素都是岔路，每一条岔路都要回溯走一遍 
 
//初始化返回集合
vector<vector<int> > ret;
vector<vector<int>> subsets(vector<int>& nums) {
    //corner case给定集合为空
	if(nums.empty()) return ret;
	//由于要求子集合升序，所以先排序
	sort(nums.begin(),nums.end());
	//空集合也算子集合，先单独压入返回集合
	ret.push_back(vector<int>());
	//初始化存储子集合的一维数组
	vector<int> tmp;
	//调用构造函数
	generate(0,tmp,nums);
	//返回
	return ret; 
}
//创建构造函数，传入开始元素下标（随着每次回溯到起点+1，就是算法要遍历完每个元素，同时又走完每个元素的岔路），一维二维数组
void generate(int start,vector<int> &tmp,vector<int> &nums){
	//当开始元素下标等于数组长度，意味着遍历完了所有的元素，返回
	if(start==nums.size()) return;
	//遍历所有元素
	for(int i=start;i<nums.size();i++){
		//压栈一维数组
		tmp.push_back(nums[i]);
		//压栈二维数组
		ret.push_back(tmp);
		//深度递归
		generate(i+1,tmp,nums);
		//一条路走到头，返回到这里，弹栈走另一条
		tmp.pop_back(); 
	} 
}
