public class candy_exchange {

    public static int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int res[] = new int[2];
        int alicecandy=0;
        int bobcandy=0;
        for(int i=0;i<aliceSizes.length;i++){
            alicecandy+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.length;i++){
            bobcandy+=bobSizes[i];
        }

        int aptr=0;
        int bptr=0;
        boolean flag=true;
        while ((aptr<aliceSizes.length || bptr<bobSizes.length)&&flag) {
          
                int bobdiff = alicecandy-aliceSizes[aptr]+bobSizes[bptr];
                int alidiff = bobcandy-bobSizes[bptr]+aliceSizes[aptr];

                if(bobdiff==alidiff){
                    res[0]=aliceSizes[aptr];
                    res[1]=bobSizes[bptr];
                }

                if(!(bptr+1>=bobSizes.length)){
                    bptr++;
                }
                if(!(aptr+1>=aliceSizes.length)){
                    aptr++;
                }
                if(bptr+1>=bobSizes.length && aptr+1>=aliceSizes.length){
                    flag=false;
                }
            
        }
        for(int i=0;i<res.length;i++){
            System.out.println(res[i]);
        }
        return res;
    }
    public static void main(String[] args) {
        System.out.println(fairCandySwap(new int[]{2},new int[]{1,3}));
    }
    
}
