#include<iostream>
#include<string>
using namespace std;

struct Contacto {
    string nombre;
    string correo;
    string telefono;
};

const int maxi_contactos = 100;
Contacto contactos[maxi_contactos];
int numContactos = 0;
//funciones modulares
void agregarContacto() {
    if (numContactos >= maxi_contactos) {
        cout << "No se pueden agregar mas contactos.\n";
        return;
    }

    cin.ignore();
    cout << "Nombre: ";
    getline(cin, contactos[numContactos].nombre);

    cout << "Correo: ";
    getline(cin, contactos[numContactos].correo);

    cout << "Telefono: ";
    getline(cin, contactos[numContactos].telefono);

    numContactos++;
    cout << "Contacto agregado correctamente.\n";
}

void mostrarContactos() {
    if (numContactos == 0) {
        cout << "No hay contactos registrados.\n";
        return;
    }

    cout << "\nLISTADO DE CONTACTOS:\n";
    for (int i = 0; i < numContactos; i++) {
        cout << i + 1 << ". "
             << contactos[i].nombre << " | "
             << contactos[i].correo << " | "
             << contactos[i].telefono << endl;
    }
}

void modificarContacto() {
    if (numContactos == 0) {
        cout << "No hay contactos para modificar.\n";
        return;
    }

    mostrarContactos();
    int idx;
    cout << "Seleccione el numero del contacto a modificar: ";
    cin >> idx;

    if (idx >= 1 && idx <= numContactos) {
        cin.ignore();
        cout << "Nuevo nombre: ";
        getline(cin, contactos[idx - 1].nombre);

        cout << "Nuevo correo: ";
        getline(cin, contactos[idx - 1].correo);

        cout << "Nuevo telefono: ";
        getline(cin, contactos[idx - 1].telefono);

        cout << "Contacto modificado correctamente.\n";
    } else {
        cout << "Indice invalido.\n";
    }
}