#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//�г������������е��Ӽ��ϣ��������Ͽ������ظ�Ԫ�� 
//ͬ�����Թ��������������ظ�Ԫ��Ҫ���� 
 
//��ʼ�����ؼ���
vector<vector<int>> ret;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //corner case ��������Ϊ��
    if(nums.empty()) return ret;
	//������
	sort(nums.begin(),nums.end());
	//ѹ���Ӽ�
	ret.push_back(vector<int>());
	//��ʼ��һά�Ӽ�
	vector<int> tmp;
	//���ù��캯��
	generate(0,tmp,nums);
	//���� 
	return ret;
}
//�������캯�������뼯�Ͽ�ʼԪ���±꣬һά�Ӽ��������Ӽ� 
void generate(int start,vector<int> &tmp,vector<int> &nums){
	//��ʼ�±���ڼ��ϳ��ȣ�������ϣ�����
	if(start==nums.size()) return;
	//��ʼ����
	for(int i=start;i<nums.size();i++){
		//ѹջһά����
		tmp.push_back(nums[i]);
		//ѹջ���ؼ���
		ret.push_back(tmp);
		//��ȵݹ�
		generate(i+1,tmp,nums);
		//������ͷ�����������ջ����һ��·
		tmp.pop_back();
		//������ͬ��Ԫ��
		while(i<nums.size()-1&&nums[i]==nums[i+1]) i++;
	}
}
 
