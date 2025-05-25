package array;

import java.util.HashMap;
import java.util.HashSet;

public class most_common_word {

    public static String mostCommonWord(String paragraph, String[] banned) {
        HashSet<String> bannedSet = new HashSet<>();
        for (String word : banned) {
            bannedSet.add(word.toLowerCase());
        }

        HashMap<String, Integer> hm = new HashMap<>();

        StringBuilder sb = new StringBuilder();
        for (char c : paragraph.toCharArray()) {
            if (Character.isLetter(c)) {
                sb.append(Character.toLowerCase(c));
            } else if (sb.length() > 0) {
                String word = sb.toString();
                if (!bannedSet.contains(word)) {
                    hm.put(word, hm.getOrDefault(word, 0) + 1);
                }
                sb.setLength(0);
            }
        }

        // Handle last word if paragraph ends with a letter
        if (sb.length() > 0) {
            String word = sb.toString();
            if (!bannedSet.contains(word)) {
                hm.put(word, hm.getOrDefault(word, 0) + 1);
            }
        }

        // Find the most common word
        String mostCommon = "";
        int maxCount = 0;
        for (String key : hm.keySet()) {
            if (hm.get(key) > maxCount) {
                maxCount = hm.get(key);
                mostCommon = key;
            }
        }
        return mostCommon;
    }

    public static void main(String[] args) {
        System.out.println(mostCommonWord("Bob hit a ball, the hit BALL flew far after it was ..hit...", new String[]{"hit"}));
    }
}
