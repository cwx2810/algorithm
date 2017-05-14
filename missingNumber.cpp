#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findPeakElement(vector<int>& nums);

int main(){
	int A[]={1,2,3,1};
	vector<int> nums(A,A+4);
	int result=findPeakElement(nums);
	cout<<result;
}



//找到顺序数组中丢失的元素
//比较快的方法是用正确的连续数组的元素和与给定的数组元素和相比较，不同则是丢失的元素
//利用cpu的性质异或XOR运算比较快，采用异或的方法可以达到On的时间复杂度，O1的空间复杂度 
int missingNumber(vector<int>& nums){
	//初始化x
	//异或正确数组
	//异或给定数组
	//返回x 
}
