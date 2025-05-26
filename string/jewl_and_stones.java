public class jewl_and_stones {

     public static int numJewelsInStones(String jewels, String stones) {
     
        int count=0;
        int tmpCount=0;
        int tmpCount2=0;
        
           for(int i=0;i<jewels.length();i++){
                if(stones.indexOf(String.valueOf(jewels.charAt(i)))>=0){
                    count++;
                }
            }
        
         
             for(int i=0;i<stones.length();i++){
                if(jewels.indexOf(String.valueOf(stones.charAt(i)))>=0){
                    tmpCount2++;
                }
            }
        
      
             for(int i=0;i<stones.length();i++){
                if(jewels.indexOf(String.valueOf(stones.charAt(i)))>=0){
                    tmpCount++;
                }
            }
        
       
        return count>=tmpCount && count>=tmpCount2 ? count:tmpCount>=tmpCount2?tmpCount:tmpCount2;
    }
    public static void main(String[] args) {
        System.out.println(numJewelsInStones("dbca","beb"));
    }
    
}
