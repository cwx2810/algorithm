#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//С���Ŷ����ǹ���ÿ������һ�����ȼ��ߵ����Ǳ��ھӶ࣬������Ҫ�����ǹ� 
//��ÿ�˷���һ���������ң��������ı�ǰһ���ȼ��ߣ��Ͷ��һ�����ٴ��ҵ��󣬱������ı�ǰһ���ȼ��ߣ��ǹ��ֱ�ǰһ����
//�͸�����ǰһ������һ��Ϊֹ 
int candy(vector<int>& ratings) {
    //��ʼ��ÿ�˷����ǹ�����
    vector<int> candys;
	//��ʼ�����飬��С���ڸ������飬ÿ����ƽ����һ��
	candys.resize(ratings.size(),1);
	//�������ұ���
	for(int i=1;i<ratings.size();i++){
		//�����ǰ�ȼ��ߣ����ǰһ����һ���ǹ�
		if(ratings[i]>ratings[i-1]) candys[i]=candys[i-1]+1;
	}
	//�����������
	for(int i=ratings.size()-2;i>=0;i--){
		//�����ǰ�ȼ��ߣ����ұ�ǰһ���ǹ��٣����ǹ�������ǰһ����һ��
		if(ratings[i]>ratings[i+1] && candys[i]<=candys[i+1]) candys[i]=candys[i+1]+1;
	}
	//��ʼ�������ǹ�������
	int ret=0;
	//�����ǹ����飬����������
	for(int i=0;i<candys.size();i++) ret+=candys[i];
	//���� 
	return ret;
}
