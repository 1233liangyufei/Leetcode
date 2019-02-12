class Solution {
public:
    //这个问题是个滑动窗口问题，如果直接做需要三个指针，其中一个记录是否正好含有K个不同的值，本题中我们将这个问题放大，通过求得最多含有K个不同数字的连续字串来，通过最多K个与最多K-1个相减来得到所求结果
    int subarraysWithKDistinct(vector<int>& A, int K) {
        //通过最多K个与最多K-1个相减得到结果
        return atMostK(A,K)-atMostK(A,K-1);
    }
    int atMostK(vector<int>& A, int K){//该函数计算含有最多K个不同数字的字串数量
        int i = 0;//记录滑动窗口起点
        int res = 0;//记录结果
        vector<int> count(A.size() + 1);//数组更加快速一些
        //unordered_map<int, int> count;//一个map映射，用来记录数字对应出现的次数
        for(int j=0;j<A.size();j++){//滑动窗口的右边界，自左边滑动至末尾
            if(count[A[j]]==0){//如果A[j]对应数字没有出现过
                K--;//K是用来反向记录当前滑动窗口所含有的不同的数字，减掉次数为含有的不同数字，当K为零时为最多含有的字串，但是如1,2,1,2,3 当K为0时仍可以滑动
                count[A[j]]++;
            }else{
                count[A[j]]++;//将A[j]记录加一
            }
            while(K<0){//如果K<0说明窗口容纳不下，需要左边界减小知道K==0
                count[A[i]]--;//i退出窗口，记录--
                if(count[A[i]]==0){//如果记录减到0，则则容量减少，K++，
                    K++;
                }
                i++;//窗口左滑
            }
            res+=j-i+1;//以1，2，3为例子，一个大小为3的以J为结尾的滑动窗口子序列正好也是3： 123，23，3，即为j-1+1，通过依次相加末尾为A[j]的数组的子序列，可得最终结果
            
            
        }
        return res;
    }
};
