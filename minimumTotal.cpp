#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//帕斯卡三角从顶到底最短路径和，且每向下一层只能选相邻的元素
//注意有覆盖问题，所以每行要从后往前算 

int minimumTotal(vector<vector<int>>& triangle) {
    //初始化行
	//corner case 行为0
	//初始化中间迭代变量数组（保存每行元素最小路径）为最大值
	//初始化中间迭代变量第一个值
	//初始化返回变量为最大值 
	//迭代
	//如果在每行开头，即j=0，要特殊计算，直接用上一层的加这一层的即可 
	//在行中间，用正常动态规划，取上一层小的加这一层的 
	//迭代每行路径，返回值为最小路径 
}
