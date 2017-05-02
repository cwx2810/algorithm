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



void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int j=m-1;
	int k=n-1;
    for(int i=m+n-1;i>=0;i--){
    	if(j>=0 && k>=0){
    		if(nums1[j]>=nums2[k]){
    			nums1[i]=nums1[j];
    			j--;
			}else{
				nums1[i]=nums2[k];
				k--;
			}
		}else if(j>=0){
			nums1[i]=nums1[j];
			j--;
		}else{
			nums1[i]=nums2[k];
			k--;
		}
	}
}

