package array;
import java.util.*;
public class _4sum {
     public static List<List<Integer>> fourSum(int[] nums, int target) {
       Set<List<Integer>> uniqueset = new HashSet<>();
       List<List<Integer>> uniqueList = new ArrayList<>();

       
       Arrays.sort(nums);
       for(int i=0;i<nums.length;i++){
        for(int j=i+1;j<nums.length;j++){
            long ts=nums[i]+nums[j];
            int lp=j+1;
            int rp=nums.length-1;

            while (lp<rp) {
                if(ts+nums[lp]+nums[rp]<target){
                    lp++;
                }
                else if(ts+nums[lp]+nums[rp]>target){
                    rp--;
                }else{
                    uniqueset.add(Arrays.asList(nums[i],nums[j],nums[lp],nums[rp]));
                   
                    lp++;
                    rp--;
                }
            }
        }
       }

       for(List<Integer> list : uniqueset){
        uniqueList.add(list);
       }

       return uniqueList;


    }
    public static void main(String[] args) {
        System.out.println(fourSum(new int[]{1000000000,1000000000,1000000000,1000000000},-294967296));
    }
}
