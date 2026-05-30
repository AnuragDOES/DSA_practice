class Solution {
public:
    double myPow(double x, int n) {
        long long(N) = n;
        if(N<0){
            N=0-N;
            x = 1/x;
        }
        if(N==1){
            return x;
        }else if(N==0){
            return 1;
        }
        double res=myPow(x,N/2);
        if(N%2==1){
            return x*res*res;
        }
        else
            return res*res;
    }
};