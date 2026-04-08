#include <iostream>
using namespace std;


void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
   int a =4 
  int b =6
  cout<4,6>
}
int sumaArreglo(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *(arr + i);
    }
    return suma;
}

// PUNTO 3
int encontrarMayor(int *arr, int n) {
    if (n <= 0) return -1;

    int mayor = *arr;
    for (int *p = arr; p < arr + n; p++) {
        if (*p > mayor) {
            mayor = *p;
        }
    }
    return mayor;
}

// PUNTO 4
void duplicar(int *x) {
    *x = (*x) * 2;
}

void aplicarOperacion(int arr, int n, void (*func)(int)) {
    for (int i = 0; i < n; i++) {
        func(arr + i);
    }
}

// PUNTO 5
void sumaFilas(int **mat, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < cols; j++) {
            suma += ((mat + i) + j);
        }
        cout << "Suma fila " << i << ": " << suma << endl;
    }
}

// PUNTO 6
void imprimirComoEntero(int *p) {
    cout << "Valor reinterpretado como int: " << *p << endl;
    cout << "Direccion: " << p << endl;
}

void imprimirBytes(char *p, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Byte " << i << ": " << (int)*(p + i)
             << " Direccion: " << (void*)(p + i) << endl;
    }
}

int main() {

    cout << "===== PUNTO 1 =====" << endl;
    int a = 5, b = 10;
    cout << "Antes: a=" << a << " b=" << b << endl;
    intercambiar(&a, &b);
    cout << "Despues: a=" << a << " b=" << b << endl;

    cout << "\n===== PUNTO 2 y 3 =====" << endl;
    int n = 5;
    int *arr = new int[n]{3, 7, 2, 9, 4};

    cout << "Arreglo: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    cout << "Suma: " << sumaArreglo(arr, n) << endl;
    cout << "Mayor: " << encontrarMayor(arr, n) << endl;

    cout << "\n===== PUNTO 4 =====" << endl;
    aplicarOperacion(arr, n, duplicar);

    cout << "Arreglo duplicado: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    cout << "\n===== PUNTO 5 =====" << endl;
    int filas = 2, cols = 3;

    int *mat = new int[filas];

    for (int i = 0; i < filas; i++) {
        mat[i] = new int[cols];
    }

    // Valores ya definidos
    int valores[2][3] = {{1,2,3},{4,5,6}};

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            ((mat + i) + j) = valores[i][j];
        }
    }

    sumaFilas(mat, filas, cols);

    cout << "\n===== PUNTO 6 =====" << endl;
    float num = 3.14;

    int pInt = (int)&num;
    char pChar = (char)&num;

    cout << "Float original: " << num << endl;
    cout << "Direccion float: " << &num << endl;

    imprimirComoEntero(pInt);
    imprimirBytes(pChar, sizeof(float));

    // Liberar memoria
    delete[] arr;

    for (int i = 0; i < filas; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
