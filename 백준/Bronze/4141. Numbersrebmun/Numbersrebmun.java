import java.io.*;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());

        for(int i = 0; i < N; i++){
            String name = bf.readLine().toUpperCase();
            char[] arr = name.toCharArray();
            int idx = 0;
            for(char s : arr){
                if (s < 'D') arr[idx] = 2;
                else if(s < 'G') arr[idx] = 3;
                else if(s < 'J') arr[idx] = 4;
                else if(s < 'M') arr[idx] = 5;
                else if(s < 'P') arr[idx] = 6;
                else if(s < 'T') arr[idx] = 7;
                else if(s < 'W') arr[idx] = 8;
                else arr[idx] = 9;
                idx++;
            }
            String Phone_num = String.valueOf(arr);
            StringBuffer sb = new StringBuffer(Phone_num);
            if(Phone_num.equals(sb.reverse().toString())) {
                System.out.println("YES");
            }else {
                System.out.println("NO");
            }
        }
    }
}
