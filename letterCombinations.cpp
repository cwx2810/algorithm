#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//有一个电话键盘，随机抽取上面一些数字，要求给出抽取出的数字里所有的字母组合
//建立dic，对于每一个数字，在dic中查找它对应的字母 
 

vector<string> letterCombinations(string digits) {
    //初始化返回数组
    vector<string> ret;
	//初始化dic
	vector<string> dic;
	//初始化返回数组中每个字母组合（主要为了压栈方便，之后把下面的字典压到这个组合，再把此组合压到ret） 
	string tmp;
	//下标代表0~9，压入所有的字母组合给每一个下标
	dic.push_back(" ");
	dic.push_back(" ");//0和1没有字母
	dic.push_back("abc");
	dic.push_back("def");
	dic.push_back("ghi");
	dic.push_back("jkl");
	dic.push_back("mno");
	dic.push_back("pqrs");
	dic.push_back("tuv");
	dic.push_back("wxyz"); 
	//corner case 给定digits为空 
	if(digits=="") return ret;
	//调用组合函数
	combinations(ret,tmp,digits,dic,0);
	//返回 
	return ret;
}
//构建组合函数，传入返回数组，数组中每个字母组合，给定数字，字典，遍历深度（给定数字每一位的下标） 
void combinations(vector<string> &ret,string tmp,string digits,vector<string> dic,int level){
	//遍历完所有给定数字（深度等于给定数字长度），压栈返回
	if(level==digits.size()){
		ret.push_back(tmp);
		return;
	}
	//初始化字典查找下标为给定数字对应的字符串转int
	int index=digits[level]-'0';
	//迭代相压栈应字典下标内查找到的所有字母
	for(int i=0;i<dic[index].size();++i){
		//字母压栈
		tmp.push_back(dic[index][i]);
		//深度递归
		combinations(ret,tmp,digits,dic,level+1);
		//递归超过给定数字长度，返回到这里，弹栈
		tmp.pop_back();
	}
}
