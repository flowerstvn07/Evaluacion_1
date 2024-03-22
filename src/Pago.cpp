#include "Pago.h"

Pago::Pago(Fecha* fechaP, float monto){
    this->fechaPago = fechaP;
    this->montoPago = monto;
}

Pago::~Pago(){
    //dtor
}

Fecha* Pago::getFechaPago(){
    return this->fechaPago;
}

float Pago::getMontoPago(){
    return this->montoPago;
}
