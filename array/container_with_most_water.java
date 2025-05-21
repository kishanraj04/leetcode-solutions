package array;

public class container_with_most_water {

    public static int max_water (int[] arr){
        int lp=0;
        int rp=arr.length-1;
        int maxWater=0;
        int tmp=0;
        while (lp<rp) {
            maxWater=(rp-lp)*(arr[rp]<arr[lp]?arr[rp]:arr[rp]==arr[lp]?arr[rp]:arr[lp]);
            if(tmp<maxWater) tmp=maxWater;

            if(arr[rp]<arr[lp]){
                rp--;
            }else if(arr[lp]<arr[rp])
            {
                lp++;
            }else{
                rp--;
            }
        }
        return tmp;
    }
    public static void main(String[] args) {
        int[] arr = {1,1};
        System.out.println(max_water(arr));
    }
}
