//求帕斯卡三角，主要要掌握这个特殊二维数组的规律，每行元素和行号相等，第一个和最后一个元素和行号相等，中间的也有递归公式 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	//初始化保存帕斯卡三角的返回数组 
		vector<vector<int>> vals;
		//定义数组长度 
		vals.resize(numRows);
		//循环遍历数组，给其赋值 
        for(int i=0;i<numRows;i++){
        	//初始化每个元素的第二维长度为行号+1，因为第k层有k个元素，而i是从0开始的，所以要+1 
			vals[i].resize(i+1);
			//每行的开始和结尾元素总是1 
			vals[i][0]=1;
			vals[i][vals[i].size()-1]=1;
			//遍历每行中间的元素，从1到size-2 
			for(int j=1;j<vals[i].size()-1;j++){
				//地推公式是，本层元素=上一层同一位子的元素+上一层前一个位子的元素 
				vals[i][j]=vals[i-1][j-1]+vals[i-1][j];
			}
		}
		//返回 
		return vals;
    }
};
