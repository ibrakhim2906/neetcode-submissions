class Solution {
   public:
    int findMin(vector<int>& arr) {
        // [3,4,5,6,1,2]
        // l = 0, r = 5
        // m = 2
        // arr[l] = 3
        // arr[r] = 2
        // arr[m] = 5
        // arr[m]>r
        // m = l+1
        // l = 3, r = 5
        // m = 4
        // arr[l] = 6
        // arr[r] = 2
        // arr[m] = 1
        // arr[m] < r
        // return arr[m]

        int l = 0, r = arr.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (arr[m] > arr[r]) {
                l = m + 1;
            } else if (arr[m] < arr[r]) {
                r = m;
            }
        }

        return arr[l];
    }
};
