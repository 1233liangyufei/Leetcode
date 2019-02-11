class Solution {
public:
    int brokenCalc(int X, int Y) {
        //正向考虑不好考虑，我们可以逆向思考，由Y变到X需要几步，Y到的操作为Y+1或者Y/2；
        //当Y<X时，只能进行嫁衣操作知道等于X所以操作次数为X-Y;
        //当Y>X时，可以分两种情况考虑当Y只有为偶数时候，才能Y/2，
        //而Y+1任何时候都可以，我们分析一下当(Y+1+1)/2 比 （Y/2）+1 节省次数，
        //所以经分析得，当Y为偶数时/2  Y为奇数是+1
        int res = 0;
        while(Y > X){
            if(Y%2==0){
                Y/=2;
                res++;
            }
            else{
                Y+=1;
                res++;
            }
        }
        return res + X - Y;
    }
};
