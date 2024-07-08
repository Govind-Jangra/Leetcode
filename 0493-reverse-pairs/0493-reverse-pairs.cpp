class Solution {
public:
    void merge(vector<long long> &arr, long long low, long long mid, long long high) {
    vector<long long> temp;
    long long left = low;
    long long right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (long long i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

long long countPairs(vector<long long> &arr, long long low, long long mid, long long high) {
    long long right = mid + 1;
    long long cnt = 0;
    for (long long i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

long long mergeSort(vector<long long> &arr, long long low, long long high) {
    long long cnt = 0;
    if (low >= high) return cnt;
    long long mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}


    long long reversePairs(vector<int>& nums) {
        vector<long long> temp(nums.begin(),nums.end());
        return mergeSort(temp,0,nums.size()-1);
    }
};