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


//给定一个数组和一个值，要求输出此数组的两个下标，这俩下标的值加起来是给定值 
vector<int> twoSum(vector<int> &numbers, int target) {
	//初始化容器保存返回数组
	vector<int> ret;
	//初始化hashmap，key为数组元素，value为数组下标
	unordered_map <int,int> hash;
	//corner case 给定数组为空 
	if(numbers.size()<1){
		return ret;
	}
	//遍历数组元素下标 
	for(int i=0;i<numbers.size();i++){
		//已知一个值可以表示出另一个值，这样每次遍历元素后找到应该匹配的值，在hashmap中找，找到说明满足 
		int numberToFind=target-numbers[i];
		//没有一直走到hashmap的最后，说明找到了，把找到的下标value和遍历的下标i压入vector
		if(hash.find(numberToFind)!=hash.end()){ 
			ret.push_back(hash[numberToFind]);
			ret.push_back(i);
		} else{
			//没找到，把映射存入map
			//这里要倒着想，一开始map中肯定是没有映射的，找不到的，渐渐存入，才会在遍历到某一元素时找到
			//刚好上面的压栈顺序也是倒着的，因为遍历到的i在后面是大下标，找到的是已经保存的在前面小下标
			//仔细揣摩，真是一个节省时间空间的做法，甚至都不在一开始初始化好所有的hashmap，而是初始化映射到刚好够用 
			hash[numbers[i]]=i; 
		}
	}
	//返回 
	return ret;
}

