import java.util.*;
import java.io.*;

class point
{
    int x,y;
    point(int x,int y)
    {
        this.x = x;
        this.y = y;
    }
}
class TestClass {
    public static void main(String args[] ) throws Exception 
    {
       Scanner in = new Scanner(System.in);
       PrintWriter out = new PrintWriter(System.out);
       
       int n,m;
       
       n = in.nextInt();
       m = in.nextInt();
       
       point g[] = new point[n+5];
       point s[] = new point[m+5];
       
       for(int i = 1; i <= n; i++)
       {
           int x,y;
           
           x = in.nextInt();
           y = in.nextInt();
           
           g[i] = new point(x,y);
        }
        
        for(int i = 1; i <= n; i++)
        {
            int x,y;
           
            x = in.nextInt();
            y = in.nextInt();
            
            s[i] = new point(x,y);
        }
        
        int guard[] = new int[n+5];
        
        int cnt,id;
        
        for(int j = 1; j <= m; j++)
        {
            int xj,yj;
            yj = s[j].y;
            xj = s[j].x;
            cnt = 0;
            id = 0;
            for(int i = n; i >= 1; i--)
            {
                int xi,yi;
                xi = g[i].x;
                yi = g[i].y;
                
                if(Math.abs(yi - yj) <= xj - xi) 
                {
                    cnt++;
                    id = i;
                }
                if(cnt > 1)
                    break;
            }
            if(cnt == 1) guard[id] = 1;
        }
        
        cnt = 0;
        for(int i = 1; i <= n; i++)
            if(guard[i] > 0)
                cnt++;
                
        int ans = n-cnt;
        
        out.println(ans);
        out.close();
    }
}
