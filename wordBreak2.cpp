#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//查字典，给定一个字符串和一个词典，问这个字符串能不能通过词典里的词组成
//啊哈哈哈，上面是上一题的描述，这题要求所有可能切分的词，是hard模式，我发现只要是求所有解的都是hard模式
//此题极难 
//这题的思路是先用二维dp求子串能否被切分，再用dfs求出所有解 
//子串的两个维度分别表示：i代表起始索引，j代表长度 
//子串有三种情况，一是直接在字典里，二是不在字典但是再切分的小子串在字典里，三是均不在字典里，找不到
//其中情况二因为要再切分，所以不用考虑，在情况一下用dfs求所有可能的切分，从i+j开始求 

//初始化二维dp数组存储子串能被切分成几段 
vector<vector<char>> dp;
//初始化返回数组，存储切分的子串
vector<string> ret;
//初始化压入数组的每个字符串
string val; 
vector<string> wordBreak(string s, vector<string>& wordDict) {
    //初始化dp第一维长度为给定字符串长度
    dp.resize(s.size());
    //遍历这个长度，给dp的第二维初始化为给定字符串长度+1，初始值都为0，表示不能切分 
    for(int i=0;i<s.size();i++) dp[i].resize(s.size()+1,0);	
    //双循环查字典，外层迭代子串长度，内层迭代子串开始索引，从0开始到总长减去子串长（索引从0一直移动到最后，但子串长始终存在）
    for(int j=1;j<=s.size();j++){
        for(int i=0;i<=s.size()-j;i++){
            //设置临时存储字符串，存储子串，防止下面调用函数时c++11报错 
            string tmp=s.substr(i,j);
            //第一种情况，调用包含方法，如果直接在字典中找到了子串
            if(contain(wordDict,tmp)){
                //设置切分为1
                dp[i][j]=1;
                //迭代下一个索引
                continue;
            }
            //如果不能直接找到，拆分，设k为子串中的子串长度，迭代k
            for(int k=1;k<j && k<s.size()-i;k++){
                //如果以k为划分可以找到两个词
                if(dp[i][k] && dp[i+k][j-k]){
                    //设置切分为2
                    dp[i][j]=2;
                    //跳出k的循环，迭代下一个索引
                    break;
                }
            }
        }
    }
    //corner case整个从0开始长度为总长，也就是整个串都不能切分，不用dfs了，直接返回
    if(dp[0][s.size()]==0) return ret;
    //调用dfs
    DFS(s,0);
    //返回dfs出的切片 
    return ret;
}
//包含方法，传入字典，字符串
bool contain(vector<string> &wordDict,string &s){
    //遍历字典中的每个词
    for(int i=0;i<wordDict.size();i++){
        //如果字符串和某个词相等，算查到了
        if(s==wordDict[i]) return true;
    }
    //遍历完整个词典都没找到，则没查到
    return false;
}
//dfs，传入给定字符串，开始下标 
void DFS(const string &s,int start){
    //如果开始下标已经等于字符串长度，即给定字符串遍历结束，压栈返回
    if(start==s.size()){
        ret.push_back(val);
        return;
    }
    //迭代所有可能的长度，从1到总长减去开始下标
    for(int i=1;i<=s.size()-start;i++){
        //如果可以切分成一段，即满足第一种情况（第二种要再切不用考虑），准备dfs字符串压栈 
        if(dp[start][i]==1){
        	//存储一开始的字符串长度，因为长度会改变，而后面递归完毕要用到初始长度 
            int oldLen=val.size();
            //根据题目要求，插到的词中以空格分开，所以如果已经查到了词，即压入数组的每个字符串长度不为0了，在后面附一个空格
            if(oldLen!=0) val.append(" ");
            //附加子串
            val.append(s.substr(start,i));
            //从（开始下标+刚才算过的可能子串长）这里做新的开始下标，继续dfs
            DFS(s,start+i);
            //dfs附加完所有子串返回到这里，因为是在后面附加的，因此每个子串包含了前一个子串，擦除原先的长度 
            val.erase(oldLen,string::npos);
        }
    }
}
