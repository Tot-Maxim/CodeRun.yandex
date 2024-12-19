import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Считываем размеры поля и количество мин
        String[] firstLine = reader.readLine().split(" ");
        int N = Integer.parseInt(firstLine[0]);
        int M = Integer.parseInt(firstLine[1]);
        int K = Integer.parseInt(firstLine[2]);

        // Создаем двумерный массив для поля и инициализируем его нулями
        int[][] field = new int[N][M];

        // Читаем координаты мин и устанавливаем их на поле
        for (int k = 0; k < K; k++) {
            String[] mineCoordinates = reader.readLine().split(" ");
            int p = Integer.parseInt(mineCoordinates[0]) - 1;
            int q = Integer.parseInt(mineCoordinates[1]) - 1;
            field[p][q] = -1; // Устанавливаем мину как -1
        }

        // Обновляем числа вокруг мин
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] == -1) {
                    // Проверяем все восемь соседних клеток
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int x = i + dx;
                            int y = j + dy;
                            if (x >= 0 && x < N && y >= 0 && y < M && field[x][y] != -1) {
                                field[x][y]++;
                            }
                        }
                    }
                }
            }
        }

        // Выводим поле
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] == -1) {
                    writer.write("*");
                } else {
                    writer.write(String.valueOf(field[i][j]));
                }
                if (j < M - 1) {
                    writer.write(" ");
                }
            }
            writer.newLine();
        }

        reader.close();
        writer.close();
    }
}