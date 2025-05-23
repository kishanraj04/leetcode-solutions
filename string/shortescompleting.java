import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;

public class shortescompleting {

    public static HashMap<Character, Integer> getWordMap(String s) {
        HashMap<Character, Integer> wordMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (!wordMap.containsKey(s.charAt(i))) {
                wordMap.put(s.charAt(i), 1);
            } else {
                wordMap.put(s.charAt(i), wordMap.get(s.charAt(i)) + 1);
            }
        }

        return wordMap;
    }

    public static String check(String licensePlate, String[] words) {
        HashMap<Character, Integer> licenseMap = new HashMap<>();
        String ns = licensePlate.toLowerCase();

        for (int i = 0; i < licensePlate.length(); i++) {
            if (ns.charAt(i) >= 'a' && ns.charAt(i) <= 'z') {
                if (!licenseMap.containsKey(ns.charAt(i))) {
                    licenseMap.put(ns.charAt(i), 1);
                } else {
                    licenseMap.put(ns.charAt(i), licenseMap.get(ns.charAt(i)) + 1);
                }
            }

        }


        int tmplen = Integer.MAX_VALUE;
        String found = "";
        boolean flag=true;
        for (int i = 0; i < words.length; i++) {
            HashMap as = getWordMap(words[i]);
            for (Character ch : licenseMap.keySet()) {
                if (as.containsKey(ch) && (licenseMap.get(ch) <=(Integer) as.get(ch))) {
                    
                  continue;
                }else{
                    flag=false;
                }

            }
            if(flag){
                if(words[i].length()<tmplen){
                    tmplen=words[i].length();
                    found=words[i];
                   }
                System.out.println("run "+found);
            }
            flag=true;

        }

        return found;
    }

    public static void main(String[] args) {
        String[] arr = { "step","steps","stripe","sspt","stepple"};
        System.out.println(check("1s3 PSt", arr));
    }
}