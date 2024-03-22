#include "Prestamo.h"

Prestamo::Prestamo(){
    this->numeroPrestamo = 0;
    this->montoAprobado = 0;
    this->saldoPendiente = 0;
    this->contadorPagos = 0;
}

Prestamo::Prestamo(int numPrestamo, Cliente* cli, Fecha* fechaA, float monto){
    this->numeroPrestamo = numPrestamo;
    this->cliente = cli;
    this->fechaAprobacion = fechaA;
    this->montoAprobado = monto;
    this->contadorPagos = 0;
    this->saldoPendiente = this->montoAprobado;
}

Prestamo::~Prestamo()
{
    //dtor
}

int Prestamo::getNumeroPrestamo(){
    return this->numeroPrestamo;
}

void Prestamo::setNumeroPrestamo(int numPrestamo){
    this->numeroPrestamo = numPrestamo;
}

Cliente* Prestamo::getCliente(){
    return this->cliente;
}

void Prestamo::setCliente(Cliente* cli){
    this->cliente = cli;
}

Fecha* Prestamo::getFechaAprobacion(){
    return this->fechaAprobacion;
}

void Prestamo::setFechaAprobacion(Fecha* fechaA){
    this->fechaAprobacion = fechaA;
}

float Prestamo::getMontoAprobado(){
    return this->montoAprobado;
}

void Prestamo::setMontoAprobado(float monto){
    this->montoAprobado = monto;
}

bool Prestamo::hacerPago(Pago* pago){
    bool pagoRealizado = false;
    if(this->saldoPendiente >= pago->getMontoPago()){
        this->saldoPendiente = this->saldoPendiente - pago->getMontoPago();
        this->lstPagos[this->contadorPagos] = pago;
        this->contadorPagos++;
        pagoRealizado = true;
    }
    return pagoRealizado;
}

Pago** Prestamo::getLstPagos(){
    return this->lstPagos;
}

float Prestamo::getSaldoPendiente(){
    return this->saldoPendiente;
}

int Prestamo::getContadorPagos(){
    return this->contadorPagos;
}
