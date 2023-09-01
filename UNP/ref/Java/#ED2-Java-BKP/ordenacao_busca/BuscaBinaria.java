package ordenacao_busca;

public class BuscaBinaria {

  public static int buscaBinaria(int[] array, int chave) {
    int left = 0;
    int right = array.length - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (array[mid] == chave) {
        return mid; // Elemento encontrado, retorna o índice
      } else if (array[mid] < chave) {
        left = mid + 1; // O elemento está na metade direita do array
      } else {
        right = mid - 1; // O elemento está na metade esquerda do array
      }
    }

    return -1; // Elemento não encontrado
  }

  public static void main(String[] args) {
    int[] sortedArray = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int target = 23;

    int result = buscaBinaria(sortedArray, target);

    if (result != -1) {
      System.out.println("Elemento encontrado no índice: " + result);
    } else {
      System.out.println("Elemento não encontrado.");
    }
  }
}
