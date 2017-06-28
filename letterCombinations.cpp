#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//��һ���绰���̣������ȡ����һЩ���֣�Ҫ�������ȡ�������������е���ĸ���
//����dic������ÿһ�����֣���dic�в�������Ӧ����ĸ 
 

vector<string> letterCombinations(string digits) {
    //��ʼ����������
    vector<string> ret;
	//��ʼ��dic
	vector<string> dic;
	//��ʼ������������ÿ����ĸ��ϣ���ҪΪ��ѹջ���㣬֮���������ֵ�ѹ�������ϣ��ٰѴ����ѹ��ret�� 
	string tmp;
	//�±����0~9��ѹ�����е���ĸ��ϸ�ÿһ���±�
	dic.push_back(" ");
	dic.push_back(" ");//0��1û����ĸ
	dic.push_back("abc");
	dic.push_back("def");
	dic.push_back("ghi");
	dic.push_back("jkl");
	dic.push_back("mno");
	dic.push_back("pqrs");
	dic.push_back("tuv");
	dic.push_back("wxyz"); 
	//corner case ����digitsΪ�� 
	if(digits=="") return ret;
	//������Ϻ���
	combinations(ret,tmp,digits,dic,0);
	//���� 
	return ret;
}
//������Ϻ��������뷵�����飬������ÿ����ĸ��ϣ��������֣��ֵ䣬������ȣ���������ÿһλ���±꣩ 
void combinations(vector<string> &ret,string tmp,string digits,vector<string> dic,int level){
	//���������и������֣���ȵ��ڸ������ֳ��ȣ���ѹջ����
	if(level==digits.size()){
		ret.push_back(tmp);
		return;
	}
	//��ʼ���ֵ�����±�Ϊ�������ֶ�Ӧ���ַ���תint
	int index=digits[level]-'0';
	//������ѹջӦ�ֵ��±��ڲ��ҵ���������ĸ
	for(int i=0;i<dic[index].size();++i){
		//��ĸѹջ
		tmp.push_back(dic[index][i]);
		//��ȵݹ�
		combinations(ret,tmp,digits,dic,level+1);
		//�ݹ鳬���������ֳ��ȣ����ص������ջ
		tmp.pop_back();
	}
}
