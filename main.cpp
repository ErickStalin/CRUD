#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Declaracion de constantes
const int TAM = 100;
//Declaracion de estructuras
typedef struct {
    string nombre;
    string especialidad;
    string identificacion;
    int edad;
}tMedicos;
typedef struct {
    tMedicos elementos[TAM];
    int contador;
}tContenedor;
//Declaracion de prototipos de las funciones 
int menu();
void cargar(tContenedor& lista, bool& ok);
void buscar(const tContenedor lista);
void iscribir(tMedicos& medico1);
void insertar(tContenedor& lista, tMedicos medico1);
void eliminar(tContenedor& lista, int pos);
void mostrar(tContenedor& lista);
void leer( tMedicos medico1);
int main()
{
    int op = -1;
    tMedicos medico1;
    tContenedor lista;
    bool compro = false;
    cargar(lista,compro);
    while (op != 0) {
        op = menu();
        switch (op) {
        case 1:
        {
            buscar(lista);
        }
        break;
        case 2:
        {
            iscribir(medico1);
            insertar(lista, medico1);
        }
        break;
        case 3:
        {
            int pos = 0;
            cout<<"---LISTA DE MEDICOS---"<<endl;
            mostrar(lista);
            cout<<endl;
            cout<<"///---ELIMINAR DATOS---///"<<endl;
            cout<<"Ingrese la posicion del elemento que quiere eliminar: ";
            cin>>pos;
            eliminar(lista,pos);
        }
        break;
        case 4:
        {

        }
        break;
        }
    }
    return 0;
}
//DEsarrollo de los prototipos
int menu() {
    int opcion = 0;
    cout << "---MENU MEDICOS---" << endl;
    cout << "1.- Buscar medico" << endl;
    cout << "2.- Ingresar medico" << endl;
    cout << "3.- Eliminar medico" << endl;
    cout << "0.- Salir" << endl;
    cout << "Ingrese la opcion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > 4) {
        cout << "OPCION ERRONEA!!" << endl;
        cout << "Ingrese de nuevo la opcion: ";
        cin >> opcion;
    }
    return opcion;
}
void cargar(tContenedor& lista,bool& ok){
    ifstream archivo;
    tMedicos aus1;
    char salto;
    lista.contador = 0;
    archivo.open("medicos.txt");
    if (!archivo.is_open()) {
        ok = false;
    }
    else {
        ok = true;
        getline(archivo, aus1.nombre);
        while ((aus1.nombre != "XXX") && (lista.contador < TAM)) {
            getline(archivo, aus1.identificacion);
            getline(archivo, aus1.especialidad);
            archivo >> aus1.edad;
            archivo.get(salto);
            lista.elementos[lista.contador] = aus1;
            lista.contador++;
            getline(archivo, aus1.nombre);
        }
        archivo.close();
    }
}
void buscar(const tContenedor lista) {
    string dato1;
    bool encontrar = false;
    cout << "Ingrese el numero de identificacion del medico que quiere buscar: ";
    cin >> dato1;
    for (int i = 0; i < lista.contador; i++) {
        if (dato1 == lista.elementos[i].identificacion) {
            cout << "//---ELEMENTO ENCONTRADO!!---//" << endl;
            cout << "Nombre: " << lista.elementos[i].nombre << endl;
            cout << "Especialidad: " << lista.elementos[i].especialidad << endl;
            cout << "Edad: " << lista.elementos[i].edad << endl;
            cout << "Identificacion: " << lista.elementos[i].identificacion << endl;
            encontrar = true;
        }
        else {
            encontrar = false;
        }
    }
    if (encontrar != true) {
        cout << "ELEMENTO NO EXISTENTE!!" << endl;
    }
}

void iscribir(tMedicos& medico1) {
    cin.sync();
    cout << "Ingrese el nombre del medico: ";
    cin.ignore();
    getline(cin, medico1.nombre);
    cout << "Ingrese el numero de identificacion: ";
    getline(cin, medico1.identificacion);
    cout << "Ingrese la especialidad: ";
    getline(cin, medico1.especialidad);
    cout << "Ingrese la edad del medico: ";
    cin >> medico1.edad;
    cin.sync();
}

void insertar(tContenedor& lista, tMedicos medico1) {
    lista.elementos[lista.contador] = medico1;
    lista.contador++;
}

void eliminar(tContenedor& lista, int pos){
  for(int i = pos; i < lista.contador; i++){
    lista.elementos[i] = lista.elementos[i + 1 ];
  }
  lista.contador--;
}

void leer( tMedicos medico1){
  cout<<"Nombre: "<<medico1.nombre<<endl;
  cout<<"Especialidad: "<<medico1.especialidad<<endl;
  cout<<"Identificacion: "<<medico1.identificacion<<endl;
  cout<<"Edad: "<<medico1.edad<<endl;
}
void mostrar(tContenedor& lista){
  for(int i = 0; i < lista.contador; i++){
    leer(lista.elementos[i]);
  }
}