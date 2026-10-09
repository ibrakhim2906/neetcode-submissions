class Solution {
    public int calPoints(String[] operations) {
        
        List<Integer> stack = new ArrayList<>();

        for (String operation : operations) {
            int size = stack.size();
            if ("+".equals(operation)) {
                stack.add(stack.get(size-1)+stack.get(size-2));
            } else if ("C".equals(operation)) {
                stack.remove(size-1);
            } else if ("D".equals(operation)) {
                stack.add(stack.get(size-1)*2);
            } else {
                stack.add(Integer.parseInt(operation));
            }
        }

        int sum = 0;
        
        for (int num : stack) {
            sum += num;
        }

        return sum;
    }
}