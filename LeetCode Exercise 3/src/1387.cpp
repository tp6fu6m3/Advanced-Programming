class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector< pair <int,int> > powers;
        for(int i=lo;i<=hi;i++){
            int power = 0, x = i;;
            while(x!=1){
                if(x%2==0){
                    x/=2;
                    power++;
                }
                else{
                    x = (3*x+1)/2;
                    power+=2;
                }
            }
            powers.push_back(make_pair(power, i));
        }
        sort(powers.begin(), powers.end());
        return powers[k-1].second;
    }
};