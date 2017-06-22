#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//任意给定数n表示节点数，求出所有二叉树排列方式
//和上一题求排列方式数量不同，这一题直接求排列方式，不过思路一样，只不过要建一个容器存放树，递归返回之而已 
 

vector<TreeNode*> generateTrees(int n) {
	//corner case 没有节点，这里要加一个边界条件，如果不加，到了下面递归就会返回一个[[]]，空中的空，程序通不过测试，应该返回[]
	//这也是我在解题报告里首度发现错误 
	vector<TreeNode*> ret; 
	if(n==0) return ret; 
    //返回函数，传入开始节点和结尾节点 
    return generate(1,n);
}
//构建返回函数
vector<TreeNode*> generate(int start,int stop){
	//初始化容器
	vector<TreeNode*> vs;
	//corner case 开始比结尾大，说明没有子树，压入空，返回空栈
	if(start>stop){
		vs.push_back(NULL);
		return vs;
	}
	
	//遍历所有子树
	for(int i=start;i<=stop;i++){
		//递归构建左子树 
		auto left=generate(start,i-1);
		//递归构建右子树
		auto right=generate(i+1,stop);
		//双循环遍历左右子树，要将他们压栈构成树
		for(int j=0;j<left.size();j++){
			for(int k=0;k<right.size();k++){
				//new根节点
				TreeNode* root=new TreeNode(i);
				//连接左子树
				root->left=left[j];
				//连接右子树
				root->right=right[k];
				//根节点压栈
				vs.push_back(root);
			}
		}
	}
	//返回栈	
	return vs;
}
 
