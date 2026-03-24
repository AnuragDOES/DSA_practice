class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> sumIndex;
        int currSum = 0;
        int maxLen = 0;
        for(int i=0; i<arr.size(); i++){
            currSum += arr[i];
            sumIndex.emplace(currSum, i);
            int key = currSum-k;
            if(key == 0 and maxLen<i+1){
                maxLen=i+1;
            }
            else if(key!=0){
                if(sumIndex.count(key)){
                    int subArrLen = i-sumIndex[key];
                    if(maxLen < subArrLen){
                        maxLen = subArrLen;
                    }
                }
            }
        }
        return maxLen;
        
    }
};