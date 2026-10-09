class DynamicArray {

    private int[] arr;
    private int size;
    private int capacity;

    public DynamicArray(int capacity) {

        arr = new int[capacity];
        size = 0;
        this.capacity = capacity;

    }

    public int get(int i) {

        return arr[i];

    }

    public void set(int i, int n) {

        arr[i]=n;

    }

    public void pushback(int n) {

        if (size>=capacity) {
        
            resize();
        }

        arr[size] = n;
        size++;

    }

    public int popback() {

        int last = size-1;
        size--;

        return arr[last];

    }

    private void resize() {

        int newCapacity = capacity*2;
        int[] newArr = new int[newCapacity];

        for (int i = 0; i<capacity; i++) {
                newArr[i] = arr[i];
                size++;
        }

        size = capacity;

        capacity = newCapacity;

        arr = newArr;

    }

    public int getSize() {

        return size;
    }

    public int getCapacity() {

        return capacity;
    }
}
