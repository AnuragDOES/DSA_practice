class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int,int> sumIndex;
        int currSum = 0;
        int maxLen = 0;
        for(int i=0; i<arr.size(); i++){
            currSum += arr[i];
            if(currSum == 0){
                maxLen = max(maxLen,i+1);
            }
            if(sumIndex.count(currSum)){
                maxLen = max(maxLen,i-sumIndex[currSum]);
            }
            if(!sumIndex.count(currSum)){
                sumIndex[currSum] = i;
            }
        }
        return maxLen;
        
    }
};