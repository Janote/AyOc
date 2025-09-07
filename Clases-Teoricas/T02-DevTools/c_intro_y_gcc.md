# 1. Lenguajes de Programación

## Primeros conceptos

Las CPU definidas en los modelos originales fueron para tratar con valores que pueden tener dos estados:

- `1` (Verdadero) → Tensión V  
- `0` (Falso) → Tensión 0  

Es muy difícil de programar usando solo 0 y 1, por lo que se desarrollaron otros lenguajes más sencillos.

---

## Lenguaje Ensamblador (Assembler)

Cada instrucción tiene un nombre que representa la operación que realiza, por ejemplo:

- `MOV` → MOVE  
- `ADD` → ADDITION  

Con ayuda de un programa llamado **ensamblador**, se convierte el texto a binarios, que es el lenguaje que entiende el procesador.

El texto escrito en lenguaje humano se conoce como **código fuente**.

---

## Lenguaje de Alto Nivel (C, C#, Java, C++)

A diferencia del ensamblador, cada sentencia de un programa se compone de varias instrucciones del procesador.  
Con ayuda de un programa llamado **compilador**, se convierte este texto a números binarios, explotando cada sentencia en una o más instrucciones del procesador.

---

## Primeros pasos en C

En C, una **directiva** es una instrucción especial que se le da al preprocesador antes de que el compilador traduzca tu código a binario.  
Todas comienzan con `#`.

### Ejemplos de directivas

```c
#include <archivo>   // Incluye un archivo del sistema o librería estándar
#include "archivo"   // Incluye un archivo propio del proyecto

#define PI 3.14
#define CUADRADO(x) ((x)*(x))
```

### Compilación condicional

```c
#if expresión       // Compila el código si la expresión es verdadera
#ifdef MACRO        // Compila si la macro está definida
#ifndef MACRO       // Compila si la macro no está definida
#elif expresión    // “else if” para compilación condicional
#else               // Alternativa si no se cumple el #if o #ifdef
#endif              // Cierra la directiva condicional
```

---

## Proceso de desarrollo en C (Compilation Steps)

### Herramientas de desarrollo

#### El compilador

- Analiza sintácticamente un archivo de texto que contiene un programa fuente.  
- Si está escrito correctamente, genera un **código binario** adecuado para el microprocesador.  
- Reemplaza los nombres lógicos de variables y funciones por las direcciones de memoria correspondientes.  
- **No puede resolver referencias externas**; por ejemplo, no sabe a qué dirección apunta `printf`.  
- Antes de compilar, invoca al **preprocesador**:
  - Elimina comentarios  
  - Incluye otros archivos (`#include`)  
  - Reemplaza macros (`#define`)  

Si el código tiene errores, el compilador los reporta; si no, el programa objeto se genera correctamente.

---

#### El linker

- Toma los archivos objeto generados por el compilador y los enlaza con otras bibliotecas, como `libc`.  
- Resuelve referencias a funciones externas (por ejemplo, `printf`).  
- Ordena el código y los datos en secciones comunes para crear un **ejecutable**.  
- Marca el punto de entrada del programa (`main`).  
- Se recomienda **siempre incluir `-Wall`** para ver warnings.

---

## Cómo usar GCC

**GCC (GNU Compiler Collection)** es el compilador más usado en Linux y disponible en otros sistemas.  
- Compila código en C, C++ y Fortran.  
- Convierte `.c` en ejecutable siguiendo varias etapas:

1. **Preprocesamiento:** `#include`, `#define`, macros, etc.  
2. **Compilación:** C → ensamblador (`.s`)  
3. **Ensamblado:** ensamblador → código objeto (`.o`)  
4. **Linkeo:** junta objetos y bibliotecas (`libc`) → ejecutable  

### Flags útiles

| Flag       | Función                                         |
|------------|-----------------------------------------------|
| `-c`       | Solo compila a `.o`, no linkea                |
| `-o nombre`| Define el nombre del ejecutable               |
| `-Wall`    | Muestra todos los warnings                     |
| `-g`       | Agrega información para depuración (GDB)     |

---

## Proceso de compilación y enlace

### Versión de dos pasos

1. Compilar a objeto:

```bash
gcc -c holamundo.c -o holamundo.o
```

- `-c` → solo compila, no enlaza  
- `-o holamundo.o` → nombre del archivo objeto

2. Linkear a ejecutable:

```bash
gcc holamundo.o -o holamundo
```

- `-o holamundo` → nombre del ejecutable final

### Versión de un paso

```bash
gcc holamundo.c -o holamundo
```

- GCC hace **todo junto**: preprocesa, compila, ensambla y linkea en un solo comando.

