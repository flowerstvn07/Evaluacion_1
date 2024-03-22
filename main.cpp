#include <iostream>
#include "Cliente.h"
#include "Fecha.h"
#include "Prestamo.h"
#include "Pago.h"
#include "stdlib.h"

#define TAM 5

using namespace std;

int menu(){
    int opcion;

    cout << "---------MENU DE OPCIONES---------\n\n";

    cout << "**********************************\n";
    cout << "1. Agregar clientes a la lista\n";
    cout << "2. Agregar prestamo a la lista\n";
    cout << "3. Hacer pagos de prestamos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostrar detalles del prestamo\n";
    cout << "7. Salir\n";
    cout << "**********************************\n";

    cout << "\nDigite una opcion: ";
    cin >> opcion;

    return opcion;
}

Cliente* agregarCliente(){
    int codigo;
    string nombre, apellido;

    cout << "\nDigite el codigo del cliente: ";
    cin >> codigo;

    cout << "Digite el nombre del cliente: ";
    cin >> nombre;

    cout << "Digite el apellido del cliente: ";
    cin >> apellido;

    Cliente* cliente = new Cliente(codigo, nombre, apellido);
    return cliente;
}

Cliente* buscarCliente(Cliente** listaDeClientes, int contadorClientes, int codCliente){
    for(int i = 0; i < contadorClientes; i++){
        if(listaDeClientes[i]->getIdCliente() == codCliente){
            return listaDeClientes[i];
        }
    }
    return nullptr;
}

Prestamo* buscarPrestamo(Prestamo** listaPrestamos, int contadorPrestamos, int codPrestamo){
    for(int i = 0; i < contadorPrestamos; i++){
        if(listaPrestamos[i]->getNumeroPrestamo() == codPrestamo){
            return listaPrestamos[i];
        }
        return nullptr;
    }
}

Prestamo* agregarPrestamo(Cliente* lstCliente[], int contadorClientes, Cliente* cliente){
    int numPrestamo;
    float montoAprobado;
    int dia, mes, anio;
    Prestamo* prestamo = nullptr;

    if(cliente != nullptr){
        cout << "\nDigite el codigo del prestamo: ";
        cin >> numPrestamo;

        cout << "Digite la fecha de aprobacion (dd/mm/aa)" << endl;

        cout << "Dia: ";
        cin >> dia;

        cout << "Mes: ";
        cin >> mes;

        cout << "Anio: ";
        cin >> anio;

        cout << "Digite el monto aprobado: $";
        cin >> montoAprobado;

        Fecha* fecha = new Fecha(dia, mes, anio);
        prestamo = new Prestamo(numPrestamo, cliente, fecha, montoAprobado);

        return prestamo;

    }
}

Pago* agregarPago(Pago* listaPagos[], int contadorPagos, Prestamo* listaPrestamos[], int contadorPrestamo, Prestamo* prestamo){
    int numeroPrestamo, dia, mes, anio;
    float montoPago;
    Pago* pago = nullptr;

    if(prestamo != nullptr){
        cout << "\nDigite la fecha del pago (dd/mm/aa) " << endl;

        cout << "Dia: ";
        cin >> dia;

        cout << "Mes: ";
        cin >> mes;

        cout << "Anio: ";
        cin >> anio;

        cout << "Digite el monto del pago: $";
        cin >> montoPago;

        Fecha* fecha = new Fecha(dia, mes, anio);
        pago = new Pago(fecha, montoPago);

       if(prestamo->hacerPago(pago)){
            cout << "\n\tPago realizado exitosamente\n" << endl;
       }
       else{
            cout << "\n\tEl monto es superior al saldo\n" << endl;
       }
    }
    return pago;
}

void mostrarListaDeClientes(Cliente* listaDeClientes[], int contadorClientes){
    if(contadorClientes != 0){
        cout << "\n*******LISTA DE CLIENTES*******" << endl;

        for(int i = 0; i < contadorClientes; i++){
            cout << "\n-------------------------" << endl;

            cout << "Codigo: ";
            cout << listaDeClientes[i]->getIdCliente();

            cout << "\nNombre: ";
            cout << listaDeClientes[i]->getNombre();

            cout << "\nApellido: ";
            cout << listaDeClientes[i]->getApellido();

            cout << "\n-------------------------" << endl;
        }
    }
    else{
        cout << "\n\tLa lista de clientes esta vacia\n" << endl;
    }
}

void mostrarListaDePrestamo(Prestamo* listaDePrestamo[], int contadorPrestamo){
    if(contadorPrestamo != 0){
        cout << "\n*******LISTA DE PRESTAMOS*******" << endl;

        for(int i = 0; i < contadorPrestamo; i++){
            cout << "\n--------------------------------" << endl;

            cout << "Codigo: ";
            cout << listaDePrestamo[i]->getNumeroPrestamo();

            cout << "\nMonto Aprobado: $";
            cout << listaDePrestamo[i]->getMontoAprobado();

            cout << "\nSaldo Pendiente: $";
            cout << listaDePrestamo[i]->getSaldoPendiente();

            cout << "\nFecha de Aprobacion: ";
            listaDePrestamo[i]->getFechaAprobacion()->mostrarFecha();

            cout << "\n--------------------------------" << endl;
        }
    }
    else{
        cout << "\n\tLa lista de prestamos esta vacia\n" << endl;
    }
}

void mostrarDetallesPrestamo(Prestamo* listaDePrestamos[], int contadorPrestamo, int numeroPrestamo){
    Prestamo* prestamo = buscarPrestamo(listaDePrestamos, contadorPrestamo, numeroPrestamo);

    if(prestamo){
        cout << "\n*******DETALLES DEL PRESTAMO*******" << endl;

        cout << "\n------------------------------" << endl;

        cout << "Cliente: " << prestamo->getCliente()->getNombre() << " " << prestamo->getCliente()->getApellido();

        if(prestamo->getContadorPagos() != 0){
            cout << "\nSaldo pendiente: $" << prestamo->getSaldoPendiente() << endl;

            cout << "Fecha de Aprobacion: ";
            prestamo->getFechaAprobacion()->mostrarFecha();

            cout << "\n------------------------------" << endl;

            cout << "\n\tPAGOS" << endl;
            Pago** pagos = prestamo->getLstPagos();

            cout << "\n-------------------------" << endl;
            for(int i = 0; i < prestamo->getContadorPagos(); i++){
                cout << "Fecha: ";
                pagos[i]->getFechaPago()->mostrarFecha();

                cout << "\nMonto: $";
                cout << pagos[i]->getMontoPago();

                cout << "\n-------------------------" << endl;
            }

        }
    }
    else{
        cout << "\n\t Prestamo no encontrado\n" << endl;
    }
}

int main(){
    int contadorClientes = 0, contadorPrestamos = 0, contadorPagos = 0, opcion = 0;
    Cliente* cliente = nullptr;
    Prestamo* prestamo = nullptr;
    Pago* pago = nullptr;
    Cliente* listaClientes[TAM];
    Prestamo* listaPrestamo[TAM];
    Pago* listaPagos[TAM];

    do{
        system("cls");
        opcion = menu();
        switch(opcion){
            case 1:
                if(contadorClientes < TAM){
                    listaClientes[contadorClientes] = agregarCliente();
                    contadorClientes++;

                    cout << "\n\tCliente agregado exitosamente\n" << endl;

                }
                else{
                    cout << "\n\tLa lista de clientes esta llena\n" << endl;
                }
                break;
            case 2:
                if(contadorPrestamos < TAM){
                    int idCliente;

                    cout << "\nDigite el codigo del cliente a buscar: ";
                    cin >> idCliente;

                    cliente = buscarCliente(listaClientes, contadorClientes, idCliente);

                    if(cliente != nullptr){
                        listaPrestamo[contadorPrestamos] = agregarPrestamo(listaClientes, contadorClientes, cliente);
                        contadorPrestamos++;

                        cout << "\n\tEl prestamo se realizo exitosamnte\n" << endl;

                    }
                    else{
                        cout << "\n\tNo se encontro el cliente\n" << endl;
                    }
                }
                else{
                    cout << "\n\tLa lista de prestamos llena\n" << endl;
                }
                break;
            case 3:
                int numeroPago;

                if(contadorPagos < TAM){
                    cout << "\nDigite el codigo del prestamo al cual desea realizar el pago: ";
                    cin >> numeroPago;

                    prestamo = buscarPrestamo(listaPrestamo, contadorPrestamos, numeroPago);

                    if(prestamo != nullptr){
                        listaPagos[contadorPagos] = agregarPago(listaPagos, contadorPagos, listaPrestamo, contadorPrestamos, prestamo);
                        contadorPagos++;
                    }
                    else{
                        cout << "\n\tPrestamo no encontrado\n" << endl;
                    }
                }
                else{
                    cout << "\n\tLa lista de pagos esta llena\n" << endl;
                }
                break;
            case 4:
                mostrarListaDeClientes(listaClientes, contadorClientes);
                break;

            case 5:
                mostrarListaDePrestamo(listaPrestamo, contadorPrestamos);
                break;

            case 6:
                int numPrestamo;

                cout << "\nDigite el codigo del prestamo: ";
                cin >> numPrestamo;

                mostrarDetallesPrestamo(listaPrestamo, contadorPrestamos, numPrestamo);
                break;
            case 7:
                cout << "\n\tSaliendo del programa...\n" << endl;
                break;
            default:
                cout << "\n\tError. Opcion invalida\n" << endl;
                break;
        }
        system("pause");
    }while(opcion != 7);
    return 0;
}
