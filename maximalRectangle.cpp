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



//��matrix��1Ԫ�ع��ɾ��ε�������
//˼·����ÿһ�п���һ��ֱ��ͼ�ĵף�1����߶�Ϊ1,0����û�и߶ȣ�
//������ֱ��ͼ����������������ÿ��j��1�ĸ�����Ϊ�������������ÿ��Ԫ��~ 
int maximalRectangle(vector<vector<char> > &matrix){
	//�ж��л���Ϊ�� 
	if(matrix.empty() || matrix[0].empty()){
		return 0;
	}
	//��ʼ���������ֵ������ֱ��ͼ�������������height 
	int m=matrix.size();
	int n=matrix[0].size();
	vector<vector<int> > height(m,vector<int>(n,0));
	//forѭ��ѹ�������height
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//Ԫ��Ϊ0���߶�Ϊ0
			if(matrix[i][j]=='0'){
				height[i][j]=0;
			}else{//Ԫ��Ϊ1���߶ȵ�һ��Ϊ1��������Ϊǰһ��+1
				height[i][j]=(i==0)?1:height[i-1][j]+1;
			}
		}
	}
	//��ʼ��������
	int maxArea=0;
	//ѭ������ÿ�е����ֱ��ͼ�������
	for(int i=0;i<m;i++){
		maxArea=max(maxArea,largestRectangleArea(height[i]));
	}
	return maxArea;
}
//ֱ��ͼ������������� 
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



