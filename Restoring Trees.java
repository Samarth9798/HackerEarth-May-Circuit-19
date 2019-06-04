import java.util.*;
import java.io.*;

class TestClass {
    
    static int start[],finish[],ans[],timer,n;
    
    static void dfs(int parent)
    {
        int node = start[timer];
        ans[node] = parent;
        
        timer++;
        
        while(finish[node] > timer)
            dfs(node);
    }
    public static void main(String args[]) throws Exception {
        
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        n = in.nextInt();
        
        start = new int[n+1];
        finish = new int[n+1];
        ans = new int[n+1];
        
        for(int i = 1; i <= n; i++)
        {
            int temp = in.nextInt();
            start[temp] = i;
        }
        
        for(int i = 1; i <= n; i++)
            finish[i] = in.nextInt();
        
        timer = 0;
        dfs(0);
        
        for(int i = 1; i <= n; i++)
            out.print(ans[i] + " ");
            
        out.close();
    }
}
