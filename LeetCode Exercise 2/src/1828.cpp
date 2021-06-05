class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> out(queries.size(), 0);
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<points.size();j++){
                if(pow((queries[i][0]-points[j][0]),2) + pow(queries[i][1]-points[j][1],2) <= pow((queries[i][2]),2))
                    out[i]++;
            }
        }
        return out;
    }
};