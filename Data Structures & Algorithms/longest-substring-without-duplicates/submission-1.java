class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> window = new HashSet<>();
        char[] arr = s.toCharArray();

        int L=0;
        int max=0;

        for (int R=0; R<arr.length; R++) {
            while (window.contains(arr[R])) {
                window.remove(arr[L]);
                L++;
            }
            
            window.add(arr[R]);
            max = Math.max(R-L+1, max);
        }

        return max;
    }
}
