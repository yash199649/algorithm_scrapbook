package basic;

import java.util.Arrays;
import java.util.Scanner;

public class anagrams {
    public static void main(String[] args) {
        try {
            String alpha = "abcdefghijklmnopqrstuvwxyz", s1, s2;
            int _temp, i, l1, l2, count, min;
            int[] ch = new int[26];
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for (int k = 0; k < t; k++) {
                count = 0;
                s1 = sc.next();
                s2 = sc.next();
                Arrays.fill(ch, 0);
                l1 = s1.length();
                l2 = s2.length();
                min = l1 < l2 ? l1 : l2;
                for (i = 0; i < min; i++) {
                    _temp = alpha.indexOf(s1.charAt(i));
                    ch[_temp] +=1;
                    _temp = alpha.indexOf(s2.charAt(i));
                    ch[_temp] -=1;
                }
                if (l1 > l2) {
                    while (i < l1) {
                        _temp = alpha.indexOf(s1.charAt(i));
                        ch[_temp] +=1;
                        i++;
                    }
                } else {
                    while (i < l2) {
                        _temp = alpha.indexOf(s2.charAt(i));
                        ch[_temp] -=1;
                        i++;
                    }
                }
                for (i = 0; i < 26; i++) {
                    count+=Math.abs(ch[i]-0);
                }
                System.out.println(count);
            }

        }
        catch (Exception e){
            System.out.println(e.toString());
        }
    }
}
