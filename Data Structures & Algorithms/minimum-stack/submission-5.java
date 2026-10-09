class MinStack {

    private List<Integer> stack;
    private List<Integer> minStack;

    public MinStack() {
        stack = new ArrayList<>();
        minStack = new ArrayList<>();
        minStack.add(Integer.MAX_VALUE);
    }
    
    public void push(int val) {
        stack.add(val);
        if (minStack.get(minStack.size()-1)>=val) {
            minStack.add(val);
        }
    }
    
    public void pop() {
        if ((stack.get(stack.size()-1)).equals(minStack.get(minStack.size()-1))) {
            minStack.remove(minStack.size()-1);
        }
        stack.remove(stack.size()-1);
    }
    
    public int top() {
        return stack.get(stack.size()-1);
    }
    
    public int getMin() {
        return minStack.get(minStack.size()-1);
    }
}
