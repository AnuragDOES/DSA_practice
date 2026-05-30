class Solution {
  public:
    int mergeSort(int l, int r, vector<int>& a){
        if(l>=r)return 0;
        int mid = (r-l)/2+l;
        int count=0;
        count=mergeSort(l, mid, a)+mergeSort(mid+1, r, a)+merge(l,mid,r,a);
        return count;
        
    }
    int merge(int l, int mid, int r, vector<int>& a){
        int i = l,j = mid+1,count = 0;
        vector<int> tempArr;
        while(i<=mid and j<=r){
            if(a[i]>a[j]){
                count+=mid-i+1; 
                tempArr.push_back(a[j]);
                j++;
            }
            else{
                tempArr.push_back(a[i]);
                i++;
            }
        }
        while(i<=mid){
            tempArr.push_back(a[i++]);
        }
        while(j<=r){
            tempArr.push_back(a[j++]);
        }
        for(int k=l;k<=r;k++){
            a[k] = tempArr[k-l];
        }
        return count;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(0, arr.size()-1,arr);
        
    }
};