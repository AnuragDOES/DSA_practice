class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, left = 0,currLen = 0;
        unordered_map<int,int> hm;
        for(int i=0; i<s.size(); i++){
            if(hm.contains(s[i]) and hm[s[i]]>=left){
                left = hm[s[i]]+1;
                currLen = i-left+1;
                hm[s[i]] = i;
            }else {
                hm[s[i]] = i;
                currLen++;
            }
            maxLen = max(currLen, maxLen);
        }
        return maxLen;
    }
};