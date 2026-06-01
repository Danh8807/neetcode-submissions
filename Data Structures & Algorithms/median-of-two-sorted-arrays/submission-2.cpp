class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A; 
        vector<int> B; 
        if( nums1.size() < nums2.size()){
            A = nums1;
            B = nums2; 
        }
        else{
            A = nums2;
            B = nums1;
        }
        int total = A.size() + B.size();
        int half = (total +1)/ 2;
        int l = 0;
        int r = A.size(); 

        while( l <= r){
            int i = (l+r)/2;
            int j = half - i;
            double Aleft = (i > 0? A[i-1] : INT_MIN);
            double Aright = (i < A.size()? A[i] : INT_MAX);
            double Bleft = (j > 0? B[j-1]: INT_MIN);
            double Bright = (j < B.size()? B[j] :INT_MAX);

            if( Aleft <= Bright && Bleft <= Aright){
                if( total%2 != 0 ){
                   return max(Aleft, Bleft); 
                }

                return (max(Aleft,Bleft) + min(Aright,Bright))/2.0;
            }
            else if(Aleft > Bright){
                r = i -1;
            }      
            else{
                l = i +1;
            }
        } 
        return -1;
    }
};
