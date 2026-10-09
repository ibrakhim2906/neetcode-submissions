class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i<n; i++) {
           nums1[i+m]=nums2[i];
        }

        mergeSort(nums1, 0, nums1.length-1);
    }

    public void mergeSort(int[] arr, int l, int r) {
        
        if (l<r) {
            
            int m = (l+r)/2;

            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            mergeHelper(arr, l, m, r);
        }

    }

    public void mergeHelper(int[] arr, int l, int m, int r) {

        int length1 = m-l+1;
        int length2 = r-m;

        int[] R = new int[length1];
        int[] L = new int[length2];


        for (int i = 0; i<length1; i++) {
            R[i] = arr[l+i];
        }

        for (int j = 0; j<length2; j++) {
            L[j] = arr[m+1+j];
        } 

        int i = 0;
        int j = 0;
        int k = l;

        while (i<length1 && j<length2) {
            
            if (L[j]>=R[i]) {
                arr[k] = R[i];
                i++;
            } else {
                arr[k] = L[j];
                j++;
            }

            k++;
        }

        while (i<length1) {
            arr[k] = R[i];
            i++;
            k++;
        }
        
        while (j<length2) {
            arr[k] = L[j];
            j++;
            k++;
        }
    }
}