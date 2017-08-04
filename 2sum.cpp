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


//����һ�������һ��ֵ��Ҫ�����������������±꣬�����±��ֵ�������Ǹ���ֵ 
vector<int> twoSum(vector<int> &numbers, int target) {
	//��ʼ���������淵������
	vector<int> ret;
	//��ʼ��hashmap��keyΪ����Ԫ�أ�valueΪ�����±�
	unordered_map <int,int> hash;
	//corner case ��������Ϊ�� 
	if(numbers.size()<1){
		return ret;
	}
	//��������Ԫ���±� 
	for(int i=0;i<numbers.size();i++){
		//��֪һ��ֵ���Ա�ʾ����һ��ֵ������ÿ�α���Ԫ�غ��ҵ�Ӧ��ƥ���ֵ����hashmap���ң��ҵ�˵������ 
		int numberToFind=target-numbers[i];
		//û��һֱ�ߵ�hashmap�����˵���ҵ��ˣ����ҵ����±�value�ͱ������±�iѹ��vector
		if(hash.find(numberToFind)!=hash.end()){ 
			ret.push_back(hash[numberToFind]);
			ret.push_back(i);
		} else{
			//û�ҵ�����ӳ�����map
			//����Ҫ�����룬һ��ʼmap�п϶���û��ӳ��ģ��Ҳ����ģ��������룬�Ż��ڱ�����ĳһԪ��ʱ�ҵ�
			//�պ������ѹջ˳��Ҳ�ǵ��ŵģ���Ϊ��������i�ں����Ǵ��±꣬�ҵ������Ѿ��������ǰ��С�±�
			//��ϸ��Ħ������һ����ʡʱ��ռ������������������һ��ʼ��ʼ�������е�hashmap�����ǳ�ʼ��ӳ�䵽�պù��� 
			hash[numbers[i]]=i; 
		}
	}
	//���� 
	return ret;
}

