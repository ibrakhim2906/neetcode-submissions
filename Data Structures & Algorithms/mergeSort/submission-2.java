// Definition for a pair.
// class Pair {
//     public int key;
//     public String value;
//
//     public Pair(int key, String value) {
//         this.key = key;
//         this.value = value;
//     }
// }
class Solution {
    public List<Pair> mergeSort(List<Pair> pairs) {
        return mergeSortHelper(pairs, 0, pairs.size()-1);
    }

    public List<Pair> mergeSortHelper(List<Pair> arr, int s, int e){
        if (e-s+1<=1) {
            return arr;
        }

        int m = s+(e-s)/2;

        mergeSortHelper(arr, s, m);
        mergeSortHelper(arr, m+1, e);
        merge(arr, s, m, e);

        return arr;
    }

    public void merge(List<Pair> arr, int s, int m, int e) {
        ArrayList<Pair> l1 = new ArrayList<>(arr.subList(s,m+1));
        ArrayList<Pair> l2 = new ArrayList<>(arr.subList(m+1, e+1));
        
        int i=0;
        int j=0;
        int k=s;

        while (i<l1.size() && j<l2.size()) {
            if (l1.get(i).key<=l2.get(j).key) {
                arr.set(k, l1.get(i));
                i++;
            } else {
                arr.set(k, l2.get(j));
                j++;
            }
            k++;
        }

        while (i<l1.size()) {
            arr.set(k, l1.get(i));
            k++;
            i++;
        }

        while (j<l2.size()) {
            arr.set(k, l2.get(j));
            k++;
            j++;
        }
    }
}
