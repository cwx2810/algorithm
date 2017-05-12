#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target);

int main(){
	int a[]={1,3,5,7};
	int b[]={10,11,16,20};
	int c[]={23,30,34,50};
	vector<int> A(a,a+4);
	vector<int> B(b,b+4);
	vector<int> C(c,c+4);
	vector<vector<int> > matrix;
	matrix.push_back(A);
	matrix.push_back(B);
	matrix.push_back(C);
	int target=10;
	cout<<searchMatrix(matrix,target);
}



//判断矩阵中有没有元素值等于给定值 
//思路，固定右上角元素，初始给定row=0，col=最大，操作这两个加减判断有没有 
bool searchMatrix(vector<vector<int> > &matrix, int target){
	//corner case
	if(matrix.size()==0){
		return false;
	}
	if(matrix[0].size()==0){
		return false;
	}
	//初始化搜索位子
	int row=0;
	int col=matrix[0].size()-1;
	//while循环到最左下角越界
	while(row<matrix.size() && col>=0){
		if(matrix[row][col]<target){
			++row;
		}else if(matrix[row][col]>target){
			--col;
		}else{
			return true;
		}
	} 
	return false;
} 
