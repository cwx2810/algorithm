#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//寻找数组中乘积最大的子数组
//要考虑两个变量，一个最大一个最小，因为乘法有负负得正，最小的也许下一步就变最大的
//还要考虑乘0的情况，遇到0最大最小都变0，从下一个开始重新开始算 

int maxProduct(vector<int>& nums) {
    //corner case 给定数组为空或只有一个元素
    if(nums.size()==0) return 0;
    if(nums.size()==1) return nums[0];
	//初始化返回值，最大值，最小值
	int ret=nums[0];
	int maxP=nums[0];
	int minP=nums[0];
	//迭代
	for(int i=1;i<nums.size();i++){
		//设置临时保存未改变前的max的变量t
		int temp=maxP;
		//求最大值，先求当前算出最大值和当前元素的对比，以防有0出现，再用算出来的值和当前最小值比，以防有负负得正出现 
		maxP=max(max(maxP*nums[i],nums[i]),minP*nums[i]);
		//求最小值，用到t，和上面相反，把求最大全变成求最小
		minP=min(min(temp*nums[i],nums[i]),minP*nums[i]); 
		//求返回值，是和当前元素算过后与没算过前的最大对比 
		ret=max(maxP,ret);
	}
	//返回 
	return ret;
}
