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



//�ж������ж�����1�ĸ��� 
//������powerof2�����������������ж����λ�Ƿ�Ϊ1, 
int hammingWeight(uint32_t n) {
	int count=0;
	while(n>0){
		count+=n&1;
		n>>=1;
	}
    return count;
}
