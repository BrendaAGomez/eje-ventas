// Una empresa de electrodomésticos cuenta con vendedores en diferentes sucursales. Al finalizar el mes se cuenta con los datos de cada venta ordenados por
// código de vendedor en forma ascendente:

// - Código de vendedor
// - Fecha de venta
// - Producto vendido
// - Monto de la venta
// - Comisión ganada

// Y en forma separada, los datos de cada vendedor:

// - Código de vendedor
// - Nombre
// - Apellido
// - Sucursal (1: Centro, 2: Shopping)

// Los datos ya están cargados en vectores estáticos y que cada vector tiene una variable asociada que indica la cantidad de elementos cargados.

// Se asume que cada vendedor realiza al menos una venta en el mes.

// ---

// ## Se pide:

// **1)** Definir las estructuras de datos necesarias para soportar la solución del problema.

// **2)** Escribir una función que ordene el vector de vendedores por sucursal (ordenamiento burbuja).

// **3)** Escribir una función que busque en el vector de vendedores por código y devuelva la posición en el vector (búsqueda binaria).

// **4)** Escribir una función que genere un nuevo vector con cada vendedor y su total de comisiones del mes, utilizando apareo entre ambos vectores.
// **Importante:** Si el monto de la venta supera los $20.000 y la sucursal es Centro (1), se debe aumentar la comisión en un 15% antes de sumarla al total.

// **5)** Escribir una función que muestre un reporte por sucursal indicando: nombre de la sucursal, cantidad total de ventas y el vendedor con mayor total
// de comisiones (usar corte de control).

#include <iostream>
#include <string>
using namespace std;

// Variables globales con datos precargados
const int MAX_VENDEDORES = 100;
const int MAX_VENTAS = 500;
const int MAX_RESULTADO = 100;

struct Vendedor
{
    int id_vendedor;
    string nombre;
    string apellido;
    int sucursal;
};

struct Venta
{
    int id_vendedor;
    long fecha_venta;
    string producto_vendido;
    float monto_venta;
    float comision_ganada;
};

struct VendedorConTotal
{
    int id_vendedor;
    string nombre;
    string apellido;
    float comision_total;
};

void ordenar_vendedores(Vendedor vendedores[], int nVendedores)
{
    for (int i = 0; i < nVendedores - 1; i++)
    {
        for (int j = i + 1; j < nVendedores; j++)
        {
            if (vendedores[i].sucursal > vendedores[j].sucursal)
            {
                Vendedor aux = vendedores[j];
                vendedores[j] = vendedores[i];
                vendedores[i] = aux;
            }
        }
    }
}

int buscar_vendedor(Vendedor vendedores[], int nVendedores, int valor)
{
    int inicio = 0;
    int fin = nVendedores - 1;
    int posicion = -1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (vendedores[medio].id_vendedor == valor)
        {
            posicion = medio;
        }

        if (vendedores[medio].id_vendedor > valor)
        {
            fin = medio - 1;
        }
        else
        {
            inicio = medio + 1;
        }
    }

    return posicion;
}

void nuevo_vector(Vendedor vendedores[], int nVendedores, Venta ventas[], int nVentas, VendedorConTotal comisiones[], int &nComisiones)
{
    int i = 0; // índice para vendedores
    int j = 0; // índice para ventas

    while (i < nVendedores)
    {
        int id_actual = vendedores[i].id_vendedor;
        float total_comision = 0;

        while (j < nVentas && ventas[j].id_vendedor == id_actual)
        {
            float com = ventas[j].comision_ganada;

            if (ventas[j].monto_venta > 20000 && vendedores[i].sucursal == 1)
            {
                com *= 1.15; // se aplica el 15% extra
            }

            total_comision += com;
            j++; // sigo con la próxima venta del mismo vendedor
        }

        // guardo los datos en el nuevo vector
        comisiones[nComisiones++] = {id_actual, vendedores[i].nombre, vendedores[i].apellido, total_comision};

        i++; // paso al siguiente vendedor
    }
}

int main()
{
    // Vector de vendedores (ordenado por código ascendente)
    Vendedor vendedores[MAX_VENDEDORES] = {
        {101, "Juan", "Perez", 1},
        {103, "Ana", "Lopez", 1},
        {105, "Carlos", "Ruiz", 2},
        {107, "Maria", "Garcia", 2},
        {109, "Luis", "Martinez", 1}};
    int cantVendedores = 5;

    // Vector de ventas (ordenado por código de vendedor ascendente)
    Venta ventas[MAX_VENTAS] = {
        {101, 15032024, "Heladera", 15000.0, 450.0},
        {101, 16032024, "Microondas", 25000.0, 750.0},
        {101, 18032024, "Lavarropas", 30000.0, 900.0},
        {103, 17032024, "Televisor", 18000.0, 540.0},
        {103, 20032024, "Aire Acond.", 22000.0, 660.0},
        {105, 19032024, "Cocina", 12000.0, 360.0},
        {105, 21032024, "Freezer", 16000.0, 480.0},
        {105, 22032024, "Lavavajillas", 28000.0, 840.0},
        {107, 23032024, "Heladera", 35000.0, 1050.0},
        {107, 25032024, "Televisor", 40000.0, 1200.0},
        {109, 26032024, "Microondas", 8000.0, 240.0},
        {109, 28032024, "Cocina", 45000.0, 1350.0}};
    int cantVentas = 12;

    // ordenar_vendedores(vendedores, cantVendedores);

    // for (int i = 0; i < cantVendedores; i++)
    // {
    //     cout << vendedores[i].sucursal << " " << vendedores[i].nombre << endl;
    // } la funcion esta perfecta pero, me desordena el array de vendedores entonces cuando se utiliza esta no se puede utilizar las demas que necesiten el array ordenado

    int resultado_busqueda = buscar_vendedor(vendedores, cantVendedores, 103);

       if (resultado_busqueda != -1) {
            cout << "el codigo de vendedor: " << vendedores[resultado_busqueda].id_vendedor << " esta en la posicion: " << resultado_busqueda << endl;
        } else {
            cout << "el codigo de vendedor no se encuentra cargado"  << endl;
        } 

    // Vector resultado del apareo
    VendedorConTotal resultado[MAX_RESULTADO];
    int comisiones;
    nuevo_vector(vendedores, cantVendedores, ventas, cantVentas, resultado, comisiones);
    int cantResultado = comisiones;
    for(int i = 0; i < cantResultado; i++){
        cout << resultado[i].id_vendedor << " " << resultado[i].nombre << " " << resultado[i].apellido<< " " << resultado[i].comision_total << endl;
    }


    return 0;
}
