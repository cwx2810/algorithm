#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//给定一个数组，每个元素代表可以跳跃的位数，现在你在第一个元素，问跳到最后一个元素需要最少的跳跃次数
//还是用贪心，每走一步就贪心的判断下一步怎么走的最远，这个最远是（当前站位允许的步数＋已走的步数）和原本的步数对比 
int jump(vector<int>& nums) {
    //初始化走了几步
    int step=0;
	//初始化当前走到的下标
	int cur=0;
	//初始化下一次走到的下标
	int next=0;
	//初始化遍历变量
	int i=0;
	//迭代给定数组
	while(i<nums.size()){
		//如果当前走到的下标达到n-1，说明走到头了，跳出遍历返回步数
		if(cur>=nums.size()-1) break;
		//在当前走到的下标内遍历下一次走的最远的下标
		while(i<=cur){
			//下一次走的最远的下标是按当前下标走的最远，和当前下标之内遍历到的下标走的最远相比较，哪个更远就是下一次走的最远的下标 
			//内循环走的最远的下标是遍历到的元素的值（也就是以这个元素为准的下一跳步数）+这个值之前已经走的步数
			next=max(next,nums[i]+i);
			//递增，遍历整个当前走到的下标
			i++;
		}
		//遍历完毕，已经求得下一次最远的下标，往前走一步
		step++;
		//当前变成了下一跳最远，大循环算下一个最远跳
		cur=next;
	}
	//遍历完所有元素，此时当前已经走到了n-1，返回走的步数
	return step; 
}
