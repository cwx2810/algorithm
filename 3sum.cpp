#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums);

int main(){
	int a[]={-1,0,1,2,-1,-4};
    vector<int> A(a,a+6);
	vector<vector<int> > ret=threeSum(A);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
}



//给定数组，找出数组中所有相加为0的三个数 
//关键在理解重复的判断，三人组里每个元素的遍历确定是独立的、单独循环的，不影响另外两个元素
//所以元素内部遇到重复的要++跳过，不然出来的是一样的数组，而元素之间可以重复 
vector<vector<int> > threeSum(vector<int>& nums) {
	//初始化返回数组 
    vector<vector<int> > ret;
    //corner case 给定数组只有两个元素是凑不出三个的 
    if(nums.size()<=2){
    	return ret;
	}
	sort(nums.begin(),nums.end());//先排序，题目要求有序 
	for(int i=0;i<nums.size();i++){
	    int j=i+1;
	    int k=nums.size()-1;
		while(j<k){
		    vector<int> tmp;//用来保存vector中的vector 
			if(nums[i]+nums[j]+nums[k]==0){//满足条件就压栈 
				tmp.push_back(nums[i]);
				tmp.push_back(nums[j]);
				tmp.push_back(nums[k]);
				ret.push_back(tmp);
				j++;//压完栈游标移动 
				k--;
				while(nums[j]==nums[j-1]){//移动后的元素等于移动前的，说明这个位子内部循环有重复，要跳过 
					j++;
				}
				while(nums[k]==nums[k+1]){//同理 
					k--;
				}
			}else if(nums[i]+nums[j]+nums[k]<0){//已经排过序了，相加小于0说明小的太小了 
				j++;
			}else{//同理，大的太大了 
				k--;
			}
		}
		while(nums[i]==nums[i+1]){//第一个位子也不能重复 
			i++;
		}
	}
	return ret;
}


