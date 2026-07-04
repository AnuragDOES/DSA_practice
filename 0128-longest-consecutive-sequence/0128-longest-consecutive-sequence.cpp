class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int maxSeq=0;
        for (int x: nums)
        s.insert(x);
        for(int x: s){
            if(s.contains(x-1)) continue;
            else{
                int seq=1;
                while(true){
                    if(s.contains(++x))seq++;
                    else break;
                }maxSeq = max(seq, maxSeq);
            }
        }
        return maxSeq;
    }
};