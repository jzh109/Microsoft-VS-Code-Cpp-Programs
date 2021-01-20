import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String str = scanner.nextLine();
            String[] ss = str.split("5");
            ArrayList<Integer> arr = new ArrayList<>();
            for (String temp : ss) {
                if (temp.equals("")) {
                    continue;
                }
                arr.add(Integer.parseInt(temp));
            }
            arr.sort(Comparator.naturalOrder());
            Iterator<Integer> it = arr.iterator();
            while (it.hasNext()) {
                Integer temp = it.next();
                System.out.print(temp);
                if (it.hasNext()) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        scanner.close();
    }
}