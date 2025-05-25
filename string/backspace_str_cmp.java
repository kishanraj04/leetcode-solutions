public class backspace_str_cmp {

    public static boolean backspaceCompare(String s, String t) {

        int sp1 = s.length() - 1;
        int sp2 = t.length() - 1;
        boolean flag = true;

        while (sp1 >= 0 || sp2 >= 0) {
            // "bxj##tw", "bxo#j##tw"
            if ((sp1 >= 0 && sp2 >= 0) && s.charAt(sp1) != t.charAt(sp2) && (s.charAt(sp1)!='#' && s.charAt(sp2)!='#')) {
                return false;
            } else {
                if ((sp1 >= 0 && sp2 >= 0) && s.charAt(sp1) == t.charAt(sp2) && (s.charAt(sp1) != '#' || s.charAt(sp2)!='#')) {
                    sp1--;
                    sp2--;
                }
                if ((sp1 <= s.length() && sp1 >= 0) && s.charAt(sp1) == '#') {
                    if ((sp1 <= s.length() && sp1 >= 0) && s.charAt(sp1 - 1) == '#') {
                        sp1 --;
                    }
                    sp1 -= 2;
                }
                if ((sp2 <= t.length() && sp2 >= 0) && t.charAt(sp2) == '#') {
                    if ((sp2 <= s.length() && sp2 >= 0) && s.charAt(sp2 - 1) == '#') {
                        sp2 --;
                    }
                    sp2 -= 2;
                }
            }

        }

        return flag;
    }

    public static void main(String[] args) {
        System.out.println(backspaceCompare("bxj##tw", "bxo#j##tw"));
    }

}
