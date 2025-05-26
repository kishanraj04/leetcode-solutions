public class rotate_string {

    public static boolean rotateString(String s, String goal) {

        int lp = s.indexOf(goal.charAt(0));

        if (lp < 0) {
            return false;
        } else {
            int gptr = 0;
            while (lp < s.length()) {
                if (s.charAt(lp) != goal.charAt(gptr)) {
                    return false;
                }
                lp++;
                gptr++;
                if(lp>=s.length())
                {

                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(rotateString("kishan", "hankis"));
    }

}
