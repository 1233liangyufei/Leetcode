/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> res;//存储结果变量
        for(int i=0,j=0;i<A.size()&&j<B.size();){//遍历两个区间段，若有一个为空，则循环结束，推出循环
            if(A[i].end<B[j].start){//如果A的该区间末尾都没有比b的开头大，则难以匹配，需要将A进一个区间，反之同理
                i++;
            }else if(A[i].start>B[j].end){
                j++;
            }else{//在这种情况下，二者有交叉，取交集
                
                res.push_back({max(A[i].start,B[j].start),min(A[i].end,B[j].end)});//取交集，加入
                if(A[i].end>B[j].end){//取完当前交集后，如果A右端比B靠右，则B进1，反之同理
                    j++;
                }else //if(A[i].end<=B[j].end){
                {
                    i++;
                }
            }
                
        }
        return res;
    
        
        
    }
};
