#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool isPowerOfTwo(int n);

int main(){
	int n=30;
	bool result=isPowerOfTwo(n);
	cout<<result; 
}



//判断是否给定数是2的幂
//思路，把给定数转换成二进制，是2的幂则二进制没有1或只有1个1，负数不是2的幂 
bool isPowerOfTwo(int n){
	//corner case负数 
	if(n<0){
		return false;
	} 
	//初始化判断的返回值 
	bool hasOne=false;
	//整数位运算 
	while(n>0){
		//如果余1则进入判断 
		if(n&1){
			//如果hasOne已经真了，则不是2的幂，说明之前算的余数出来1了，有超过1个1 
			if(hasOne){
				return false;
			}else{//否则，1是第一次粗线，则设置hasOne为1 
				hasOne=true;
			}
		}
		//余0则直接跳过这一位 
		n>>=1;
	}
	return hasOne;
	
}
