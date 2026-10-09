class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack();
        
        for (String token : tokens) {
            if (token.equals("-")) {
                int pop1 = stack.pop();
                int pop2 = stack.pop();

                int res = pop2 - pop1;
                stack.push(res);
            }
            else if (token.equals("+")) {
                int pop1 = stack.pop();
                int pop2 = stack.pop();

                int res = pop1 + pop2;
                stack.push(res);
            }
            else if (token.equals("*")) {
                int pop1 = stack.pop();
                int pop2 = stack.pop();
                
                int res = pop1 * pop2;
                stack.push(res);
            }
            else if (token.equals("/")) {
                int pop1 = stack.pop();
                int pop2 = stack.pop();

                int res = pop2 / pop1;
                stack.push(res);
            } else {
                stack.push(Integer.parseInt(token));
            }
        }

        return stack.pop();
    }
}
