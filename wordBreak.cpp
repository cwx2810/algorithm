#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���ֵ䣬����һ���ַ�����һ���ʵ䣬������ַ����ܲ���ͨ���ʵ���Ĵ����
//��dpi��ʾ����Ϊi�ĺ����ַ����ܲ��ܱ��з֣������һ����j~i�����ó�������dp����Ϊdpi=dpj+���һ���� 
bool wordBreak(string s, vector<string>& wordDict) { 
	//��ʼ������dp����Ϊi��1��ʼһֱ�������ַ������ȣ������鱾����һ��0��Ԫ�أ����Գ�ʼ����СҪ+1����ʼ��Ϊfalse
	vector<bool> dp(s.size()+1,false);
	//corner case�ַ�������Ϊ0ʱҲ���ܲ鵽
	dp[0]=true;
	//˫ѭ�����ֵ�ƥ����ĸ����ѭ�����������ַ�������ѭ������ÿ��i�еݹ��j
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<i;j++){
			//���������tmp��ʱ�洢һ�����ַ�������Ȼ�ύ��oj�ᱨc++11���� 
			string tmp = s.substr(j, i - j);
			//����ݹ�ɹ��������һ����Ҳ�ܲ鵽���򳤶�Ϊi�ĺ����ַ��������з�
			//������ܾ�����ÿ��i�������ַ�������ʲô�ã���ʵ�㺢����Ϊ�������յ�ʱ��������Ϊ�������ֵģ��ز�����
			if(dp[j] && contain(wordDict,tmp)){
				//i��ÿ��j����������������j��ѭ����������һ��i
				dp[i]=true;
				break;
			}
		}
	}
	//����i������ɣ�������dp 
	return dp[s.size()];
}
//���������һ���ʵĺ���contain�������ֵ䣬�ַ�����˼·���ֵ��еĴʵ��������ַ���
bool contain(vector<string> &wordDict,string &s){
	//�����ֵ��е�ÿ����
	for(int i=0;i<wordDict.size();i++){
		//����ַ�����ĳ������ȣ���鵽��
		if(wordDict[i]==s) return true;
	}
	//����û�鵽
	return false; 
} 
 


//��ʱ��һ�ַ���û�������ڽ��ⱨ�����ѵ���һ�ֽ��ⷽ������������ֵ�һ�ַ����ֶ��ˡ��� 
bool wordBreak(string s, vector<string>& wordDict) {
	//description said nonempty,it's a lie 
    if(s.length()==0||wordDict.size()==0)
        return false;
    //��ʼ��ջ�����Ѿ��������ĸ�� 
    stack<int> st;
    //��ʼ��ջ���Ѿ����0����ĸ 
    st.push(0);
    //��ʼ��������飬�����true 
    vector<bool> visited(s.size() + 1, false);
    //ջ��Ϊ�վ�һֱ���� 
    while (!st.empty())
    {	//ȡջ�е�ǰ�������ĸ�� 
        int cur = st.top();
        st.pop();
        //����������ĸ�����ڸ����ַ�����˵�����ֵ��������ȫ�� 
        if (cur == s.size())
            return true;
        //���ֵ� 
        for (const string& w : wordDict)
        {	//��ʼ��iΪ������һ�β��Һ�Ӧ�е��ܲ��ҳ��� 
            const int i = cur + w.size();
            //���ȳ����˸���������Ѿ�������λ�ӵ���ĸ�ˣ�����������һ������ 
            if (i >= visited.size() || visited[cur + w.size()])
                continue;
            //�ֵ���Ĵ�w�͸����ַ���sÿ����ĸ����ƥ�䣬���û�в��ҵ����һ����ĸ���Ѿ�ƥ�䣬����ҳɹ� 
            if (!strncmp(w.c_str(), s.c_str() + cur, w.size()))
            {
                visited[i] = true;
                st.push(cur + w.size());
            }
        }
    }
    //ջΪ�գ�˵���Ѿ�ȫ�����꣬����ջû����ѹջ��ƥ�䲻��
    return false;
}


