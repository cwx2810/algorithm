//removeDuplicates的升级版，这次允许有两个重复元素
//建立一个计数器记录重复次数，同样建立两个游标
//当重复有2次以上时，移动探针游标，不移动返回数组游标，反之移动返回数组游标，计数器清零 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	//corner case给定数组为空 
    	if(nums.size()==0){
    		return 0;
    	}
    	//初始化返回数组游标 
        int j=0;
        //初始化计数器 
        int sum=0;
        //初始化探针游标，遍历数组 
        for(int i=1;i<nums.size();i++){
        	//当遇到重复元素时 
        	if(nums[j]==nums[i]){
        		//计数器增加 
        		sum++;
        		if(sum<2){
        			//若重复次数小于2，移动赋值返回数组 
        			nums[++j]=nums[i];
        		}
        	}else{
        		//否则元素不重复，更要移动赋值返回数组 
        		nums[++j]=nums[i];
        		//计数器记录重复次数，清零 
        		sum=0;
        	}
        }
        //返回数组长度，为下标加一 
        return j+1;
    }
};
