class Solution {
    HashMap<Integer, Integer> memo = new HashMap<>();
    public int climbStairs(int n) {

        return climb(n, memo);
        
    }

    public int climb(int n, HashMap<Integer, Integer> memo) {
        if (n<=2) {
            return n;
        }

        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        int result = climb(n-1, memo) + climb(n-2, memo);
        memo.put(n, result);

        return result;

    }
}
