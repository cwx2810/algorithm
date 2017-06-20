#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��˹�����ǴӶ��������·���ͣ���ÿ����һ��ֻ��ѡ���ڵ�Ԫ��
//ע���и������⣬����ÿ��Ҫ�Ӻ���ǰ�� 

int minimumTotal(vector<vector<int>>& triangle) {
    //��ʼ����
    int row=triangle.size();
	//corner case ��Ϊ0
	if(row==0) return 0;
	//��ʼ���м�����������飨����ÿ��Ԫ����С·����Ϊ���ֵ
	vector<int> total(row,INT_MAX);
	//��ʼ���м����������һ��ֵ
	total[0]=triangle[0][0];
	//��ʼ�����ر���Ϊ���ֵ 
	int minitotal=INT_MAX;
	//����
	for(int i=1;i<row;i++){
		for(int j=i;j>=0;j--){
			if(j==0){
				//�����ÿ�п�ͷ����j=0��Ҫ������㣬ֱ������һ��ļ���һ��ļ���
				total[j]=total[j]+triangle[i][j];
			}else{
				//�����м䣬��������̬�滮��ȡ��һ��С�ļ���һ���
				total[j]=min(total[j-1],total[j])+triangle[i][j];
			}
		}
	}
	//����ÿ��·��������ֵΪ��С·�� 
	for(int i=0;i<row;i++){
		minitotal=min(minitotal,total[i]);
	}
	return minitotal;
}
