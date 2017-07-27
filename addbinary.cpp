#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�����������������ַ�����ӣ�Ҫ�����λ�������ַ���������ͬ�Ͳ�ͬ�������������char��int��ת�� 
string addBinary(string a, string b) {
    //corner caseĳ���ַ�������Ϊ0��������һ������
    if(a.size()==0) return b;
    if(b.size()==0) return a;
	//��ʼ�������ַ���
	string ret;
	//��ʼ����λ
	int carry=0;
	//��ʼ�������ַ��������±�
	int index1=a.size()-1;
	int index2=b.size()-1;
	//�����±����ӷ����㣬���±�ͬʱ��Чʱ������
	while(index1>=0 && index2>=0){
		//����ÿһλ���֣�Ϊ�����ַ�����ÿһλת����int��+��λ
		int num=(a[index1]-'0')+(b[index2]-'0')+carry;
		//��������ƽ�λ������һ�ε����� 
		carry=num/2;
		//�Ѳ��������ת���ɿɷ��صĶ�����
		num=num%2;
		//���������ַ����±�
		index1--;
		index2--;
		//���뵽�����ַ�������
		ret.insert(ret.begin(),num+'0');
	}
	//����������������飬�ѽ�λ����
	if(index1<0 && index2<0){
		if(carry==1){
			ret.insert(ret.begin(),carry+'0');
			//����
			return ret;
		}
	}
	//�������ַ�����һ��������һ������ʱ�������������һ�� 
	while(index1>=0){
		int num=(a[index1]-'0')+carry;
		carry=num/2;
		num=num%2;
		index1--;
		ret.insert(ret.begin(),num+'0');
	}
	//��һ������Ҳһ��
	while(index2>=0){
		int num=(b[index2]-'0'+carry);
		carry=num/2;
		num=num%2;
		index2--;
		ret.insert(ret.begin(),num+'0');
	}
	//�ٴ���ӽ�λ
	if(carry==1) ret.insert(ret.begin(),carry+'0');
	//���� 
	return ret;
}
