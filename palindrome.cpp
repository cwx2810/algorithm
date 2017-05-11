#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool isPalindrome(int x);

int main(){
	cout<<"Enter a number:";
	int x;
	cin>>x;
	cout<<isPalindrome(x);
}



//判断回文数
//思路，把给定数的每一位倒过来写还等于原数就是回文数
//怎么倒？设计递归数，每次给定数/10的余数加上上一次递归的数*10，直到给定数为0为止 
bool isPalindrome(int x){
	//小于0的数不是回文数
	if(x<0){
		return false;
	}else if(x==0){//等于0的数是回文数
		return true;
	}else{
		//初始化给定数临时保存用于后续比较、初始化递归数 
		int tmp=x;
		int y=0;
		//只要给定数不为零就一直循环
		while(x!=0){
			y=y*10+x%10;
			x=x/10;
		}
		//递归数等于给定数，返回true 
		if(y==tmp){
			return true;
		}else{
			return false;
		}
	}
}



