class Solution {
public:
    int mergeCount(int l, int r, vector<int>& arr){
        if(l>=r)return 0;
        int mid = l+(r-l)/2;
        return mergeCount(l, mid, arr) + mergeCount(mid+1, r, arr) + merge(l, mid, r, arr);
    }
    int merge(int l, int mid, int r, vector<int>& arr){
        int i=l, j=mid+1;
        //counting revers pairs in sub arrays
        int count = 0;
        while(i<=mid and j<=r){
            if(arr[i]>2*long(arr[j])){
                count+=mid-i+1;
                j++;
            }
            else i++;
        }
        //vanilla merging
        vector<int> tempArr;
        i=l,j=mid+1;
        while(i<=mid and j<=r){
            if(arr[i]>arr[j]){
                tempArr.push_back(arr[j]);
                j++;
            }else{
                tempArr.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid){
            tempArr.push_back(arr[i++]);
        }
        while(j<=r){
            tempArr.push_back(arr[j++]);
        }
        for(int k=l; k<=r; k++){
            arr[k]=tempArr[k-l];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeCount(0, nums.size()-1, nums);
    }
};