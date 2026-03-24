class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,curr=0;
        for(int x: nums){
            if(x==1){
                curr+=1;
                if(curr>max){
                    max = curr;
                }
            }
            if(x==0){
                curr=0;
            }
        }
        return max;
    }
};