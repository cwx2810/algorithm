class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size()==0){
    		return 0;
    	}
        int j=0;
        int sum=0;
        for(int i=1;i<nums.size();i++){
        	if(nums[j]==nums[i]){
        		sum++;
        		if(sum<2){
        			nums[++j]=nums[i];
        		}
        	}else{
        		nums[++j]=nums[i];
        		sum=0;
        	}
        }
        return j+1;
    }
};