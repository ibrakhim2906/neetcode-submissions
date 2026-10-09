class MinStack {
    private ArrayList<Integer> mainStack;
    private ArrayList<Integer> minSpy;

    public MinStack() {
        mainStack = new ArrayList<Integer>();
        minSpy = new ArrayList<Integer>();
    }
    
    public void push(int val) {
        if (minSpy.isEmpty() || minSpy.get(minSpy.size()-1)>=val) {
            minSpy.add(val);
        }
        
        mainStack.add(val);

    }
    
    public void pop() {
        if (minSpy.get(minSpy.size()-1).equals(mainStack.get(mainStack.size()-1))) {
            minSpy.remove(minSpy.size()-1);
        }
        mainStack.remove(mainStack.size()-1);
    }
    
    public int top() {
        return mainStack.getLast();
        
    }
    
    public int getMin() {
        return minSpy.getLast();
    }
}
