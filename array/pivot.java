package array;

public class pivot {
    public static int indexOfPivot(int []arr){

        int totalsum=0;
        for(int i=0;i<arr.length;i++){
            totalsum+=arr[i];
        }

        int leftSum=0;
        for(int i=0;i<arr.length;i++){
            leftSum+=arr[i];
            if(leftSum==totalsum){
                return i;
            }
            totalsum-=arr[i];
            

            if(i+1<arr.length && leftSum==(totalsum-arr[i+1])){
                return i+1;
            }
        }

        return -1;
    }
    public static void main(String[] args) {
        System.out.println(indexOfPivot(new int[]{-1,-1,3,-2}));
    }
}
