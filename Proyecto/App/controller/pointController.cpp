#include<iostream>
#include "../model/points.h"

using namespace std;

// Cambia formato actual
void changeFormat(Mode m){ 
    format = m;
}

// Devuelve formato actual
int getFormat(){
    return format;
}

// Genera un punto
Point getPoint(float x=0, float y=0, float z=0){
    return Point::createPoint(x,y,z);
}

// Compara si dos puntos son iguales
bool samePoint(Point p1, Point p2){
    return Point::compare(p1, p2);
}

// Convierte a polar
Polar convertPolar(Point p){
    Polar vec;
    double* coordinates = p.get_vector();
    vec.radius = p.get_distance_to_center();
    if(p.get_dimension() == D2){
        vec.alpha = atan2(coordinates[Y], coordinates[X]);
    } else if(p.get_dimension() == D3){
        vec.alpha = atan2(coordinates[Y], coordinates[X]);
        vec.beta = acos(coordinates[Z] / vec.radius);
    }
    return vec;
}

// Convierte a cartesianas
Point convertCartesian(Polar p, int dimension){
    if(dimension == D2){
        return Point(p.radius * cos(p.alpha), p.radius * sin(p.alpha));
    } else if(dimension == D3){
        return Point(
            p.radius * sin(p.beta) * cos(p.alpha),
            p.radius * sin(p.beta) * sin(p.alpha),
            p.radius * cos(p.beta)
        );
    }
    return Point(0, 0, 0); // caso por defecto
}

// Calcula la distancia entre dos puntos
double calculateDistance(Point p1, Point p2){
    if(p1.get_dimension() != p2.get_dimension()){
        cout << "Puntos en dimensiones diferentes" << endl;
        return -1;
    }
    double* coords1 = p1.get_vector();
    double* coords2 = p2.get_vector();
    double sum = 0;
    for(int i = 0; i < p1.get_dimension(); ++i){
        sum += pow(coords2[i] - coords1[i], 2);
    }
    return sqrt(sum);
}
