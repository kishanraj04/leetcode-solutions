package array;

public class no_of_lines_to_write_Str {
    public static int[] numberOfLines(int[] widths, String s) {
       int maxWidth = 100;
        int lines = 1;
        int currentWidth = 0;

        for (char c : s.toCharArray()) {
            int width = widths[c - 'a'];
            if (currentWidth + width > maxWidth) {
                lines++;
                currentWidth = width;
            } else {
                currentWidth += width;
            }
        }

        return new int[] {lines, currentWidth}; 
    }
    public static void main(String[] args) {
       int []res = numberOfLines(new int[]{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},"abcdefghijklmnopqrstuvwxyz")
    }
}
