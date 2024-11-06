#include <iostream>
#include <windows.h> // Para cambiar colores de texto
#include <conio.h> // Para capturar input sin mostrarlo (en login)
using namespace std;

// Prototipos de las funciones
void mostrarMenu();
void cargarDatos(int datos[], int& numDatos);
void visualizarDatos(const int datos[], int numDatos);
void cambiarColor(int color);

int main() {
    // Variables para el login
    string usuarioCorrecto = "admin";
    string contrasenaCorrecta = "12345";
    string usuarioIngresado, contrasenaIngresada;
    
    // Intento de login
    cout << "=== Login ===" << endl;
    cout << "Usuario: ";
    cin >> usuarioIngresado;
    cout << "Contrasena: ";
    char c;
    while ((c = _getch()) != '\r') { // Captura hasta Enter (Enter es '\r')
        contrasenaIngresada += c;
        cout << '*'; // Muestra asteriscos para ocultar la contraseña
    }
    cout << endl;

    if (usuarioIngresado == usuarioCorrecto && contrasenaIngresada == contrasenaCorrecta) {
        cout << "Acceso concedido.\n";
        goto menu;
    } else {
        cout << "Usuario o contrasena incorrectos. Programa finalizado.\n";
        return 0;
    }

menu:
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcion;
    int datos[5] = {0}; // Array para almacenar hasta 5 datos
    int numDatos = 0;

    do {
        cambiarColor(11); // Cambia el color a cian claro
        cout << "\n=== Menu Principal ===" << endl;
        cout << "1. Cargar Datos" << endl;
        cout << "2. Visualizar Datos" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargarDatos(datos, numDatos);
                break;
            case 2:
                visualizarDatos(datos, numDatos);
                break;
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 3);
}

void cargarDatos(int datos[], int& numDatos) {
    cambiarColor(10); // Cambia el color a verde
    cout << "\n--- Carga de Datos ---" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Ingrese un numero (" << i + 1 << " de 5): ";
        cin >> datos[i];
        numDatos++;
    }
    cout << "Datos cargados exitosamente.\n";
}

void visualizarDatos(const int datos[], int numDatos) {
    cambiarColor(14); // Cambia el color a amarillo
    cout << "\n--- Visualizacion de Datos ---" << endl;
    if (numDatos == 0) {
        cout << "No hay datos para mostrar.\n";
    } else {
        for (int i = 0; i < numDatos; ++i) {
            cout << "Dato " << i + 1 << ": " << datos[i] << endl;
        }
    }
}

void cambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
