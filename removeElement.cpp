//给定一个数组，一个值，要求移除数组中等于这个值的元素，最后返回数组剩下元素的长度。
//利用两个变量，分别记录等于和不等于val的元素。 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	//初始化两个变量记录等于和不等于val的元素的数组下标 
        int i=0;
        int j=0;
        for(i=0;i<nums.size();i++){
        	//遍历给定数组，当遍历到的值等于移除值时，跳过 
            if(nums[i]==val){
                continue;
            }
            //此时剩下的遍历到的值都是不等于要移除值的，将这些值从0开始一个一个赋给新的记录下标j 
            nums[j]=nums[i];
            j++;
        }
        //题目要求返回长度，返回下标j即可 
        return j;
    }
};
