import java.util.Scanner;
import java.Math;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        long a = s.nextLong();
        int n,sum=0;
        int i=(int) (Math.log10(a) + 1)
        while(a && i>0){
            n = a%10;
            a=a/10;
            sum+=i*n;
            i--;
        }
        if(sum%11==0){
            System.out.print("Legal ISBN");
        }
        else{
            System.out.print("illegal ISBN");
        }
    }
}
