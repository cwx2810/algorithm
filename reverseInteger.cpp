#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��תһ��int���֣�����32λ����0 
int reverse(int x) {
    //��ʼ��longlong���ͷ������֣���Ϊ���жϾ�Ҫ����32λ��
    long long ret=0;
	//����x
	while(x){
		//������ÿ��*10��ĩβ���������ң���Ӹ������ϴ�/10����������������Ҳ����ĩβ�� 
		ret=ret*10+x%10;
		//������/10
		x/=10;
	}
	//����ʱ�ж��ǲ�������32λ 
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
