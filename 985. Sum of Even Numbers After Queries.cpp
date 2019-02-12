class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        //本体直接使用暴力解法是O(n^2)复杂度，而我们可以先计算所有偶数的和，每次queries操作一下再更新一下even值然后赋给B数组
        vector<int> B(A.size());//初始化存放最终结果的数组，
        int even=0;//存放偶数和
        for(int j=0;j<A.size();j++){//先初步计算原始数组的偶数和
                if(A[j]%2==0){
                   even +=A[j];
                }
            }
        
        for(int i=0;i<queries.size();i++){//每次访问二维向量queries更新even
            int val = queries[i][0];//第一位是存储的数值
            int index = queries[i][1];//第二位存储要修改的位置
            int pre = A[index];//修改以前的值
            A[index]+=val;//修改
            int behind = A[index];//修改以后的值
            if(pre % 2 != 0 && behind%2 ==0 ){//如果之前是奇数，之后是偶数，则增加一个偶数
                even+=behind;//加上这个修改后的偶数
            }else  if(pre % 2 == 0 && behind%2 !=0 ){//如果之前是偶数，之后是奇数，则减少原来的偶数
                even-=pre;//减掉原来的数字
            }else  if(pre % 2 == 0 && behind%2 ==0 ){
                even+=(behind-pre);//如果都是偶数，则修正
            }
            B[i]=even;//将更正的even放人B中
            
            
        }
        
        
        return B;
    }
};
