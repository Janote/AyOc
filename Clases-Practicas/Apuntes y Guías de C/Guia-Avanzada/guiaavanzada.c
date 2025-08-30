#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct monstruo_t
{
    char nombre[20];
    int vida;
    double ataque;
    double defensa;
} monstruo_t;


int main(int argc, char const *argv[])
{
    struct monstruo_t array_monstruoso[3] = {{"Jano",4,40,400}, {"Nico",5,50,500},{"Tomi",5,223,233}};

    for (uint32_t i = 0; i < sizeof(array_monstruoso) / sizeof(array_monstruoso[0]); i++)
    {
        printf("Nombre: %s\n",array_monstruoso[i].nombre);
        printf("Vida: %d\n",array_monstruoso[i].vida);

    }
    

}

