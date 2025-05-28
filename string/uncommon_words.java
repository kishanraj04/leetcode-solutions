import java.util.HashMap;

public class uncommon_words {
    public static String[] uncommonFromSentences(String s1, String s2) {
        HashMap<String,Integer> hm1 = new HashMap<>();
        HashMap<String,Integer> hm2 = new HashMap<>();
        String[] strarr1 = s1.split(" ");
        String[] strarr2 = s2.split(" ");

        int ptr1=0;
        int ptr2=0;
        //  s1 = "this apple is sweet", s2 = "this apple is sour"
        while (ptr1<strarr1.length || ptr2<strarr2.length) {
            if(ptr1<strarr1.length && !hm1.containsKey(strarr1[ptr1])){
                hm1.put(strarr1[ptr1],1);
            }
            else{
                hm1.put(strarr1[ptr1],hm1.get(strarr1[ptr1])+1);
            }
            if(ptr2<strarr2.length && !hm1.containsKey(strarr2[ptr2])){
                hm2.put(strarr2[ptr2],1);
            }
            else{
                hm1.put(strarr2[ptr2],hm2.get(strarr2[ptr2])+1);
            }
        }
        System.out.println(hm1 );

        return new String[]{"kishu"};
    }
    public static void main(String[] args) {
        System.out.println(uncommonFromSentences("this apple is sweet", "this apple is sour"));
    }
}
