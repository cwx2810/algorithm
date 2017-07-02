#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//求出给定序列所有可能的变种序列，这次给定序列有重复元素，答案的序列不能相同 
//对给定数组进行排序，这样相同的元素就会在一起，我们以往的思路是以每个元素为基准求他的序列
//现在一样，求出某个元素的序列，但后面和他一样的重复元素就跳过，这样就避免的求得同样的序列 
vector<vector<int>> permuteUnique(vector<int>& nums) {
    //初始化返回二维数组
    vector<vector<int>> ret;
	//corner case给定数组为空
	if(nums.size()==0) return ret;
	//初始化一维序列
	vector<int> curr;
	//初始化标记序列，大小等于给定数组，开始都为false
	vector<bool> isVisited(nums.size(),false);
	//先对给定数组进行排序
	sort(nums.begin(),nums.end());
	//递归
	backTracking(ret,curr,nums,isVisited);
	//返回 
	return ret;
}
//构建递归函数，传入二维返回数组，一维数组，给定数组，标记数组
void backTracking(vector<vector<int>> &ret,vector<int> curr,vector<int> nums,vector<bool> isVisited){
	//如果一维序列大小等于给定序列，压栈完成，压入二维数组并返回
	if(curr.size()==nums.size()){
		ret.push_back(curr);
		return;
	}
	//迭代
	for(int i=0;i<nums.size();++i){
		//如果未标记，则操作，标记过了不操作，跳过
		if(isVisited[i]==false){
			//标记之
			isVisited[i]=true;
			//压栈一维数组
			curr.push_back(nums[i]);
			//深度递归
			backTracking(ret,curr,nums,isVisited);
			//递归到头，返回到这里走另一条路，重新置当前节点为未访问
			isVisited[i]=false;
			//弹栈
			curr.pop_back();
			//当遇到重复元素时，跳过
			while(i<nums.size()-1&&nums[i]==nums[i+1]) ++i;
		}
	}
}
