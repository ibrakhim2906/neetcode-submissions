class MinHeap {

    private List<Integer> minHeap;

    public MinHeap() {
        minHeap = new ArrayList<>();
        minHeap.add(0);
    }

    public void push(int val) {
        minHeap.add(val);
        int i = minHeap.size()-1;
        
        while (i>1 && minHeap.get(i)<minHeap.get(i/2)) {
            int tmp = minHeap.get(i);
            minHeap.set(i, minHeap.get(i/2));
            minHeap.set(i/2, tmp);
            i=i/2;
        }
    }

    public Integer pop() {
        if (minHeap.size()-1==0) {
            return -1;
        }
        
        if (minHeap.size()-1==1) {
            return minHeap.remove(1);
        }

        int res = minHeap.get(1);
        minHeap.set(1, minHeap.remove(minHeap.size()-1));

        int i = 1;
        while (i*2<minHeap.size()) {
            if (i*2+1<minHeap.size() && 
                minHeap.get(i*2+1)<minHeap.get(i*2) &&
                minHeap.get(i)>minHeap.get(i*2+1)) {
                    int tmp = minHeap.get(i);
                    minHeap.set(i, minHeap.get(2*i+1));
                    minHeap.set(i*2+1, tmp);
                    i=i*2+1;
                }
            else if (minHeap.get(i)>minHeap.get(i*2)) {
                    int tmp = minHeap.get(i);
                    minHeap.set(i, minHeap.get(2*i));
                    minHeap.set(i*2, tmp);
                    i=i*2;
            } else {
                break;
            }
        }

        return res;
    }

    public Integer top() {
        if (minHeap.size()-1==0) {
            return -1;
        }

        return minHeap.get(1);
    }

    public void heapify(List<Integer> nums) {
        minHeap = new ArrayList<>();
        
        minHeap.add(0);
    
        minHeap.addAll(nums);
        int cur = (minHeap.size()-1) / 2;
        while (cur>0) {
            int i = cur;
            while (i*2<minHeap.size()) {
                if (i*2+1<minHeap.size() &&
                    minHeap.get(i*2)>minHeap.get(i*2+1) &&
                    minHeap.get(i)>minHeap.get(i*2+1)) {
                        int tmp = minHeap.get(i);
                        minHeap.set(i, minHeap.get(i*2+1));
                        minHeap.set(i*2+1, tmp);
                        i=i*2+1;
                    }
                else if (minHeap.get(i)>minHeap.get(i*2)) {
                        int tmp = minHeap.get(i);
                        minHeap.set(i, minHeap.get(i*2));
                        minHeap.set(i*2, tmp);
                        i=i*2;
                } else {
                    break;
                }
            }
            cur--;
        }
        return;
    }
}
