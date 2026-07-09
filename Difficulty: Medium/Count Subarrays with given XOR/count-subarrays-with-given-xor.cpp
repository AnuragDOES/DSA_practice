class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int> pastXOR;
        pastXOR[0] = 1;
        long count = 0;
        int currXOR = 0, key = 0;
        for(int i=0; i<arr.size(); i++){
            currXOR = currXOR^arr[i];
            key = k^currXOR;
            if(pastXOR.count(key)) {
                count += pastXOR[key];
            }
            //if key doesn't exist in hashmap, it will be created with value 0 and incremented by 1
            pastXOR[currXOR]++;
        }
        return count;
        
    }
};