class Solution {
public:
    int myAtoi(string s) {
        int out = 0, sign = 1;
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        while(isdigit(s[i]) != 0){
            if ( out > (INT_MAX-(s[i]-'0')) / 10){
                return (sign>0)?INT_MAX:INT_MIN;
            }
            out = 10*out + (s[i]-'0');
            i++;
        }
        return sign*out;
    }
};