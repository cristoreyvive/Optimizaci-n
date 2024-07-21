#include<iostream>
#include "../controller/fileController.cpp"

using namespace std;

float point[3];
int dimension = 3;
char formato;

// Guarda un punto haciendo una llamada a la función add_point de pointController
void savePoint() {
    char opt;
    cout << "Desea guardar el punto (s = Si, n = No)" << endl;
    cin >> opt;
    if(opt != 's') return;

    cout << "Por favor, ingrese formato para guardar (p = Polar, c = Cartesianas)" << endl;
    cin >> opt;
    if(opt == 'p' && formato == 'p') {
        Polar p {point[0], point[1], point[2]};
        add_point(p, dimension);
    } else if(opt == 'p' && formato == 'c') {
        add_point(convertPolar(getPoint(point[0], point[1], point[2])), dimension);
    } else if(opt == 'c' && formato == 'c') {
        add_point(getPoint(point[0], point[1], point[2]));
    } else {
        Polar p {point[0], point[1], point[2]};
        add_point(convertCartesian(p, dimension));
    }
}

// Obtiene las coordenadas desde la consola
void getValues() {
    cout << "Por favor, ingrese dimension a trabajar (2 o 3)" << endl;
    cin >> dimension;
    if(dimension > 3 || dimension < 2) dimension = 3;

    cout << "Por favor, ingrese formato a trabajar (p = Polar, c = Cartesianas)" << endl;
    cin >> formato;

    if(formato == 'p') {
        cout << "Por favor, ingrese valor de radio" << endl;
        cin >> point[0];
        cout << "Por favor, ingrese valor del angulo alpha" << endl;
        cin >> point[1];
    } else {
        cout << "Por favor, ingrese valor de X" << endl;
        cin >> point[0];
        cout << "Por favor, ingrese valor de Y" << endl;
        cin >> point[1];
    }

    if(dimension == 3 && formato == 'p') {
        cout << "Por favor, ingrese valor de angulo beta" << endl;
        cin >> point[2];
    } else if(dimension == 3) {
        cout << "Por favor, ingrese valor de Z" << endl;
        cin >> point[2];
    }

    savePoint();
}

// Comparar dos puntos dados por el usuario
void compareUserPoints() {
    double p1[3] = {0, 0, 0}, p2[3] = {0, 0, 0};
    cout << "Ingrese las coordenadas del primer punto (X Y [Z]):" << endl;
    cin >> p1[0] >> p1[1];
    if(dimension == 3) cin >> p1[2];

    cout << "Ingrese las coordenadas del segundo punto (X Y [Z]):" << endl;
    cin >> p2[0] >> p2[1];
    if(dimension == 3) cin >> p2[2];

    Point point1(p1, dimension);
    Point point2(p2, dimension);

    if(samePoint(point1, point2)) {
        cout << "Los puntos son iguales." << endl;
    } else {
        cout << "Los puntos son diferentes." << endl;
    }
}

// Calcular la distancia entre dos puntos dados por el usuario
void distanceBetweenPoints() {
    double p1[3] = {0, 0, 0}, p2[3] = {0, 0, 0};
    cout << "Ingrese las coordenadas del primer punto (X Y [Z]):" << endl;
    cin >> p1[0] >> p1[1];
    if(dimension == 3) cin >> p1[2];

    cout << "Ingrese las coordenadas del segundo punto (X Y [Z]):" << endl;
    cin >> p2[0] >> p2[1];
    if(dimension == 3) cin >> p2[2];

    Point point1(p1, dimension);
    Point point2(p2, dimension);

    double distance = calculateDistance(point1, point2);
    cout << "La distancia entre los puntos es: " << distance << endl;
}
