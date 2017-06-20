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
    int row=triangle.size();
	//corner case 行为0
	if(row==0) return 0;
	//初始化中间迭代变量数组（保存每行元素最小路径）为最大值
	vector<int> total(row,INT_MAX);
	//初始化中间迭代变量第一个值
	total[0]=triangle[0][0];
	//初始化返回变量为最大值 
	int minitotal=INT_MAX;
	//迭代
	for(int i=1;i<row;i++){
		for(int j=i;j>=0;j--){
			if(j==0){
				//如果在每行开头，即j=0，要特殊计算，直接用上一层的加这一层的即可
				total[j]=total[j]+triangle[i][j];
			}else{
				//在行中间，用正常动态规划，取上一层小的加这一层的
				total[j]=min(total[j-1],total[j])+triangle[i][j];
			}
		}
	}
	//迭代每行路径，返回值为最小路径 
	for(int i=0;i<row;i++){
		minitotal=min(minitotal,total[i]);
	}
	return minitotal;
}
