#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nombre;
    double saldo;
};

int main() {
    Cliente clientes[100];
    int numClientes = 0;
    int opcion;

    do {
        cout << "\n--- MENU BANCO ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Consignar\n";
        cout << "4. Retirar\n";
        cout << "5. Transferir\n";
        cout << "6. Totales\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (numClientes < 100) {
                cout << "Nombre del cliente: ";
                cin >> clientes[numClientes].nombre;
                clientes[numClientes].saldo = 0;
                numClientes++;
                cout << "Cliente agregado con saldo 0.\n";
            } else {
                cout << "Limite de clientes alcanzado.\n";
            }
        }
        else if (opcion == 2) {
            if (numClientes == 0) {
                cout << "No hay clientes.\n";
            } else {
                for (int i = 0; i < numClientes; i++) {
                    cout << i+1 << ". " << clientes[i].nombre
                         << " - $" << clientes[i].saldo << endl;
                }
            }
        }
        else if (opcion == 3) {
            string nombre;
            double monto;
            cout << "Nombre del cliente: ";
            cin >> nombre;
            bool encontrado = false;
            for (int i = 0; i < numClientes; i++) {
                if (clientes[i].nombre == nombre) {
                    cout << "Monto a consignar: ";
                    cin >> monto;
                    clientes[i].saldo += monto;
                    cout << "Consignacion exitosa.\n";
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cliente no encontrado.\n";
        }
        else if (opcion == 4) {
            string nombre;
            double monto;
            cout << "Nombre del cliente: ";
            cin >> nombre;
            bool encontrado = false;
            for (int i = 0; i < numClientes; i++) {
                if (clientes[i].nombre == nombre) {
                    cout << "Monto a retirar: ";
                    cin >> monto;
                    if (monto <= clientes[i].saldo) {
                        clientes[i].saldo -= monto;
                        cout << "Retiro exitoso.\n";
                    } else {
                        cout << "Fondos insuficientes.\n";
                    }
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cliente no encontrado.\n";
        }
        else if (opcion == 5) {
            string origen, destino;
            double monto;
            cout << "Cliente origen: ";
            cin >> origen;
            cout << "Cliente destino: ";
            cin >> destino;
            int iOrigen = -1, iDestino = -1;
            for (int i = 0; i < numClientes; i++) {
                if (clientes[i].nombre == origen) iOrigen = i;
                if (clientes[i].nombre == destino) iDestino = i;
            }
            if (iOrigen == -1 || iDestino == -1) {
                cout << "Cliente no encontrado.\n";
            } else {
                cout << "Monto a transferir: ";
                cin >> monto;
                if (monto <= clientes[iOrigen].saldo) {
                    clientes[iOrigen].saldo -= monto;
                    clientes[iDestino].saldo += monto;
                    cout << "Transferencia exitosa.\n";
                } else {
                    cout << "Fondos insuficientes.\n";
                }
            }
        }
        else if (opcion == 6) {
            double total = 0;
            for (int i = 0; i < numClientes; i++) {
                total += clientes[i].saldo;
            }
            cout << "Total en el banco: $" << total << endl;
        }
        else if (opcion == 7) {
            cout << "Saliendo...\n";
        }
        else {
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 7);

    return 0;
}
