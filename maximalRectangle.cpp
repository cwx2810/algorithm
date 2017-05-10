#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int maximalRectangle(vector<vector<char> > &matrix);
int largestRectangleArea(vector<int> &height);

int main(){
	char a[]={"10100"};
	char b[]={"10111"};
	char c[]={"11111"};
	char d[]={"10010"};
    vector<vector<char> > m;
    vector<char> e(a,a+5);
    vector<char> f(b,b+5);
    vector<char> g(c,c+5);
    vector<char> h(d,d+5);
    m.push_back(e);
    m.push_back(f);
    m.push_back(g);
    m.push_back(h);
//    for(int i=0;i<m.size();i++){
//    	for(int j=0;j<m[i].size();j++){
//    		cout<<m[i][j]<<" ";
//		}
//		cout<<endl;
//	}
    int result=maximalRectangle(m);
    cout<<result<<endl;
}



//求matrix中1元素构成矩形的最大面积
//思路：将每一行看做一个直方图的底，1代表高度为1,0代表没有高度，
//利用求直方图最大矩形面积，先求出每个j中1的个数作为传入数组参数的每个元素~ 
int maximalRectangle(vector<vector<char> > &matrix){
	//判断行或列为空 
	if(matrix.empty() || matrix[0].empty()){
		return 0;
	}
	//初始化行列最大值、传给直方图函数的数组参数height 
	int m=matrix.size();
	int n=matrix[0].size();
	vector<vector<int> > height(m,vector<int>(n,0));
	//for循环压入参数给height
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//元素为0，高度为0
			if(matrix[i][j]=='0'){
				height[i][j]=0;
			}else{//元素为1，高度第一行为1，其余行为前一行+1
				height[i][j]=(i==0)?1:height[i-1][j]+1;
			}
		}
	}
	//初始化最大面积
	int maxArea=0;
	//循环调用每行的最大直方图矩形面积
	for(int i=0;i<m;i++){
		maxArea=max(maxArea,largestRectangleArea(height[i]));
	}
	return maxArea;
}
//直方图最大矩形面积函数 
int largestRectangleArea(vector<int> &height){
	vector<int> s;
	height.push_back(0);
	int i=0;
	int sum=0;
	while(i<height.size()){
		if(s.empty() || height[i]>height[s.back()]){
			s.push_back(i);
			i++;
		}else{
			int t=s.back();
			s.pop_back();
			sum=max(sum,height[t]*(s.empty()?i:i-s.back()-1));
		}
	}
	return sum;
}



