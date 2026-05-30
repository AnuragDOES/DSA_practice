class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = nums[0], strength = 1;
        for(int i=1; i<nums.size(); i++){
            if(strength == 0){
                strength++;
                elem = nums[i];
                continue;
            }
            if(elem==nums[i]){
                strength++;
            }else{
                strength--;
            }
        }
        return elem;
    }
};