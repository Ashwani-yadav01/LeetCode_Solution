class Solution {
    public String reverseParentheses(String s) {
        StringBuilder res = new StringBuilder();
        Stack<String> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c != ')') {
                st.push(String.valueOf(c));
            } else {
                StringBuilder str = new StringBuilder();
                while (!st.peek().equals("(")) {
                    str.append(st.pop());
                }
                st.pop();
                for (int j = 0; j < str.length(); j++) {
                    st.push(String.valueOf(str.charAt(j)));
                }
            }
        }
        while (!st.isEmpty()) {
            res.append(st.pop());
        }

        return res.reverse().toString();
    }
}