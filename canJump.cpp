#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//给定一个数组，每个元素代表可以跳跃的位数，现在你在第一个元素，问能不能挑到最后一个元素
//用贪心法，把每次跳跃的步数拆分开，跳跃一格步数减一，判断当前格子的步数是不是比剩下要跳的步数远，是的话用当前的...
//直到步数用完还没到头则失败 
bool canJump(vector<int>& nums) {
    //corner case给定数组为空
    if(nums.size()==0) true;
	//初始化要跳跃的步数，一开始是第一个元素 
	int step=nums[0];
	//遍历给定数组，从1开始遍历，因为0号位数值已经初始化保存在步数中了 
	for(int i=1;i<nums.size();i++){
		//每遍历一格步数减一
		step--;
		//如果步数小于0了则失败
		if(step<0) return false; 
		//如果步数小于当前格子的步数，替换
		if(step<nums[i]) step=nums[i];
	}
	//遍历顺利结束，说明到头了，成功
	return true; 
}
