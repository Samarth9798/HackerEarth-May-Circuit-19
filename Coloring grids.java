import java.util.*;

class TestClass {
    public static void main(String args[] ) throws Exception {
        
        Scanner in = new Scanner(System.in);
        
        Long ans,n,k;
        
        n = in.nextLong();
        k = in.nextLong();
        
        if(n == 2)
        {
            ans = k*(k-1)+k;
        }
        else
        {
            ans = k;
        }
        
        System.out.println(ans);
    }
}
