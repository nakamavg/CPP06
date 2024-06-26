# CPP06
C++ - Módulo 06 C++ casts

## ex 00

### Objetivo del ejercicio
El objetivo del ejercicio es crear una clase ScalarConverter que pueda convertir un literal de tipo cadena (string) en varios tipos escalares en C++: char, int, float y double. Además, debe manejar pseudo literales específicos como -inf, +inf y nan.

### Conceptos Clave
#### Tipos Escalares:
- char: Tipo de dato que almacena un solo carácter. Su rango es de -128 a 127 en la mayoría de las implementaciones.
- int: Tipo de dato entero. Su rango es amplio y depende de la implementación (típicamente -2147483648 a 2147483647 para un entero de 32 bits).
- float: Tipo de dato de punto flotante de precisión simple. Puede almacenar números decimales y valores especiales como -inff, +inff y nanf.
- double: Tipo de dato de punto flotante de precisión doble. Similar a float, pero con más precisión.

#### Conversión de Tipos:
Se requiere convertir una cadena a un valor numérico y luego a otros tipos escalares.
- std::stod: Convierte una cadena a un double. Puede lanzar excepciones std::invalid_argument o std::out_of_range.

#### Manejo de Errores:
- Si una conversión no es válida, debe mostrarse un mensaje indicando que la conversión es imposible.
- Si un valor no es imprimible como char, se debe mostrar "Non displayable".

### Pasos de Conversión
1. Entrada: Una cadena que representa un literal de C++.
2. Detección del Tipo: Convertir la cadena a un double para simplificar la conversión a otros tipos.
- Convertir la entrada de la cadena a un double es una estrategia útil en este caso por varias razones:

	- Rango Amplio de Representación: El tipo double en C++ tiene un rango muy amplio y puede representar tanto números enteros como números de punto flotante. Esto permite manejar una amplia variedad de literales numéricos sin perder precisión significativa para el propósito de este ejercicio.

	- Conversión a Otros Tipos: Una vez que tenemos el valor como un double, es relativamente sencillo convertirlo a otros tipos escalares (char, int, float) mediante castings. C++ permite conversiones explícitas (casting) entre tipos numéricos de una manera bastante directa.

	- Detección de Valores Especiales: El tipo double tiene soporte nativo para valores especiales como nan (Not-a-Number), inf (infinito positivo) y -inf (infinito negativo). Esto es útil para detectar y manejar estos casos de manera uniforme.

	- Funciones de Biblioteca: C++ proporciona funciones de biblioteca estándar, como std::stod, que facilitan la conversión de una cadena a un double y manejan excepciones para valores fuera de rango o formatos inválidos.


3. Conversión y Salida: Convertir el double a char, int, float y double.
4. Manejar casos especiales y valores fuera de rango.

### Ejemplo de Funcionamiento
Supongamos que queremos convertir la cadena "42.0f":
- char: La representación 42 no es un carácter imprimible, así que debe mostrar "Non displayable".
- int: 42.0f se convierte a 42.
- float: 42.0f ya es un float.
- double: 42.0f se convierte a 42.0.

## ex 01

### ¿Qué es la Serialización?
La serialización es el proceso de convertir un objeto en una secuencia de bytes para almacenarlo o transmitirlo a través de una red. Esta secuencia de bytes puede luego ser deserializada, para volver al objeto original

### ¿Por qué es útil la Serialización?
- Persistencia: Permite almacenar el estado de un objeto en un archivo o una base de datos para que pueda ser restaurado más tarde.
- Comunicación en Red: Facilita el envío de objetos entre diferentes sistemas, ya que convierte los objetos en una secuencia de bytes que pueden ser transmitidos fácilmente.
- Clonación: Crear copias exactas de objetos complejos.
- Interoperabilidad: Permite que sistemas escritos en diferentes lenguajes de programación puedan comunicarse y compartir datos.

## ex 02
1. Polimorfismo y Herencia
	- Uso de Clases Base y Derivadas: Se practica la creación de una clase base (Base) y clases derivadas (A, B, C). Esto establece una jerarquía de herencia donde A, B y C heredan de Base, permitiendo el uso de polimorfismo.

2. Destructor Virtual
	-  El uso de un destructor virtual en la clase base (Base) asegura que los objetos derivados sean correctamente destruidos cuando se eliminan a través de un puntero de la clase base. Esto es crucial para evitar comportamientos indefinidos y pérdidas de memoria en aplicaciones más complejas.

3. Indentificación Dinámica de Tipos
	- Uso de dynamic_cast: En la función identify, se utiliza dynamic_cast para determinar dinámicamente el tipo real del objeto apuntado por un puntero Base*. Esto es esencial para realizar operaciones específicas basadas en el tipo concreto de cada objeto.

4. Manipulación de Punteros y Referencias:

	- Se practicó el uso de punteros (Base*) para apuntar dinámicamente a objetos de las clases derivadas (A, B, C). También se utilizó una referencia (Base&) en la función identify, demostrando que las referencias pueden ser usadas con objetos polimórficos sin necesidad de punteros.

	```c++
	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();

	identify(obj1); // Imprime el tipo real de obj1
	identify(*obj2); // Imprime el tipo real de obj2 usando referencia

	```
	