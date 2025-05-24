import java.lang.reflect.Array;

public class goatlatin {

    public static String toGoatLatin(String sentence) {

        StringBuilder sb = new StringBuilder();

        String arr[] = sentence.split(" ");

        for (int i = 0; i < arr.length; i++) {
            String str = String.valueOf(arr[i].charAt(0));
            System.out.println(str);
            if (str.equals("a") || str.equals("e") || str.equals("o") || str.equals("u") || str.equals("i") || str.equals("A")
                    || str.equals("E") || str.equals("I")|| str.equals("O") || str.equals("U")) {

    
                    sb.append(arr[i] + "ma" + "a".repeat(i + 1));
                

            } else {
                     StringBuilder substr =new StringBuilder(arr[i].substring(1));
                     sb.append(substr.append(String.valueOf(arr[i].charAt(0)))+"ma"+"a".repeat(i+1));
            }
            if(i<arr.length-1){
                sb.append(" ");
            }
        }

        System.out.println(sb);
        return sb.toString();
    }

    public static void main(String[] args) {
        toGoatLatin("inNWTMce CT");
    }

}
