package basic;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class anagrams_updated {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine());

        //Get Strings
        String [][] inputStrings = new String[testcases][2];
        for(int i=0;i<testcases;i++){
            inputStrings[i][0] = br.readLine();
            inputStrings[i][1] = br.readLine();
        }

        int result = 0;
        for(int i=0;i<testcases;i++){
            result = 0;
            int[] s1 = new int[26];
            int[] s2 = new int[26];
            for(int k=0;k<inputStrings[i][0].length();k++){
                s1[inputStrings[i][0].charAt(k) - 'a']++;
            }
            for(int k=0;k<inputStrings[i][1].length();k++){
                s1[inputStrings[i][1].charAt(k) - 'a']++;
            }
            for(int index = 0; index<26; index++){
                result += Math.abs(s1[index]-s2[index]);
            }
            System.out.println(result);
        }
    }
}
