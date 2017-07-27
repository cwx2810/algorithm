#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//将两个给定二进制字符串相加，要保存进位，考虑字符串长度相同和不同的情况，并考虑char和int的转换 
string addBinary(string a, string b) {
    //corner case某个字符串长度为0，返回另一个即可
    if(a.size()==0) return b;
    if(b.size()==0) return a;
	//初始化返回字符串
	string ret;
	//初始化进位
	int carry=0;
	//初始化两个字符串数组下标
	int index1=a.size()-1;
	int index2=b.size()-1;
	//遍历下标做加法运算，当下标同时有效时，迭代
	while(index1>=0 && index2>=0){
		//计算每一位数字，为两个字符串的每一位转换成int后+进位
		int num=(a[index1]-'0')+(b[index2]-'0')+carry;
		//计算二进制进位，供下一次迭代用 
		carry=num/2;
		//把插入的数字转换成可返回的二进制
		num=num%2;
		//迭代两个字符串下标
		index1--;
		index2--;
		//插入到返回字符串数组
		ret.insert(ret.begin(),num+'0');
	}
	//如果迭代完两个数组，把进位加上
	if(index1<0 && index2<0){
		if(carry==1){
			ret.insert(ret.begin(),carry+'0');
			//返回
			return ret;
		}
	}
	//当两个字符串不一样长，第一个有余时，单独计算添加一遍 
	while(index1>=0){
		int num=(a[index1]-'0')+carry;
		carry=num/2;
		num=num%2;
		index1--;
		ret.insert(ret.begin(),num+'0');
	}
	//另一个有余也一样
	while(index2>=0){
		int num=(b[index2]-'0'+carry);
		carry=num/2;
		num=num%2;
		index2--;
		ret.insert(ret.begin(),num+'0');
	}
	//再次添加进位
	if(carry==1) ret.insert(ret.begin(),carry+'0');
	//返回 
	return ret;
}
