#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//走楼梯问题，一次可以走一级或两级，斐波那契数列，动态规划 

int climbStairs(int n) {
    //初始化步数1和步数2，递归表示时要把步数2赋给步数1，再更新步数1为更大的，所以初始时步数1较大
	int f1=2;
	int f2=1;
	//corner case 第一步和第二步
	if(n==1){
		return f2;
	}else if(n==2){
		return f1;
	}
	//初始化fn
	int fn;
	//从第三层开始迭代到第n层
	for(int i=3;i<=n;i++){
		//更新fn，f2，f1
		fn=f1+f2;
		f2=f1;
		f1=fn;	
	} 
	//返回 
	return fn;
}
