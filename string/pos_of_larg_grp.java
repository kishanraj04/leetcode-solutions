import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class pos_of_larg_grp {

    public static List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> range = new ArrayList<>();
        int count = 1;
        int initial = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                if (count == 1) {
                    initial = i;
                }
                count++;
            } else {
                if (count >= 3) {
                    int end = i;
                    range.add(Arrays.asList(initial, end));
                }
                count = 1;
            }
        }

       
        if (count >= 3) {
            int end = s.length() - 1;
            range.add(Arrays.asList(initial, end));
        }

        return range;
    }

    public static void main(String[] args) {
        List<List<Integer>> result = largeGroupPositions("abcdddeeeeaabbbcd");
        System.out.println(result);  
    }
}
