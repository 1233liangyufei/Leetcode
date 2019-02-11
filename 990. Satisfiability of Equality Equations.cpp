class Solution {
public:
    int uf[26]; //创建并查集数据结果
    bool equationsPossible(vector<string>& equations) {
        //该方法使用并查集实现
        for(int i=0;i<26;i++){
            uf[i]= i;//并查集初始化，根据并查集定义，数组内代表指向的根节点，初始时各个结点独立，根节点即为本身，所以赋值为自己
        }
        for(string e:equations){
            if(e[1] == '='){//当遇到相等情况时候，加入并查集，将e[3]的根也设置为e[0]的根
                uf[find(e[0]-'a')] = find(e[3] -'a');//e[i]-'a'即为英文字母对应的数字a为0,z为25
                 //uf[find(e[0] - 'a')] = find(e[3] - 'a');     
            }
        }
        for(string e:equations){
            if(e[1] == '!'){//当遇到不等情况时候，判断二者是否属于一个并查集，如果否则正确，继续排查，如果属于则失败，返回false
                if(find(e[0]-'a') == find(e[3]-'a')){
                    return false;
                }
            }
        }
        return true;
        
        
    }
    int find(int x){//通过递归找寻x所在并查集的根节点
        //return x == uf(x)?x:uf(x) = find(uf(x));
        //判断x的根节点是x吗，如果不是找x的相邻结点根节点是否是根节点，如果不是则不停递归下去直到找到根节点
        if(x!=uf[x]) {
            uf[x] =find(uf[x]);
        }
        return uf[x];
    }
};
