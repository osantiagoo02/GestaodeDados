import java.util.Arrays;

public class ArrayManipulator {
    private int[] array;
    private int size;

    public ArrayManipulator(int capacity) {
        array = new int[capacity];
        size = 0;
    }

    // Método para adicionar um elemento ao array
    public void add(int element) {
        if (size < array.length) {
            array[size] = element;
            size++;
        } else {
            System.out.println("O array está cheio. Não é possível adicionar mais elementos.");
        }
    }

    // Método para remover um elemento do array
    public void remove(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        } else {
            System.out.println("Índice inválido. Não é possível remover o elemento.");
        }
    }

    // Método para procurar um elemento no array
    public int search(int element) {
        for (int i = 0; i < size; i++) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1; // Retorna -1 se o elemento não for encontrado
    }

    // Método para exibir todos os elementos do array
    public void display() {
        System.out.print("Array: [");
        for (int i = 0; i < size; i++) {
            System.out.print(array[i]);
            if (i < size - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        ArrayManipulator manipulator = new ArrayManipulator(5);

        manipulator.add(10);
        manipulator.add(20);
        manipulator.add(30);
        manipulator.add(40);
        manipulator.add(50);
        manipulator.add(60); // Este elemento não será adicionado devido ao tamanho máximo do array

        manipulator.display();

        manipulator.remove(2);
        manipulator.display();

        int index = manipulator.search(20);
        if (index != -1) {
            System.out.println("O elemento 20 foi encontrado no índice " + index);
        } else {
            System.out.println("O elemento 20 não foi encontrado no array.");
        }
    }
}
