class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxPile=0;
        for (int p: piles) {
            maxPile = Math.max(maxPile, p);
        }

        int low = 1;
        int high = maxPile;

        while (low<=high) {
            int m = low+(high-low)/2;

            int hours = 0;
            for (int p : piles) {
                hours+=(p+m-1)/m;
            }

            if (hours<=h) {
                high=m-1;
            } else if (hours>=h) {
                low=m+1;
            }
        }
        return low;
    }
}