#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�г������������е��Ӽ���
//�ñ���-���ݵķ���������Сʱ�����ɽ�3���Թ���ȡ����һ��Ԫ�أ���ʣ��Ԫ�ض��ǲ�·��ÿһ����·��Ҫ������һ�� 
 
//��ʼ�����ؼ���
vector<vector<int> > ret;
vector<vector<int>> subsets(vector<int>& nums) {
    //corner case��������Ϊ��
	if(nums.empty()) return ret;
	//����Ҫ���Ӽ�����������������
	sort(nums.begin(),nums.end());
	//�ռ���Ҳ���Ӽ��ϣ��ȵ���ѹ�뷵�ؼ���
	ret.push_back(vector<int>());
	//��ʼ���洢�Ӽ��ϵ�һά����
	vector<int> tmp;
	//���ù��캯��
	generate(0,tmp,nums);
	//����
	return ret; 
}
//�������캯�������뿪ʼԪ���±꣨����ÿ�λ��ݵ����+1�������㷨Ҫ������ÿ��Ԫ�أ�ͬʱ������ÿ��Ԫ�صĲ�·����һά��ά����
void generate(int start,vector<int> &tmp,vector<int> &nums){
	//����ʼԪ���±�������鳤�ȣ���ζ�ű����������е�Ԫ�أ�����
	if(start==nums.size()) return;
	//��������Ԫ��
	for(int i=start;i<nums.size();i++){
		//ѹջһά����
		tmp.push_back(nums[i]);
		//ѹջ��ά����
		ret.push_back(tmp);
		//��ȵݹ�
		generate(i+1,tmp,nums);
		//һ��·�ߵ�ͷ�����ص������ջ����һ��
		tmp.pop_back(); 
	} 
}
