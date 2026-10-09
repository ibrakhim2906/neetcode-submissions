class Solution {
    public boolean isValid(String s) {
        
        if (s.length()%2!=0) {
            return false;
        }

        List<Character> stack = new ArrayList<>();

        for (char ch : s.toCharArray()) {
            if (ch=='}' || ch==']' || ch==')') {

                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.get(stack.size()-1);

                if (ch=='}' && top!='{') {
                    return false;
                } else if (ch==']' && top!='[') {
                    return false;
                } else if (ch==')' && top!='(') {
                    return false;
                } else {
                    stack.remove(stack.size()-1);
                }
                
            } else {
                stack.add(ch);
            }
        }
        
        return stack.isEmpty();
    }
}
