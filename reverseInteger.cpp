#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//翻转一个int数字，超过32位返回0 
int reverse(int x) {
    //初始化longlong类型返回数字，因为光判断就要超过32位了
    long long ret=0;
	//迭代x
	while(x){
		//返回数每次*10在末尾（从左至右）添加给定数上次/10的余数（从右至左）也就是末尾数 
		ret=ret*10+x%10;
		//给定数/10
		x/=10;
	}
	//返回时判断是不是满足32位 
	return (ret<INT_MIN || ret>INT_MAX)?0:ret;
}










class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
