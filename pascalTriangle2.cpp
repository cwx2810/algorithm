class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> vals;
 		vals.resize(rowIndex+1,1);//Ҫ�������һ�еģ���ʼ��Ҫ��һ��
		for(int i=3;i<=rowIndex+1;i++){//������Ҫ����У�ǰ���ж���1������
			for(int j=i-1;j>=2;j--){//������Ҫ����У���ͷ�ͽ�β�����㣬Ҫ�����㣬�����´�Ҫ�õĺ�һ��Ԫ��
				vals[j-1]=vals[j-1]+vals[j-2];//���������кţ���Ϊ�±�Ҫ-1
			}
		}
		return vals;
    }
};
