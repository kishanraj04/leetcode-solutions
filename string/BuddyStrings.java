public class BuddyStrings {
    public static boolean buddyStrings(String s, String goal) {
       
        if (s.length() != goal.length()) return false;

       
        if (s.equals(goal)) {
            int[] count = new int[26];
            for (char c : s.toCharArray()) {
                count[c - 'a']++;
                if (count[c - 'a'] > 1) {
                    return true; 
                }
            }
            return false;
        }

       
        int first = -1, second = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != goal.charAt(i)) {
                if (first == -1) {
                    first = i;
                } else if (second == -1) {
                    second = i;
                } else {
                    return false; 
                }
            }
        }

        return second != -1 &&
               s.charAt(first) == goal.charAt(second) &&
               s.charAt(second) == goal.charAt(first);
    }

   
    public static void main(String[] args) {
        System.out.println(buddyStrings("ab", "ba"));   
        System.out.println(buddyStrings("ab", "ab"));  
        System.out.println(buddyStrings("aa", "aa"));  
        System.out.println(buddyStrings("abcaa", "cabaa")); 
    }
}
