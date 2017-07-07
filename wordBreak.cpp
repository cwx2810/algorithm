#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//查字典，给定一个字符串和一个词典，问这个字符串能不能通过词典里的词组成
//设dpi表示长度为i的孩子字符串能不能被切分，把最后一个词j~i单独拿出来，则dp方程为dpi=dpj+最后一个词 
bool wordBreak(string s, vector<string>& wordDict) { 
	//初始化返回dp，因为i从1开始一直到给定字符串长度，而数组本身还有一个0号元素，所以初始化大小要+1，初始都为false
	vector<bool> dp(s.size()+1,false);
	//corner case字符串长度为0时也算能查到
	dp[0]=true;
	//双循环查字典匹配字母，外循环迭代给定字符串，内循环迭代每个i中递归的j
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<i;j++){
			//这里必须用tmp临时存储一下子字符串，不然提交到oj会报c++11错误 
			string tmp = s.substr(j, i - j);
			//如果递归成功并且最后一个词也能查到，则长度为i的孩子字符串可以切分
			//这里可能觉得算每个i（孩子字符串）有什么用？其实算孩子是为了算最终的时候孩子是作为条件出现的，必不可少
			if(dp[j] && contain(wordDict,tmp)){
				//i中每个j都符合条件，跳出j的循环，迭代下一个i
				dp[i]=true;
				break;
			}
		}
	}
	//所有i迭代完成，返回总dp 
	return dp[s.size()];
}
//构建查最后一个词的函数contain，传入字典，字符串，思路是字典中的词等于整个字符串
bool contain(vector<string> &wordDict,string &s){
	//遍历字典中的每个词
	for(int i=0;i<wordDict.size();i++){
		//如果字符串和某个词相等，算查到了
		if(wordDict[i]==s) return true;
	}
	//否则没查到
	return false; 
} 
 


//当时第一种方法没看懂，在解题报告里搜的另一种解题方法，看到最后发现第一种方法又懂了…… 
bool wordBreak(string s, vector<string>& wordDict) {
	//description said nonempty,it's a lie 
    if(s.length()==0||wordDict.size()==0)
        return false;
    //初始化栈保存已经查过的字母数 
    stack<int> st;
    //初始化栈，已经查过0个字母 
    st.push(0);
    //初始化标记数组，查过置true 
    vector<bool> visited(s.size() + 1, false);
    //栈不为空就一直迭代 
    while (!st.empty())
    {	//取栈中当前查过的字母数 
        int cur = st.top();
        st.pop();
        //如果查过的字母数等于给定字符串，说明在字典里查完了全部 
        if (cur == s.size())
            return true;
        //查字典 
        for (const string& w : wordDict)
        {	//初始化i为马上下一次查找后应有的总查找长度 
            const int i = cur + w.size();
            //长度超过了给定数组或已经查过这个位子的字母了，跳过，找下一个单词 
            if (i >= visited.size() || visited[cur + w.size()])
                continue;
            //字典里的词w和给定字符串s每个字母依次匹配，如果没有查找到最后一个字母就已经匹配，则查找成功 
            if (!strncmp(w.c_str(), s.c_str() + cur, w.size()))
            {
                visited[i] = true;
                st.push(cur + w.size());
            }
        }
    }
    //栈为空，说明已经全部查完，弹了栈没有再压栈，匹配不上
    return false;
}


