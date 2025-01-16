class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(); int n2=nums2.size();
        if((n1%2==0) && (n2%2==0)) return 0;
        else if((n1%2!=0) && (n2%2!=0)){
            int ans=0; int pns=0;
            for(int i=0;i<n1;i++)
                ans=ans^nums1[i];
            for(int i=0;i<n2;i++)
                pns=pns^nums2[i];

            return ans^pns;
            
        }
        else if((n1%2==0) && (n2%2!=0)){
            int ans=0;
            for(int i=0;i<n1;i++)
                ans=ans^nums1[i];
            return ans;
        }   
        else{
            int pns=0;
            for(int i=0;i<n2;i++)
                pns=pns^nums2[i];
            return pns;
        }
    }
};