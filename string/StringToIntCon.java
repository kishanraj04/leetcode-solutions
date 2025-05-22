public class StringToIntCon {
    public static int convert(String s) {

         s = s.trim(); 
    if (s.length() == 0) return 0;

    int i = 0, sign = 1;
    long num = 0;

    if (s.charAt(i) == '+' || s.charAt(i) == '-') {
        sign = (s.charAt(i) == '-') ? -1 : 1;
        i++;
    }

    while (i < s.length() && Character.isDigit(s.charAt(i))) {
        num = num * 10 + (s.charAt(i) - '0');

        
        if (sign == 1 && num > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (sign == -1 && -num < Integer.MIN_VALUE) return Integer.MIN_VALUE;

        i++;
    }

    return (int) num * sign;
    }

    public static void main(String[] args) {
        System.out.println(convert("-987"));
    }
}
