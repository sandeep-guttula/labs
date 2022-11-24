
import java.util.*;
class CharStuffing {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the string");
    String s = sc.nextLine();
    String ans = new String();
    for(int i = 0; i < s.length();i++){
      ans += s.charAt(i);
      if (s.charAt(i) == ' ')
        ans += "DLE ";
    }
    System.out.println("After character stufing "+"DLE STX " + ans + " DLE ETX");
    sc.close();
  }
}