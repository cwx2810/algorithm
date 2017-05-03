#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(){
	int a[]={1,2,5,7,9};
    vector<int> A(a,a+5);
	int t=7;
	vector<int> ret=twoSum(A,t);
	for(int i=0;i<ret.size();i++){
		cout<<ret[i]<<" ";
	}
}



vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> ret;//新建容器保存返回数组
	unordered_map <int,int> hash;//新建hashmap，key为数组元素，value为数组下标
	if(numbers.size()<1){
		return ret;
	}
	for(int i=0;i<numbers.size();i++){
		int numberToFind=target-numbers[i];//遍历数组元素，已知一个求另一个
		if(hash.find(numberToFind)!=hash.end()){//找到了，把value和i压入vector 
			ret.push_back(hash[numberToFind]);
			ret.push_back(i);
		} else{
			hash[numbers[i]]=i;//没找到，把键值对存入map 
		}
	}
	return ret;
	 
}

