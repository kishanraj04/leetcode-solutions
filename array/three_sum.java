package array;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class three_sum {
    public static List<List<Integer>> threeSum(int[]arr){

        Set<List<Integer>> res = new HashSet<>();
        Arrays.sort(arr);
        for(int i=0;i<arr.length-2;i++){
            int lp=i+1;
            int rp=arr.length-1;
            while (lp<rp) {
                int sum = arr[i]+arr[lp]+arr[rp];

                if(sum==0){
                    int arr1[] = new int[3];
                     res.add(Arrays.asList(arr[i],arr[lp],arr[rp]));
                     rp--;
                     lp++;
                }
                else if(sum<0){
                    lp++;
                }else{
                    rp--;
                }
            }
        }

        return new ArrayList<>(res);
    }

    public static void main(String[] args) {
          int a1[] = {-1,0,1};
          int a2[] = {-1,0,1};
          System.out.println(a1.equals(new int[]{-1,0,1,2,-1,-4}));
    }
}
