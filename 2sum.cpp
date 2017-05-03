#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(){
	int a[]={1,2,5,7,9};
    vector<int> A(a,a+5);
	int t=7;
	vector<int> ret=twoSum(A,t);
	for(int i=0;i<ret.size();i++){
		cout<<ret[i]<<" ";
	}
}



vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> ret;//�½��������淵������
	unordered_map <int,int> hash;//�½�hashmap��keyΪ����Ԫ�أ�valueΪ�����±�
	if(numbers.size()<1){
		return ret;
	}
	for(int i=0;i<numbers.size();i++){
		int numberToFind=target-numbers[i];//��������Ԫ�أ���֪һ������һ��
		if(hash.find(numberToFind)!=hash.end()){//�ҵ��ˣ���value��iѹ��vector 
			ret.push_back(hash[numberToFind]);
			ret.push_back(i);
		} else{
			hash[numbers[i]]=i;//û�ҵ����Ѽ�ֵ�Դ���map 
		}
	}
	return ret;
	 
}

