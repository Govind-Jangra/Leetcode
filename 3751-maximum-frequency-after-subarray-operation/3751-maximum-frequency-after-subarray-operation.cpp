class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // 1) Count how many elements are already k
        int n = (int)nums.size();
        int freqK = 0;
        unordered_set<int> distinctValues;
        for (int val: nums) {
            if (val == k) freqK++;
            distinctValues.insert(val);
        }
        
        // If all elements are the same as k, answer is n (but we still have to do one operation).
        // Actually, in that scenario freqK = n, we can't improve on that. 
        // The operation could be x=0 on a single-element subarray => final freq is still n. 
        // We'll handle that automatically below.
        
        // 2) For each distinct v != k, compute the maximum subarray difference
        //    difference = (# of v) - (# of k) in that subarray.
        
        int bestGain = 0;  // We'll track the best subarray gain across all v
        
        for (int v: distinctValues) {
            if (v == k) continue;  // No need to do subarray transform for v == k (x=0 doesn't help).
            
            // Build the array A_v
            // A_v[i] = +1 if nums[i] = v
            //         = -1 if nums[i] = k
            //         =  0 otherwise
            // Then run Kadane's to find max subarray sum
            int currentSum = 0;
            int maxSum = INT_MIN;
            
            for (int val: nums) {
                int contribution = 0;
                if (val == v) contribution = 1;
                else if (val == k) contribution = -1;
                
                currentSum += contribution;
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
                if (currentSum < 0) {
                    currentSum = 0;
                }
            }
            
            bestGain = max(bestGain, maxSum);
        }
        
        // If bestGain < 0, we won't use it. So net gain is max(0, bestGain).
        // Final answer is freqK + that net gain
        // But we must do an operation. If all bestGain are negative, we pick e.g. subarray of length 1 with x=0 => net gain = 0
        // So effectively we just do:
        
        bestGain = max(bestGain, 0);
        return freqK + bestGain;
    }
};
