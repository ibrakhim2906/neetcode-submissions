class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for (int stone : stones) {
            maxHeap.add(stone);
        }

        while (maxHeap.size()>1) {
            int m1 = maxHeap.poll();
            int m2 = maxHeap.poll();

            if (m1>m2) {
                maxHeap.add(m1-m2);
            } else if (m2>m1) {
                maxHeap.add(m2-m1);
            } else {
                continue;
            }
                
        }

        return maxHeap.isEmpty() ? 0 : maxHeap.poll();
    }
}
