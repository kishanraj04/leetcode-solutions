public class shortestdist {

    public static int[] shortestToChar(String s, char c) {
     int dist[] = new int[s.length()];
     
     int lp=0;
     int rp=0;

     for(int i=0;i<s.length();i++){
         if(s.charAt(i)==c){
                dist[i]=0;
                continue;
            }
        lp=i-1;
        rp=i+1;

        
        int mindist=Integer.MAX_VALUE;
        while (rp<=s.length()-1 || lp>=0) {
           
            if(rp<=s.length()-1){
                if(s.charAt(rp)==c ){
               if(rp-i<mindist){
                mindist=rp-i;
               }
               
            }
            }
            rp++;
            if(lp>=0){
                if(s.charAt(lp)==c){
                if(i-lp<mindist){
                    mindist=i-lp;
                }
                
            }
            lp--;
            }
        }

        dist[i]=mindist;

     }
   

     return dist;
    }
    public static void main(String[] args) {
        shortestToChar("aaab", 'b');
    }
}