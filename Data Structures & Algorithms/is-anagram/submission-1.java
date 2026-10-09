class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length()!=t.length()) {
            return false;
        }
        
        HashMap<Character, Integer> hashMap = new HashMap<>();

        for (int i=0; i<s.length(); i++) {
            hashMap.put(s.charAt(i), hashMap.getOrDefault(s.charAt(i), 0)+1);
        }

        for (int i=0; i<t.length(); i++) {
            if (hashMap.get(t.charAt(i))==null || hashMap.get(t.charAt(i))==0) {
                return false;
            }
            hashMap.put(t.charAt(i), hashMap.get(t.charAt(i))-1);
        }

        return true;
    }
}
