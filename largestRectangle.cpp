#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int> &height);

int main(){
	int a[]={2,1,5,6,2,3};
    vector<int> A(a,a+6);
    int result=largestRectangleArea(A);
    cout<<result<<endl;
}



//��ֱ��ͼ�����������
//˼·��bar�ı�Ŵ�0��ʼ�����ѿ���������ĳ��bar�����������������bar�ĸ߶�������bar������͵ģ���˼���Ǿ����Աߵ�bar���� 
//��ô������bar��ʼ����߱����͵ĵ�һ��bar�����ln���ұ���rn
//����ͼ������������s=(rn-ln-1)*height��bar�ı�Ŵ�0��ʼ����Ϊ�������϶�����һ�������ʾbar��~ 
//��ô����ҵ���Щ������������һ�������stack��� 
//��barһ��һ��ѹջ����������һ����ջ��С��barʱ������ջ��bar������Ϊ���bar���������ʱrn���ұߵ�Сbar��ln�����ջ��bar
//�����˴˵���ջ��bar�����жϴ�ʱջ��bar��������ͼ�����������������s...ѭ������
//һ��ʼҪ�ڴ����barȺ����һ���߶�Ϊ0��bar������������bar�����һ��bar���ܵ���~ 
int largestRectangleArea(vector<int> &height){
	//���һ�������stack
	vector<int> s;
	//�ڴ�����������������0bar
	height.push_back(0);
	//��ʼ������͵ױ߱��
	int sum=0;
	int i=0;
	//ѭ��
	while(i<height.size()){
		//������������ѹջ
		if(s.empty() || height[i]>height[s.back()]){
			s.push_back(i);
			i++;
		} else{//����������bar��ջ����С������ 
			int t=s.back();
			s.pop_back();
			//��ջҪ���ǣ�i-���ǵ�ջ֮���ջ�� 
			sum=max(sum,height[t]*(s.empty()?i:i-s.back()-1)); 
		}
	} 
	return sum;
}  



