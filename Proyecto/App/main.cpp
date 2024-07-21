#include<iostream>
#include "./view/menu.cpp"
using namespace std;

void showMenu() {
    cout << "Seleccione una opción:" << endl;
    cout << "1. Guardar un punto" << endl;
    cout << "2. Comparar dos puntos" << endl;
    cout << "3. Calcular distancia entre dos puntos" << endl;
    cout << "4. Leer archivo de puntos" << endl;
    cout << "5. Limpiar archivo de puntos" << endl;
    cout << "6. Comparar dos puntos desde archivo" << endl;
    cout << "0. Salir" << endl;
}

int main() {
    char opt = 's';
    int choice;

    while(opt == 's') {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                getValues();
                break;
            case 2:
                compareUserPoints();
                break;
            case 3:
                distanceBetweenPoints();
                break;
            case 4:
                read_file();
                break;
            case 5:
                clear_file();
                break;
            case 6:
                if(compare_points_from_file()) {
                    cout << "Los primeros dos puntos del archivo son iguales." << endl;
                } else {
                    cout << "Los primeros dos puntos del archivo son diferentes." << endl;
                }
                break;
            case 0:
                opt = 'n';
                break;
            default:
                cout << "Opción no válida." << endl;
        }

        if(opt != 'n') {
            cout << "Desea continuar? (s= SI, n= NO)" << endl;
            cin >> opt;
        }
    }
    return 0;
}
