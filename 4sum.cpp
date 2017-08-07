#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target);

int main(){
	int a[]={-1,0,1,2,-1,-4};
    vector<int> A(a,a+6);
    int t=-6;
    vector<vector<int> > V=fourSum(A,t);
    for(int i=0;i<V.size();i++){
    	for(int j=0;j<V[i].size();j++){
    		cout<<V[i][j]<<" ";
		}
		cout<<endl;
	}
}


//4个数的和等于target，和3sum一毛一样，多一层循环 
//外层循环多了j循环 
vector<vector<int> > fourSum(vector<int> &num, int target) {
	//初始化返回数组 
    vector<vector<int> > ret;
    //corner case 给定数组不足4个元素 
    if(num.size()<4){
    	return ret;
	}
	//先排序 
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++){//i循环 
		for(int j=i+1;j<num.size();j++){//j循环 
			int k=j+1;
			int l=num.size()-1;
			while(k<l){//k、l循环 
				vector<int> tmp;//存储数组的数组 
				if(num[i]+num[j]+num[k]+num[l]==target){//满足条件压栈 
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);
					tmp.push_back(num[l]);
					ret.push_back(tmp);
					k++;
					l--;
					while(num[k]==num[k-1]){//判断k、l内部重复 
						k++;
					}
					while(num[l]==num[l+1]){
						l--;
					}
				}else if(num[i]+num[j]+num[k]+num[l]<target){//不满足条件移动游标 
					k++;
				}else{
					l--;
				}
			}
			while(num[j]==num[j+1]){//判断j内部重复 
				j++;
			}
		}
		while(num[i]==num[i+1]){//判断i内部重复 
			i++;
		}
	}
	return ret;
}


