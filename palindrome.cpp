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



//�жϻ�����
//˼·���Ѹ�������ÿһλ������д������ԭ�����ǻ�����
//��ô������Ƶݹ�����ÿ�θ�����/10������������һ�εݹ����*10��ֱ��������Ϊ0Ϊֹ 
bool isPalindrome(int x){
	//С��0�������ǻ�����
	if(x<0){
		return false;
	}else if(x==0){//����0�����ǻ�����
		return true;
	}else{
		//��ʼ����������ʱ�������ں����Ƚϡ���ʼ���ݹ��� 
		int tmp=x;
		int y=0;
		//ֻҪ��������Ϊ���һֱѭ��
		while(x!=0){
			y=y*10+x%10;
			x=x/10;
		}
		//�ݹ������ڸ�����������true 
		if(y==tmp){
			return true;
		}else{
			return false;
		}
	}
}



