class Stack {
    private ArrayList<Character> stack;
    
    public Stack(){
        stack = new ArrayList<>();
    }

    public Character top() {
        return stack.get(stack.size()-1);
    } 

    public int size() {
        return stack.size();
    }

    public void push(Character num) {
        stack.add(num);
    }
    
    public void pop() {
        if (stack.size()<=0) {
            return;
        }
        stack.remove(stack.size()-1);
    }
}

class Solution {
    public boolean isValid(String s) {
        Stack stack = new Stack();
        if (s.length()%2!=0) {
            return false;
        }
        for (Character chr : s.toCharArray()) {
            if (chr=='[' || chr=='(' || chr=='{') {
                stack.push(chr);
            } else {
                if (stack.size()==0) {
                    return false;
                }
                Character top = stack.top();

                if ((top=='(' && chr==')') 
                    || (top=='{' && chr=='}')
                    || (top=='[' && chr==']')) {
                        stack.pop();
                } else {
                    return false;
                }

            
            }
        }
        return stack.size() == 0;
    }
}
