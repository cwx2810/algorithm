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
	//����x
	//������ÿ��*10��ĩβ���������ң���Ӹ������ϴ�/10����������������Ҳ����ĩβ�� 
	//������/10
	//����ʱ�ж��ǲ�������32λ 
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
