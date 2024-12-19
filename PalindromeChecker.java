import java.util.Scanner;

public class PalindromeChecker {

    public static boolean isPalindrome(String s) {
        // Удаляем все непробельные символы и приводим к нижнему регистру
        String cleaned = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        
        int left = 0;
        int right = cleaned.length() - 1;
        
        while (left < right) {
            if (cleaned.charAt(left) != cleaned.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Введите строку для проверки на палиндром (или 'exit' для выхода): ");
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("exit")) {
                System.out.println("Выход из программы. Пока!");
                break;
            }

            boolean result = isPalindrome(input);
            System.out.println("Строка: \"" + input + "\"");
            System.out.println("Палиндром: " + result);
        }
        scanner.close(); // Закрываем Scanner после выхода из цикла
    }
}
