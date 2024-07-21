#include<iostream>
#include<cmath>
using namespace std;

enum Planes{X, Y, Z, XY, XZ, YZ}; // Planos/ejes de coordenadas
enum Dimensions{D1, D2, D3}; // Dimensiones disponibles
enum Mode{POLAR, CARTESIANS}; // Formato de coordenadas

int save_points = 0; // Cantidad de puntos guardados
int format = CARTESIANS; // Formato actual

// Estructura de coordenadas polares
struct Polar{   
   double alpha = 0;
   double beta = 0;
   double radius = 0;
};

// Clase punto
class Point{
private:
    double* coordinates; // Coordenadas 
    int dimension; // Dimensión del punto

public:
    Point(double x);
    Point(double x, double y);
    Point(double x, double y, double z);
    Point(double coords[], int dimension);

    ~Point(); // Destructor

    double get_distance_to_center();
    double* get_vector(); // Devuelve puntero a coordenadas
    int get_dimension();
    bool compare(Point); // Compara un punto externo con el punto actual
    static bool compare(Point, Point); // Compara dos puntos cualquiera
    static Point createPoint(double, double, double); // Devuelve un punto
};

Point::Point(double x) : dimension(D1) {
    coordinates = new double[1];
    coordinates[0] = x;
}

Point::Point(double x, double y) : dimension(D2) {
    coordinates = new double[2];
    coordinates[0] = x;
    coordinates[1] = y;
}

Point::Point(double x, double y, double z) : dimension(D3) {
    coordinates = new double[3];
    coordinates[0] = x;
    coordinates[1] = y;
    coordinates[2] = z;
}

Point::Point(double coords[], int dim) : dimension(dim) {
    coordinates = new double[dim];
    for(int i = 0; i < dim; ++i){
        coordinates[i] = coords[i];
    }
}

Point::~Point() {
    delete[] coordinates;
}

int Point::get_dimension() {
    return dimension;
}

double Point::get_distance_to_center() {
    double sum = 0;
    for(int i = 0; i < dimension; ++i){
        sum += coordinates[i] * coordinates[i];
    }
    return sqrt(sum);
}

double* Point::get_vector() {
    return coordinates;
}

Point Point::createPoint(double x, double y, double z) {
    if(z != 0) return Point(x, y, z);
    if(y != 0) return Point(x, y);
    return Point(x);
}

bool Point::compare(Point p1, Point p2) {
    if(p1.dimension != p2.dimension) return false;
    for(int i = 0; i < p1.dimension; ++i){
        if(p1.coordinates[i] != p2.coordinates[i]) return false;
    }
    return true;
}

bool Point::compare(Point p) {
    if(dimension != p.dimension) return false;
    for(int i = 0; i < dimension; ++i){
        if(coordinates[i] != p.coordinates[i]) return false;
    }
    return true;
}
