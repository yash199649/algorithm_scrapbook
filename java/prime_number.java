package basic;

import java.util.Arrays;
import java.util.Scanner;


public class prime_number {
    public static void getPrime(int n) {
        Boolean[] sieve = new Boolean[n + 1];
        Arrays.fill(sieve, Boolean.TRUE);
        sieve[0] = false;
        sieve[1] = false;
        for (int i = 2; i*i <= n; i++) {
            if (sieve[i] == true) {
                for (int j = 2*i; j < n + 1; j+=i) {
                    sieve[j] = false;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (sieve[i] == true) {
                System.out.println(i);
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        getPrime(input);
    }





}
