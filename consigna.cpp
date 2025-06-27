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

struct Venta {
    int id_vendedor;
    long fecha_venta;
    string producto_vendido;
    float monto_venta;
    float comision_ganada;
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

int main(){
//Vector de vendedores (ordenado por código ascendente)
Vendedor vendedores[MAX_VENDEDORES] = {
    {101, "Juan", "Perez", 1},
    {103, "Ana", "Lopez", 1},
    {105, "Carlos", "Ruiz", 2},
    {107, "Maria", "Garcia", 2},
    {109, "Luis", "Martinez", 1}};
int cantVendedores = 5;

//Vector de ventas (ordenado por código de vendedor ascendente)
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

ordenar_vendedores(vendedores, cantVendedores);

for(int i = 0; i < cantVendedores; i++){
    cout << vendedores[i].sucursal << " " << vendedores[i].nombre << endl;
}

int resultado = buscar_vendedor(vendedores, cantVendedores, 107);

   if (resultado != -1) {
        cout << "el codigo de vendedor: " << vendedores[resultado].id_vendedor << " esta en la posicion: " << resultado << endl;
    } else {
        cout << "el codigo de vendedor no se encuentra cargado"  << endl;
    }




//Vector resultado del apareo
// VendedorConTotal resultado[MAX_RESULTADO];
// int cantResultado = 0;

return 0;
}
