class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        


        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2<n1){return findMedianSortedArrays(nums2,nums1);}
        // to make sure complexity is o(log(min(m,n))) 
        int st=0,en=n1;

        while(st<=en){
            int cut1 = (st+en)/2;
            int cut2 = (n1+n2+1)/2 - cut1; // nums1:6,nums2:5, cut1 at 3,cut2 at 3

            double l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            double l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            double r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            double r2 = cut2==n2 ? INT_MAX : nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2!=0){
                  return   max(l1,l2);
                }
                return (max(l1,l2)+min(r1,r2))/2.0;
            }else if(l1>r2){
                en = cut1-1;
            }else{
                st = cut1+1;
            }

        }
        return -1;


    }
};