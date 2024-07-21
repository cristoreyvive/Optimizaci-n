#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "./pointController.cpp"

using namespace std;

// Agrega un punto (coordenadas cartesianas) al archivo de puntos
void add_point(Point point, string file="./model/points.csv"){
    ofstream output(file, ios::app);
    if(!output.is_open()){
        cout << "No se pudo crear el archivo" << endl;
        return;
    }
    save_points++;
    double* coordinates = point.get_vector();
    if(point.get_dimension() == D2){
        output << coordinates[X] << ";" << coordinates[Y] << ";0" << endl;
    } else if(point.get_dimension() == D3){
        output << coordinates[X] << ";" << coordinates[Y] << ";" << coordinates[Z] << endl;
    }
    output.close();
}

// Guarda un punto (coordenadas polares) en el archivo de puntos
void add_point(Polar point, int dimension, string file="./model/points.csv"){
    ofstream output(file, ios::app);
    if(!output.is_open()){
        cout << "No se pudo crear el archivo" << endl;
        return;
    }
    save_points++;
    if(dimension == D2){
        output << point.radius << ";" << point.alpha << ";0" << endl;
    } else {
        output << point.radius << ";" << point.alpha << ";" << point.beta << endl;
    }
    output.close();
}

// Genera un archivo de puntos dado un arreglo
void generate_file_points(string file="./model/points.csv", Point points[] = {}, int size = 0, bool opt = false){
    ofstream output(file, ios::app);
    if(!output.is_open()){
        cout << "No se pudo crear el archivo" << endl;
        return;
    }
    save_points = size;
    format = opt ? CARTESIANS : POLAR;
    for (int i = 0; i < size; i++){
        double* coordinates = points[i].get_vector();
        if(opt){
            Polar p = convertPolar(points[i]);
            output << p.radius << ";" << p.alpha << ";" << (points[i].get_dimension() == D3 ? to_string(p.beta) : "0") << endl;
        } else {
            if(points[i].get_dimension() == D2){
                output << coordinates[X] << ";" << coordinates[Y] << ";0" << endl;
            } else if(points[i].get_dimension() == D3){
                output << coordinates[X] << ";" << coordinates[Y] << ";" << coordinates[Z] << endl;
            }
        }
    }
    output.close();
}

// Compara dos puntos desde un archivo
bool compare_points_from_file(string file="./model/points.csv"){
    ifstream input(file);
    if(!input.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }
    string line1, line2;
    if(!getline(input, line1) || !getline(input, line2)){
        cout << "El archivo debe contener al menos dos puntos para comparar" << endl;
        return false;
    }
    input.close();

    stringstream ss1(line1), ss2(line2);
    string temp;
    double coords1[3] = {0}, coords2[3] = {0};
    int dim1 = 0, dim2 = 0;

    for(int i = 0; getline(ss1, temp, ';') && i < 3; ++i){
        coords1[i] = stod(temp);
        dim1++;
    }
    for(int i = 0; getline(ss2, temp, ';') && i < 3; ++i){
        coords2[i] = stod(temp);
        dim2++;
    }

    Point p1(coords1, dim1);
    Point p2(coords2, dim2);

    return samePoint(p1, p2);
}

// Limpia el archivo de puntos
void clear_file(string file="./model/points.csv"){
    ofstream output(file);
    if(!output.is_open()){
        cout << "No se pudo crear el archivo" << endl;
        return;
    }
    output.close();
}

// Lee un archivo de puntos
void read_file(string file="./model/points.csv"){
    ifstream input(file);
    if(!input.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string line, word;
    cout << (format == POLAR ? "Puntos en coordenadas polares:" : "Puntos en coordenadas cartesianas:") << endl;
    while(getline(input, line)){
        stringstream s(line);
        while(getline(s, word, ';')){
            cout << word << "; ";
        }
        cout << endl;
    }
    input.close();
}
