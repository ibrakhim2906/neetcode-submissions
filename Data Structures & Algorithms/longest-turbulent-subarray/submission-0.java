class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int L = 0;
        int R = 1;
        int result = 1;

        String prev = "";

        while (R<arr.length) {
            if (arr[R-1] > arr[R] && !prev.equals(">")) {
                result = Math.max(result, R-L+1);
                R++;
                prev = ">";
            } else if (arr[R-1] < arr[R] && !prev.equals("<")) {
                result = Math.max(result, R-L+1);
                R++;
                prev = "<";
            } else {
                R = (arr[R]==arr[R-1]) ? R+1 : R;
                L=R-1;
                prev="";
            }
        }

        return result;

    }
}