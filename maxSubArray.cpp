#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//寻找数组中和最大的子数组，假设用动态规划dp表示最大和，则递归表示下一个最大值和：当前最大和与当前和下一个数组元素的和哪个大 

int maxSubArray(vector<int>& nums) {
    //初始化元素和
    int sum=0;
	//初始化返回最大值为最小int型 
	int m=INT_MIN;
	//迭代
	for(int i=0;i<nums.size();i++){
		//元素和是数组元素累加
		sum+=nums[i];
		//m是每次累加后比较出的最大值
		m=max(m,sum);
		//如果累加和小于0，则置0，从下一个元素继续开始累加
		if(sum<0){
			sum=0;
		}
	}
	//返回
	return m; 
}
