class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        //该方法将K依次加入到数组中，属于大整数相加问题，如果转换成longlong也只能计算64位，无法通过样例，必须将K加到数组中，方法如下：
        for(int i=A.size()-1;i>=0&&K>0;i--){//自数组从右往左遍历
            A[i]+=K;    //将K与第i位相加
            K = A[i]/10;//通过这一操作获得进位后的K的去掉最后一位，如 A[i]=3，K=658,A[i]+K=661,通过次操作后，K成为66，余 1 则为A[i]；
            A[i] = A[i]% 10;
        }
       //当K位数多而A位数少时，如A为120，K为1000时，经过上面操作，A为120，K为1，仍剩余K,则将其自低位向高位插入，此时使用STL的inser方法 A.insert(位置,数值)  A.begin()为A初始位置
       while(K>0){
           A.insert(A.begin(),K%10);
           K/=10;
       }
        
        //返回数组A
        return A;
    }
};
