# PC1: Práctica Calificada
**course:** Programación Orientada a Objetos II  
**unit:** 1 y 2  
**cmake project:** poo2_pc1_teo1_v2021_2
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo fuente (`.cpp`) y un archivo cabecera (`.h`) con el número de la pregunta:
    - `p1.cpp, p1.h`
    - `p2.cpp, p2.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.

## Question #1 - clases, punteros y sobrecarga de operadores (10 points)

Desarrollar la clase `symmetric_difference_t` que permita generar un arreglo dinámico ordenado de enteros a partir de la diferencia simétrica de 2 vectores (considerar solo los elementos que estén solamente en uno de los vectores). La clase contará con un constructor que cuente con el siguiente parámetro:
- 2 parámetros que permitan ingresar 2 lista de enteros (utilizar el tipo `std::initializer_list`).
- 2 parámetros que permitan ingresar 2 lista de enteros (utilizar el tipo `std::vector`).

La clase deberá utilizar **arreglos dinámicos (punteros)**, para el almacenamiento de los enteros. 

El método que debe ser implementado es el método:

- `size_t size()`, retorna el tamaño del arreglo dinámico .
Y las sobrecargas a los operadores:
- Paréntesis `()`, que retorne un puntero al arreglo de los valores ordenados en forma ascendente.
- Negación `!`, que invierta los valores del arreglo de ascendente a descendente o viceversa y que retorne el puntero al arreglo

**Use Case #1:**
```cpp
// genera un arreglo dinámico
symmetric_difference_t sd1 ({1, 5, 3, 8, 2}, {4, 9, 7, 6, 10, 1});
// imprimiendo los datos
std::copy(sd1(), sd1() + sd1.size(), std::ostream_iterator<int>(std::cout," ");
std::cout << std::endl;
// 2 3 4 5 6 7 8 9 10
!sd1;
std::copy(sd1(), sd1()+sd1.size(), 
std::ostream_iterator<int>(std::cout," ");
std::cout << std::endl;
// 10 9 8 7 6 5 4 3 2
```

**Use Case #2:**
```cpp
// genera un arreglo dinámico
std::vector v1 = {1, 10, 3, 6, 2, 1};
std::vector v2 = {4, 9, 7, 6, 10, 1};
symmetric_difference_t sd1 (v1, v2);
// imprimiendo los datos
std::copy(sd1(), sd1() + sd1.size(), std::ostream_iterator<int>(std::cout," ")
std::cout << std::endl;
  // 2 3 4 7 9
!sd1;
std::copy(sd1(), sd1() + sd1.size(), 
std::ostream_iterator<int>(std::cout," ")
std::cout << std::endl;
// 9 7 4 3 2

```

## Question #2 - template de funciones y librería estándar (10 points)

Escribir la función de template `get_maximum_product_range` que reciba como parámetro un contenedor genérico y que genere un contenedor con los elementos que produzcan el máximo producto que se puede obtener de multiplicar elementos del contenedor.  

La función debe retornar un contenedor, que por default será `std::vector`, pero que podría ser personalizado.

**Use Case #1:**
```cpp
std::list<int> lst1 = {3, 3, -3, 5, 4, -4, 0, -4, -4, -5};
std::deque f1 = get_maximum_product_range<std::deque>(lst1);
for (const auto& row: f1) {
	for(const auto& value: row)
		std::cout << value << " ";
	std::cout << std::endl;
}

/*
 Se imprimirá:
    3 3 5 4 -4 -4 -4 -5
*/
```

**Use Case #2:**
```cpp
std::forward_list<int> flst1 = {1, 2, -3, 0, 0, -3, -2, 5, -1, -5};
std::vector f1 = get_maximum_product_range(flst1); 
for (auto row: f1) {
	for(auto value: row)
		std::cout << value << " ";
	std::cout << std::endl;
}
/*
 Se imprimirá:
    1 2 -3 -3 -2 5 -5
*/
```
