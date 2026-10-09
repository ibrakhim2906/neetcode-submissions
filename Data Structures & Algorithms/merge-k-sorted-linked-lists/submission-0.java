/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer> arr = new ArrayList<>();

        int i=0;

        for (ListNode node : lists) {
            while (node!=null) {
                arr.add(node.val);
                node=node.next;
            }
        }

        if (arr.isEmpty()) {
            return null;
        }

        arr = mergeSort(arr, 0, arr.size()-1);

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (int x : arr) {
            tail.next = new ListNode(x);
            tail=tail.next;
        }
        return dummy.next;
    }
}

public List<Integer> mergeSort(List<Integer> arr, int s, int e) {
    if (e-s+1<=1) {
        return arr;
    }

    int m = (e+s)/2;

    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, m, e);

    return arr;
}

public void merge(List<Integer> arr, int s, int m, int e) {
    List<Integer> L = new ArrayList<Integer>(arr.subList(s, m + 1));
    List<Integer> R = new ArrayList<Integer>(arr.subList(m + 1, e + 1));
    
    int i = 0;
    int j = 0;
    int k = s;

    while (i<L.size() && j<R.size()) {
        if (L.get(i)<R.get(j)) {
            arr.set(k, L.get(i));
            i++;
        } else {
            arr.set(k, R.get(j));
            j++;
        } 
        k++;
    }

    while (i<L.size()) {
        arr.set(k, L.get(i));
        k++;
        i++;
    }

    while (j<R.size()) {
        arr.set(k, R.get(j));
        k++;
        j++;
    }
}

