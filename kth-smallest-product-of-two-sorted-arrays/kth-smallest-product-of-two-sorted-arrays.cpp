class Solution {
public:
//     long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
//     }
    #define ll long long
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> &a=nums1;
        vector<int> &b=nums2;
        ll l=-1e11,r=1e11;
        int n=a.size();
        int m=b.size();
        if(n>m){
            swap(n,m);
            swap(a,b);
        }
        while(l<=r){
            ll mid=l+r>>1;
            ll cnt=0;
            for(int i=0;i<n;++i){
                ll x=a[i];
                if(x>=0){
                    int _l=0,_r=m-1;
                    while(_l<=_r){
                        int _mid=_l+_r>>1;
                        if(x*b[_mid]>mid)
                            _r=_mid-1;
                        else
                            _l=_mid+1;
                    }
                    cnt+=_l;
                }else{
                    int _l=0,_r=m-1;
                    while(_l<=_r){
                        int _mid=_l+_r>>1;
                        if(x*b[_mid]<=mid)
                            _r=_mid-1;
                        else
                            _l=_mid+1;
                    }
                    cnt+=m-_l;
                }
            }
            if(cnt>=k)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};