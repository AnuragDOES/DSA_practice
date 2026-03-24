class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long sumArr = 0;
        long long N = arr.size()+1;
        long long sumN = (N*(N+1))/2;
        for(int x: arr){
            sumArr+=x;
        }
        return sumN-sumArr;
    }
};