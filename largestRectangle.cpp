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



//求直方图中最大矩形面积
//bar的编号从0开始，对任意bar，以它为准最大面积矩形中这个bar的高度肯定是矩形所有bar中最低的 
//那么设从这个bar开始，左边比他低的第一个bar编号是ln，右边是rn，他们之间的就是最大面积，因为只有比这个bar还低才导致面积不能再扩大 
//画个图可以算出，面积s=(rn-ln-1)*height，bar的编号从0开始，因为传进来肯定是用一个数组表示bar们~ 
//那么如何找到这些参数，这里有一个神奇的stack设计 
//将bar依次压栈，当遇到第一个比栈顶小的bar时，弹出栈顶bar并以它为最低bar算面积，此时rn是右边的第一个小bar，ln是现在的左边栈顶bar
//算完了此弹出栈顶bar，再判断此时栈顶bar，它还比第一个bar大就继续弹出并用它计算s...循环往复
//一开始要在传入的bar群最后加一个高度为0的bar，这样本来的bar中最后一个bar才能弹出~ 
int largestRectangleArea(vector<int> &height){
	//设计一个神奇的stack
	vector<int> s;
	//在传入的数组参数最后加上0bar
	height.push_back(0);
	//初始化面积和底边编号
	int sum=0;
	int i=0;
	//循环
	while(i<height.size()){
		//不满足条件就压栈（要压栈的bar始终大于栈顶bar） 
		if(s.empty() || height[i]>height[s.back()]){
			s.push_back(i);
			i++;
		} else{//满足遇到的bar比栈顶的小，弹出 
			int t=s.back();
			s.pop_back();
			//空栈要考虑，i-的是弹栈之后的栈顶 
			sum=max(sum,height[t]*(s.empty()?i:i-s.back()-1)); 
		}
	} 
	return sum;
}  



