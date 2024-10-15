class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();  

        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }

        int st = 0,en = n1;

        while(st<=en){
            int mid1 = (st+en)/2;
            int mid2 = (n1+n2+1)/2 - mid1;  //  (n1+n2+1)/2 gives total number of elements in left partition in combined array 1,2,3 - (2+1+1)/2 = 2 elements in left partition of combined array

            double low1 = mid1 == 0 ? INT_MIN : nums1[mid1-1]; // cut is just before mid point 
            double low2 = mid2 == 0 ? INT_MIN : nums2[mid2-1];
            double high1 = mid1 == n1? INT_MAX : nums1[mid1];
            double high2 = mid2 == n2? INT_MAX : nums2[mid2];


            if(low1 <= high2 && low2<=high1){
                if((n1+n2)%2==0){return (max(low1,low2)+min(high1,high2))/2;}
                return max(low1,low2);
            }else if(low1 <= high2){
                st = mid1+1;
            }else{
                en = mid1-1;
            }
        }
        return 0;
    }
};