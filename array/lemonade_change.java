import java.util.ArrayList;

class lemonade_change {

    public static boolean lemonadeChange(int[] bills) {

         int fiveCount = 0;  
        int tenCount = 0;   

        for (int bill : bills) {
            if (bill == 5) {
                fiveCount++; 
            } else if (bill == 10) {
                if (fiveCount == 0) {
                    return false;
                }
                fiveCount--;   
                tenCount++;    
            } else { 
               
                if (tenCount > 0 && fiveCount > 0) {
                    tenCount--;
                    fiveCount--;
                } else if (fiveCount >= 3) {
                    fiveCount -= 3;
                } else {
                    return false; 
                }
            }
        }
        return true; 

    }

    public static void main(String[] args) {
        System.out.println(lemonadeChange(new int[] {5,5,10,10,20}));
    }
}