import java.util.Scanner;

class A {
    static Scanner sc = new Scanner(System.in);

    private static void solve() {
        String s = "codeforces";
        Character a = sc.next().charAt(0);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == a) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t > 0) {
            solve();
            t--;
        }
    }
}