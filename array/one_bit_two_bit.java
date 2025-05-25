package array;

public class one_bit_two_bit {
    public static boolean oneTwoBit(int[] arr){

        boolean flag = false;
        for(int i=0;i<arr.length;i++){
              if(i<arr.length-1){
                if(arr[i]==1 && (arr[i+1]==0 || arr[i+1]==1)){
                    flag=false;
                    i++;
                }
              }
              else{
                flag=true;
              }
        }

        return flag;
    }
    public static void main(String[] args) {
        System.out.println(oneTwoBit(new int[]{,1,0}));
    }
}
