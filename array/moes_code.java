package array;

import java.util.*;

public class moes_code {
     public static int uniqueMorseRepresentations(String[] words) {
        
        String str[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        Set<String> set = new HashSet<>();
        
        for(String s:words){
            StringBuilder sb = new StringBuilder();
            for(char ch:s.toCharArray()){
                sb.append(str[ch-'a']);
            }
            set.add(sb.toString());
        }

        return set.size();
    }
    public static void main(String[] args) {
        System.out.println(uniqueMorseRepresentations(new String[]{"gin","zen","gig","msg"}));
    }
}
