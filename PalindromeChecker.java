

public class PalindromeChecker {

    public static boolean isPalindrome(String s) {
        // Удаляем все непробельные символы и приводим к нижнему регистру
        String cleaned = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        
        // Проверяем, является ли строка палиндромом
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
        // Тесты
        runTests();
    }

    public static void runTests() {
        // Тестовые случаи
        String[] testCases = {
            "A man, a plan, a canal, Panama",
            "racecar",
            "No lemon, no melon",
            "Was it a car or a cat I saw?",
            "Not a palindrome",
            "12321",
            "123456",
            "Able was I, I saw Elba",
            "Madam, in Eden, I'm Adam",
            "A Santa at NASA",
            "No 'x' in Nixon",
            "Eva, can I see bees in a cave?",
            "Not a palindrome at all"
        };

        // Ожидаемые результаты
        boolean[] expectedResults = {
            true,
            true,
            true,
            true,
            false,
            true,
            false,
            true,
            true,
            true,
            true,
            true,
            false
        };

        // Запуск тестов
        for (int i = 0; i < testCases.length; i++) {
            String testCase = testCases[i];
            boolean expectedResult = expectedResults[i];
            boolean result = isPalindrome(testCase);
            System.out.println("Test case: \"" + testCase + "\"");
            System.out.println("Expected: " + expectedResult + ", Got: " + result);
            System.out.println(result == expectedResult ? "PASS" : "FAIL");
            System.out.println();
        }
    }
}
