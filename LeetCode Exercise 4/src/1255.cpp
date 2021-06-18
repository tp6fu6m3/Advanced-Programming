class Solution {
public:
    int DFS(vector<string>& words, vector<int>& cnt_, vector<int>& score, int idx){
        if(idx>=words.size()){
            return 0;
        }
        int wScore = 0;
        vector<int> cnt(cnt_.begin(), cnt_.end());
        for(auto c:words[idx]){
            if(cnt[c-'a']==0){
                wScore = 0;
                break;
            }
            wScore += score[c-'a'];
            cnt[c-'a']--;
        }
        if(wScore==0){
            return DFS(words, cnt_, score, idx+1);
        }
        else{
            return max(DFS(words, cnt_, score, idx+1), wScore + DFS(words, cnt, score, idx+1));
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26);
        for(auto c:letters){
            cnt[c-'a']++;
        }
        return DFS(words, cnt, score, 0);
    }
};