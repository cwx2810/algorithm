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



//判断整数中二进制1的个数 
//类似于powerof2，还是利用与运算判断最低位是否为1, 
int hammingWeight(uint32_t n) {
	int count=0;
	while(n>0){
		count+=n&1;
		n>>=1;
	}
    return count;
}
