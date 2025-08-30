#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/* Ejercicio 1 
int main(){
    printf("Hola Orga\n");
    return 0;
}
*/
/* Ejercicio 3 : 

int main() {
    char c = 'a';
    short corto = 23; 
    long largo = 40000000000L;
    long long x = 400000000000LL;
    int xnum = 4;
    int* pointer = &xnum; 
    unsigned int num = 23232323;
    unsigned char charPasado = 130;

    printf("Char: %zu\n", sizeof(c));
    printf("Short: %zu\n", sizeof(corto));
    printf("Long: %zu\n", sizeof(largo));
    printf("Long long: %zu\n", sizeof(x));
    printf("Pointer (dirección): %zu\n", sizeof(pointer));
    printf("Unsigned int: %zu\n", sizeof(num));
    printf("Unsigned char: %zu\n", sizeof(charPasado));

    return 0;
}
*/


/*  Ejercicio 4 

int main() {
    char c = 'a';
    int8_t corto = 23; 
    int64_t largo = 40000000000L;
    int64_t  x = 400000000000LL;
    int32_t xnum = 4;
    int* pointer = &xnum; 
    unsigned int num = 23232323;
    unsigned char charPasado = 130;

    printf("Char: %zu\n", sizeof(c));
    printf("Short: %zu\n", sizeof(corto));
    printf("Long: %zu\n", sizeof(largo));
    printf("Long long: %zu\n", sizeof(x));
    printf("Pointer (dirección): %zu\n", sizeof(pointer));
    printf("Unsigned int: %zu\n", sizeof(num));
    printf("Unsigned char: %zu\n", sizeof(charPasado));

    return 0;
}
*/


/* Ejercicio 5 

int main() {
    float f = 0.1f;      // 0.1 como float
    double d = 0.1;      // 0.1 como double

    printf("Float: %.10f\n", f);
    printf("Double: %.20f\n", d);

    // Cast a int
    int f_to_int = (int) f;
    int d_to_int = (int) d;

    printf("Float -> int: %d\n", f_to_int);
    printf("Double -> int: %d\n", d_to_int);

    return 0;
}
*/


/* Ejercico 6

int main() {
int mensaje_secreto[] = {116, 104, 101, 32, 103, 105, 102, 116, 32, 111,
102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32,
103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105,
111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110};
size_t length = sizeof(mensaje_secreto) / sizeof(int);
char decoded[length];
for (int i = 0; i < length; i++) {
decoded[i] = (char) (mensaje_secreto[i]); // casting de int a char
}
for (int i = 0; i < length; i++) {
printf("%c", decoded[i]);
}
}
*/

/* Ejercicio 9 
int main(){
    uint32_t num1 = 3;
    uint32_t num2 = num1 << 29;


    num1 = num1 >> 29;
    num2 = (num2 << 29) >> 29;

    if (num1 == num2)
    {
        printf("Son Iguales los 3 bits\n");
    }
    else
    {
        printf("No son igules los 3 bits\n");
    }
    return 0;
    

}
*/

int main()
{
    uint32_t arr[] = {1,2,3,4,5};

    int largo = sizeof(arr) / sizeof(arr[0]);

    uint32_t new_array[largo];
    
    for (int i = largo - 1; i >= 0; i--)
    {
        new_array[largo - i - 1] = arr[i];
    }
    
    for (int j = 0; j < largo; j++)
    {
        printf("%d\n",new_array[j]);
    }
    tirar_dado();
    int num = factorial(4);
    printf("%d\n",num);

}




void tirar_dado() {
    int contadorDeCara[6] = {0, 0, 0, 0, 0, 0};

    for (uint64_t i = 0; i < 60000000; i++) {
        int tirada = (rand() % 6) + 1;

        switch (tirada) {
            case 1: contadorDeCara[0]++; break;
            case 2: contadorDeCara[1]++; break;
            case 3: contadorDeCara[2]++; break;
            case 4: contadorDeCara[3]++; break;
            case 5: contadorDeCara[4]++; break;
            case 6: contadorDeCara[5]++; break;
        }
    }

    for (int j = 0; j < 6; j++)
        printf("La cantidad de veces que salió el %d es: %d\n", j + 1, contadorDeCara[j]);
}



int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }else
    {
        return num * factorial(num-1);
    }
}