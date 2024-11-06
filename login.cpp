#include <iostream>
#include <cstring> // Para funciones como strcpy y strcmp
using namespace std;

// Definimos la estructura de Usuario con char arrays
struct Usuario {
    char nombre[50];
    char apellido[50];
    int edad;
    char usuario[50];
    char contrasena[50];
};

// Prototipos de funciones
bool iniciarSesion(Usuario* usuarios, int numUsuarios);
void registrarUsuario(Usuario*& usuarios, int& numUsuarios);
void visualizarUsuarios(Usuario* usuarios, int numUsuarios);

int main() {
    int numUsuarios = 0;
    Usuario* usuarios = nullptr; // Inicialmente vacío

    int opcion;
    do {
        cout << "\n=== Menu Principal ===\n";
        cout << "1. Registrar Usuario\n";
        cout << "2. Iniciar Sesion y Visualizar Datos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                registrarUsuario(usuarios, numUsuarios);
                break;
            case 2:
                if (iniciarSesion(usuarios, numUsuarios)) {
                    visualizarUsuarios(usuarios, numUsuarios);
                } else {
                    cout << "Error: Usuario o contrasena incorrectos.\n";
                }
                break;
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    // Liberamos la memoria
    delete[] usuarios;
    return 0;
}

bool iniciarSesion(Usuario* usuarios, int numUsuarios) {
    char usuarioIngresado[50], contrasenaIngresada[50];
    cout << "\nIngrese su usuario: ";
    cin.getline(usuarioIngresado, 50);
    cout << "Ingrese su contrasena: ";
    cin.getline(contrasenaIngresada, 50);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].usuario, usuarioIngresado) == 0 &&
            strcmp(usuarios[i].contrasena, contrasenaIngresada) == 0) {
            return true;
        }
    }
    return false;
}

void registrarUsuario(Usuario*& usuarios, int& numUsuarios) {
    Usuario nuevoUsuario;
    cout << "\n=== Registro de Usuario ===\n";
    cout << "Nombre: ";
    cin.getline(nuevoUsuario.nombre, 50);
    cout << "Apellido: ";
    cin.getline(nuevoUsuario.apellido, 50);
    cout << "Edad: ";
    cin >> nuevoUsuario.edad;
    cin.ignore(); // Para limpiar el buffer de entrada
    cout << "Usuario: ";
    cin.getline(nuevoUsuario.usuario, 50);
    cout << "Contrasena: ";
    cin.getline(nuevoUsuario.contrasena, 50);

    // Creamos un nuevo array con espacio adicional
    Usuario* nuevosUsuarios = new Usuario[numUsuarios + 1];

    // Copiamos los datos antiguos al nuevo array
    for (int i = 0; i < numUsuarios; i++) {
        nuevosUsuarios[i] = usuarios[i];
    }

    // Agregamos el nuevo usuario al final
    nuevosUsuarios[numUsuarios] = nuevoUsuario;

    // Liberamos la memoria antigua
    delete[] usuarios;

    // Actualizamos el puntero y el tamaño
    usuarios = nuevosUsuarios;
    numUsuarios++;
}

void visualizarUsuarios(Usuario* usuarios, int numUsuarios) {
    cout << "\n=== Lista de Usuarios ===\n";
    for (int i = 0; i < numUsuarios; i++) {
        cout << "Nombre: " << usuarios[i].nombre << ", Apellido: " << usuarios[i].apellido
             << ", Edad: " << usuarios[i].edad << ", Usuario: " << usuarios[i].usuario << endl;
    }
}
