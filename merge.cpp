#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(){
	int a[]={1,2,5,7,9};
	int b[]={1,3,2,6};
    vector<int> A(a,a+5); 
    vector<int> B(a,a+4); 
	merge(A,5,B,4);
	for(int p=0;p<A.size();p++){
		cout<<A[p]<<" ";
	}
}


//合并两个有序数组A、B 
//题目中说数组A有足够大的空间，因此我们从最后一个元素往前遍历，比较两个数组元素大小，大的存进去
//最后如果哪一个数组有剩余就存那个数组即可 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	//初始化遍历两个数组的下标 
	int j=m-1;
	int k=n-1;
	//初始化要保存进去的下标，从后往前遍历 
    for(int i=m+n-1;i>=0;i--){
    	//如果两个数组都存在 
    	if(j>=0 && k>=0){
    		//哪边大就把哪边存入数组，同时移动下标 
    		if(nums1[j]>=nums2[k]){
    			nums1[i]=nums1[j];
    			j--;
			}else{
				nums1[i]=nums2[k];
				k--;
			}
		}else if(j>=0){//如果只剩一边了，那只插入这一边的，同时移动下标 
			nums1[i]=nums1[j];
			j--;
		}else{
			nums1[i]=nums2[k];
			k--;
		}
	}
}

