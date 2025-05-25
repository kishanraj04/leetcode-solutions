package array;

public class flip_image {

    public static int[][] flipAndInvertImage(int[][] image) {
        for (int i = 0; i < image.length; i++) {
            int lp = 0;
            int rp = image[i].length - 1;
            while (lp <= rp) {
                int tmp = image[i][rp] == 0 ? 1 : 0;
                image[i][rp] = image[i][lp] == 0 ? 1 : 0;
                image[i][lp] = tmp;
                lp++;
                rp--;
            }
        }

        return image;
    }

    public static void main(String[] args) {
        System.out.println(
                flipAndInvertImage(new int[][] { { 1, 1, 0, 0 }, { 1, 0, 0, 1 }, { 0, 1, 1, 1 }, { 1, 0, 1, 0 } }));
    }

}
