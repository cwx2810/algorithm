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



//�ж��Ƿ��������2����
//˼·���Ѹ�����ת���ɶ����ƣ���2�����������û��1��ֻ��1��1����������2���� 
bool isPowerOfTwo(int n){
	//corner case���� 
	if(n<0){
		return false;
	} 
	//��ʼ���жϵķ���ֵ 
	bool hasOne=false;
	//����λ���� 
	while(n>0){
		//�����1������ж� 
		if(n&1){
			//���hasOne�Ѿ����ˣ�����2���ݣ�˵��֮ǰ�����������1�ˣ��г���1��1 
			if(hasOne){
				return false;
			}else{//����1�ǵ�һ�δ��ߣ�������hasOneΪ1 
				hasOne=true;
			}
		}
		//��0��ֱ��������һλ 
		n>>=1;
	}
	return hasOne;
	
}
