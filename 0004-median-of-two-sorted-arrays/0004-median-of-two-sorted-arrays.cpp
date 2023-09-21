class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int count;
        int m = nums1.size();
        int n = nums2.size();

        double m1 = -1, m2 = -1;
        
        for(count=0; count<=(m+n)/2; count++)
        {
            m2=m1;
            
            if(i != m && j != n)
            {
                m1 = (nums1[i] > nums2[j]) ? nums2[j++] : nums1[i++];
            }
            else if(i<m)
            {
                m1 = nums1[i++];
            }
            else
            {
                m1 = nums2[j++];
            }
        }
        
        if((m+n)%2==0){
            return (m1+m2)/2;
        }
        else{
            return m1;
        }
    }
};