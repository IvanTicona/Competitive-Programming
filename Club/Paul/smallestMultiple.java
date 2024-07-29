import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
    // Function to calculate the greatest common divisor
    private static BigInteger gcd(BigInteger a, BigInteger b) {
        return a.gcd(b);
    }

    // Function to calculate the least common multiple
    private static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(gcd(a, b));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] numbersStr = line.split(" ");
            List<BigInteger> numbers = new ArrayList<>();

            for (String numStr : numbersStr) {
                numbers.add(new BigInteger(numStr));
            }

            // Calculate LCM of the entire set of numbers
            BigInteger result = numbers.get(0);
            for (int i = 1; i < numbers.size(); i++) {
                result = lcm(result, numbers.get(i));
            }

            System.out.println(result);
        }

        scanner.close();
    }
}