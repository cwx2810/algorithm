#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��¥�����⣬һ�ο�����һ����������쳲��������У���̬�滮 

int climbStairs(int n) {
    //��ʼ������1�Ͳ���2���ݹ��ʾʱҪ�Ѳ���2��������1���ٸ��²���1Ϊ����ģ����Գ�ʼʱ����1�ϴ�
	int f1=2;
	int f2=1;
	//corner case ��һ���͵ڶ���
	if(n==1){
		return f2;
	}else if(n==2){
		return f1;
	}
	//��ʼ��fn
	int fn;
	//�ӵ����㿪ʼ��������n��
	for(int i=3;i<=n;i++){
		//����fn��f2��f1
		fn=f1+f2;
		f2=f1;
		f1=fn;	
	} 
	//���� 
	return fn;
}
