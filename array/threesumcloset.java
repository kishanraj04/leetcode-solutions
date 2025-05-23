package array;

import java.util.Arrays;

public class threesumcloset {

    public static int threeSumClosest(int[] nums, int target) {
         Arrays.sort(nums);
        int resultsum=nums[0]+nums[1]+nums[2];
        int tdiff = Integer.MAX_VALUE;
       
        for(int i=0;i<nums.length-2;i++){
            int lp=i+1;
            int rp=nums.length-1;
            while(lp<rp){
                int sum=nums[i]+nums[lp]+nums[rp];
                
                 if(sum==target){
                    return target;
                }
                if(sum<target){
                    lp++;
                }
               
                else{
                    rp--;
                }

                int diff = Math.abs(sum-target);
                if(diff<tdiff){
                    resultsum=sum;
                    tdiff=diff;
                }
            }
        }
        return resultsum;
    }
    public static void main(String[] args) {
        System.out.println(threeSumClosest(new int[]{2, 5, 6, 7},16));
    }
}