#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//求出给定序列所有可能的变种序列，和combination很像，只不过combination是求子组合，permutation是求和给定数组一样长的序列 
//同样按照DFS，遍历压栈以每个元素为首的序列，设置bool，遍历过的设为true 
vector<vector<int>> permute(vector<int>& nums) {
    //初始化返回二维序列
    vector<vector<int>> ret;
	//corner case给定序列为空
	if(nums.size()==0) return ret;
	//初始化一维序列
	vector<int> curr;
	//初始化bool数组，大小和给定数组一样，初始为false
	vector<bool> isVisited(nums.size(),false); 
	//调用回溯函数
	backTracking(ret,curr,isVisited,nums);
	//返回 
	return ret;
}
//构造回溯函数，传入返回二维数组，一维序列，标记数组，给定数组
void backTracking(vector<vector<int>> &ret,vector<int> curr,vector<bool> isVisited,vector<int> nums){
	//一维数组大小等于给定数组，说明遍历完了整个给定数组，压栈，返回
	if(curr.size()==nums.size()){
		ret.push_back(curr);
		return;
	}
	//迭代给定数组
	for(int i=0;i<nums.size();++i){
		//当前节点没有标记就进行标记和操作，标记过了就跳过迭代下一个
		if(isVisited[i]==false){
			//标记当前节点 
			isVisited[i]=true;
			//把当前节点压入一维数组
			curr.push_back(nums[i]);
			//深度回溯
			backTracking(ret,curr,isVisited,nums);
			//如果回溯到头返回到这里，重新置标记为false，弹栈
			isVisited[i]=false;
			curr.pop_back();
		} 
	}
} 
