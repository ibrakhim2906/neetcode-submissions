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
        List<Pair> result = mergeSort1(pairs, 0, pairs.size()-1);

        return result;                
    }

    public List<Pair> mergeSort1(List<Pair> pairs, int l, int r) {

        if (l<r) {
            
            int m = (l+r)/2;
            
            mergeSort1(pairs, l, m);
            mergeSort1(pairs, m+1, r);
            mergeHelper(pairs, l, m, r);

        }

        return pairs;
    }

    public void mergeHelper(List<Pair> pairs, int l, int m, int r) {

        int length1 = m-l+1;
        int length2 = r-m;   

        List<Pair> temp1 = new ArrayList<>();
        List<Pair> temp2 = new ArrayList<>();

        for (int i = 0; i < length1; i++) {
            temp1.add( pairs.get(i+l));
        }

        for (int j = 0; j < length2; j++) {
            temp2.add( pairs.get(m+1+j));
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i<length1 && j<length2) {
            
            if (temp1.get(i).key<=temp2.get(j).key) {
                pairs.set(k, temp1.get(i));
                i++;  
            } else {

                pairs.set(k, temp2.get(j));
                j++;

            } 

            k++;
        }

        while (i<length1) {
            pairs.set(k, temp1.get(i));
            i++;
            k++;
        }   

        while (j<length2) {
            pairs.set(k, temp2.get(j));
            j++;
            k++;
        }
         

    }
}
