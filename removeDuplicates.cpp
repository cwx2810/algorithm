//删除一个已排序数组的重复元素并返回最终长度（这种水题找不到水的地方，就让返回一个莫名其妙无意义的长度，还不如返回真实的数组） 
//用两个游标i和j来比较并移动 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	//corner case 给定数组为空 
        if(nums.size()==0){
            return 0;
        }
        //初始化游标j，也是我们最终返回的下标 
        int j=0;
        //初始化游标i，i从1开始，遍历数组和j（数组中第一个元素，下标0）比较 
        for(int i=1;i<nums.size();i++){
        	//如果和下标j的元素不相等，说明符合不重复的条件，j可以增加，赋值给j，反之相等，不移动j继续遍历i 
            if(nums[j]!=nums[i]){
                nums[++j]=nums[i];
            }
        }
        //题目要求返回数组长度，长度比下标多1，因此返回j+1 
        return j+1;
    }
};
