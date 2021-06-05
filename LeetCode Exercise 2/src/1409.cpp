class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> out, r;
        for(int i=0;i<queries.size();i++){
            int temp = queries[i]-1;
            for(int j=i-1;j>=0;j--){
                if(queries[j]==queries[i]){
                    queries[j] = 0;
                    temp = (i-j-1);
                    for(int k=0;k<r.size();k++){
                        if(r[k]>j){
                            temp--;
                        }
                    }
                    r.push_back(j);
                    break;
                }
                if(queries[j]>queries[i]){
                    temp++;
                }
            }
            out.push_back(temp);
        }
        return out;
    }
};