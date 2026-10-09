class Solution {
    public int[] replaceElements(int[] arr) {
        for (int i = 0; i<arr.length; i++) {
            int maxElem = 0;
            for (int j = i+1; j<arr.length; j++) {
                if (arr[j]>maxElem) {
                    maxElem = arr[j];
                }
            }
            arr[i]=maxElem;
        }
        arr[arr.length-1]=-1;

        return arr;
    }
}