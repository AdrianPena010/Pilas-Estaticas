#include <iostream>
#include <string>

using namespace std;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportA;

public:
    Empleado(int C = 0, string N = "", string D = "", float S = 0.0, string R = "")
        : ClaveEmpleado(C), Nombre(N), Domicilio(D), Sueldo(S), ReportA(R) {}

    // Setters
    void SetClaveEmpleado(int C) { ClaveEmpleado = C; }
    void SetNombre(string N) { Nombre = N; }
    void SetDomicilio(string D) { Domicilio = D; }
    void SetSueldo(float S) { Sueldo = S; }
    void SetReportA(string R) { ReportA = R; }

    // Getters
    int GetClaveEmpleado() const { return ClaveEmpleado; }
    string GetNombre() const { return Nombre; }
    string GetDomicilio() const { return Domicilio; }
    float GetSueldo() const { return Sueldo; }
    string GetReportA() const { return ReportA; }

    // Sobrecarga de operadores
    friend ostream &operator<<(ostream &o, const Empleado &e)
    {
        o << "Clave: " << e.ClaveEmpleado << endl;
        o << "Nombre: " << e.Nombre << endl;
        o << "Domicilio: " << e.Domicilio << endl;
        o << "Sueldo: $" << e.Sueldo << endl;
        o << "Reporta: " << e.ReportA << endl;
        return o;
    }

    friend istream &operator>>(istream &i, Empleado &e)
    {
        cout << "\nIngresa la Clave: ";
        i >> e.ClaveEmpleado;
        cout << "Ingresa Nombre: ";
        i.ignore(); // Clear newline from input buffer
        getline(i, e.Nombre);
        cout << "Ingresa Domicilio: ";
        getline(i, e.Domicilio);
        cout << "Ingresa Sueldo: $";
        i >> e.Sueldo;
        cout << "Ingresa Reporta: ";
        i.ignore(); // Clear newline from input buffer
        getline(i, e.ReportA);
        return i;
    }

    bool operator==(const Empleado &e) const { return ClaveEmpleado == e.ClaveEmpleado; }
    bool operator!=(const Empleado &e) const { return ClaveEmpleado != e.ClaveEmpleado; }
    bool operator<(const Empleado &e) const { return ClaveEmpleado < e.ClaveEmpleado; }
    bool operator<=(const Empleado &e) const { return ClaveEmpleado <= e.ClaveEmpleado; }
    bool operator>(const Empleado &e) const { return ClaveEmpleado > e.ClaveEmpleado; }
    bool operator>=(const Empleado &e) const { return ClaveEmpleado >= e.ClaveEmpleado; }

    void Imprime() const
    {
        cout << "\tDatos del empleado...\n";
        cout << "Clave: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: $" << Sueldo << endl;
        cout << "Reporta: " << ReportA << endl;
    }
};

const int Tam = 500;

class Pila {
private:
    Empleado datos[Tam];
    int index;

public:
     Pila()
        {
         index=-1;
        }
    bool llena()const;
    bool vacia()const;
    bool push(const Empleado &dato);
    bool pop();
    bool top()const;
};

bool Pila::llena()const
{
    if(index==Tam-1)
            return true;
        return false;

}

bool Pila::vacia()const
{
    if(index==-1)
            return true;
        return false;

}

bool Pila::top()const
{
   if (vacia())
    {
        return -1;
    }
            for (int i = 0; i <= index; ++i) {
            cout << datos[i] << endl;
        }


}

bool Pila::push(const Empleado& dato)
{
     if (llena())
    {
        return index==Tam-1;
    }

    datos[++index] = dato;

}


bool Pila::pop()
{
    if (vacia())
    {
        return index==-1;
    }
    --index;
}


int main()
{
    Pila Mipila;
    int opcion;
    Empleado emp;

    do {
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. TOP";
        cout << "\n4. SALIR";
        cout << "\nElige una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                cout << "Ingrese los datos del empleado:" << endl;
                cin >> emp;
                Mipila.push(emp);
                cin.ignore();
                break;
            case 2:
                Mipila.pop();
                break;
            case 3:
                Mipila.top();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (opcion != 4);

    return 0;
}


