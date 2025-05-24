package array;

import java.lang.reflect.Array;
import java.util.Arrays;

public class max_are_of_traingle {

    // public double calArea(int[]?)

    public static double largestTriangleArea(int[][] points) {

        // Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        double maxAre = Integer.MIN_VALUE;
        int are = Integer.MAX_VALUE;
        for (int i = 0; i < points.length-1; i++) {
            int lp = i + 1;
            int rp = points.length - 1;

            while (lp < rp) {

                int x1 = points[i][0];
                int x2 = points[lp][0];
                int x3 = points[rp][0];
                int y1 = points[i][1];
                int y2 = points[lp][1];
                int y3 = points[rp][1];

                double area = 0.5 * Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) +x3 * (y1 - y2));

                if(area>maxAre){
                    maxAre=area;
                }
                 
                if(area<are){
                    lp++;
                }
                else{
                    rp--;
                }

            }
        }

        return maxAre;
    }

    public static void main(String[] args) {
           System.out.println(largestTriangleArea(new int[][]{{8,10},{2,7},{9,2},{4,10}}));
    }

}
