#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#define MAXPAGOS 5


class Prestamo{
    public:
        Prestamo();
        Prestamo(int, Cliente*, Fecha*, float);
        virtual ~Prestamo();
        int getNumeroPrestamo();
        void setNumeroPrestamo(int);
        Cliente* getCliente();
        void setCliente(Cliente*);
        Fecha* getFechaAprobacion();
        void setFechaAprobacion(Fecha*);
        float getMontoAprobado();
        void setMontoAprobado(float);
        bool hacerPago(Pago*);
        Pago** getLstPagos();
        float getSaldoPendiente();
        int getContadorPagos();
    protected:

    private:
        int numeroPrestamo;
        Cliente* cliente;
        Fecha* fechaAprobacion;
        float montoAprobado;
        Pago* lstPagos[MAXPAGOS];
        float saldoPendiente;
        int contadorPagos;
};

#endif // PRESTAMO_H
