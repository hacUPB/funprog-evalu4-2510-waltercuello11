sustentación unidad 4
1:
 1 .El desafío era crear una aplicación de consola en C que pudiera manejar archivos de texto plano. Las funciones que se necesitaban eran:
2.El contenido de un archivo.txt se puede leer de manera dinámica.
3.Determinar datos estadísticos del texto (cantidad de caracteres, palabras, espacios y líneas).
4.Especificar la frecuencia de cada vocal (sin emplear tolower()).
5.La sustitución de todas las apariciones de una palabra por otra.
6.Guardar los resultados en un archivo de texto reciente.

 Es un programa modular, dividido en funciones que abordaran cada requerimiento. Elegí el lenguaje C puro sin estructuras para respetar las restricciones del reto y optimizar el control sobre memoria dinámica.

2:Estrategia de solución
Dividimos el código en funciones principales, cada una encargada de una tarea específica:
leerArchivo(): carga dinámicamente el contenido del archivo en memoria.
calcularEstadisticas(): calcula caracteres, palabras, espacios y líneas.
contarVocales(): cuenta la frecuencia de las vocales sin importar su mayúscula o minúscula.
reemplazarPalabra(): crea una nueva versión del texto reemplazando una palabra dada por otra.
guardarResultados(): guarda estadísticas, frecuencia de vocales y el texto final en un archivo nuevo.
main(): gestiona el menú interactivo, solicita entradas al usuario y orquesta la ejecución de las funciones anteriores.
El uso de memoria dinámica permite adaptar el tamaño del contenido leído y modificado, garantizando eficiencia y flexibilidad.

3:
Tabla de variables
leerArchivo
Función         	                                                                   Variable	Tipo	Rol
leerArchivo	nombre	const char*	Entrada
leerArchivo	buffer	char*	Salida
calcularEstadisticas
Función	Variable	Tipo	Rol
calcularEstadisticas	 texto	const char*	Entrada
calcularEstadisticas	 caracteres	int*	Salida
calcularEstadisticas	 palabras	int*	Salida
calcularEstadisticas	 espacios	int*	Salida
calcularEstadisticas	 lineas	int*	Salida

contarVocales
Función	     Variable	Tipo	Rol
contarVocales	   texto	const char*	Entrada
contarVocales	a, e, i, o, u	int*	Salida
	







		
reemplazarPalabra
Función	                 Variable	Tipo	Rol
reemplazarPalabra	                  texto	const char*	Entrada
reemplazarPalabra	               palabra	const char*	Entrada
reemplazarPalabra	         reemplazo	const char*	Entrada
reemplazarPalabra	       nuevoTexto	char*	Salida


	
guardarResultados
Función	                 Variable	Tipo	Rol
guardarResultados	             nombreArchivo	const char*	Entrada
guardarResultados	                 caracteres	int	Entrada
guardarResultados	                   palabras	int	Entrada
guardarResultados	                 espacios	int	Entrada
guardarResultados	                   lineas	int	Entrada
guardarResultados	              a, e, i, o, u	int	Entrada
guardarResultados	                  texto	const char*	Entrada





			
4:
INICIO

    DEFINIR variables:
        opcion, nombreArchivo, salida
        contenido ← NULL
        caracteres, palabras, espacios, lineas ← 0
        a, e, i, o, u ← 0

    REPETIR
        MOSTRAR menú:
            1. Ingresar nombre del archivo
            2. Calcular estadísticas
            3. Calcular frecuencia de vocales
            4. Reemplazar palabra
            5. Guardar resultados
            6. Salir

        LEER opcion

        SEGÚN opcion HACER

            CASO 1:
                PEDIR nombreArchivo
                SI contenido ≠ NULL ENTONCES
                    LIBERAR contenido
                FIN SI
                contenido ← leerArchivo(nombreArchivo)
                SI contenido ≠ NULL ENTONCES
                    MOSTRAR "Archivo cargado correctamente"
                FIN SI

            CASO 2:
                SI contenido = NULL ENTONCES
                    MOSTRAR "Primero debe cargar un archivo"
                SINO
                    calcularEstadisticas(contenido, caracteres, palabras, espacios, lineas)
                    MOSTRAR resultados
                FIN SI

            CASO 3:
                SI contenido = NULL ENTONCES
                    MOSTRAR "Primero debe cargar un archivo"
                SINO
                    contarVocales(contenido, a, e, i, o, u)
                    MOSTRAR resultados
                FIN SI

            CASO 4:
                SI contenido = NULL ENTONCES
                    MOSTRAR "Primero debe cargar un archivo"
                SINO
                    PEDIR palabra a buscar
                    PEDIR palabra de reemplazo
                    nuevoContenido ← reemplazarPalabra(contenido, palabra, reemplazo)
                    SI nuevoContenido ≠ NULL ENTONCES
                        LIBERAR contenido
                        contenido ← nuevoContenido
                        MOSTRAR "Reemplazo realizado correctamente"
                    FIN SI
                FIN SI

            CASO 5:
                SI contenido = NULL ENTONCES
                    MOSTRAR "Primero debe cargar un archivo"
                SINO
                    PEDIR nombre del archivo de salida
                    guardarResultados(salida, caracteres, palabras, espacios, lineas, a, e, i, o, u, contenido)
                FIN SI

            CASO 6:
                MOSTRAR "Programa finalizado"

            OTRO CASO:
                MOSTRAR "Opción no válida"

        FIN 

    HASTA opcion = 6

    SI contenido ≠ NULL ENTONCES
        LIBERAR contenido
    FIN SI

FIN
5:
 Se usó un lenguaje técnico y conciso, adecuado para una sustentación académica de ingeniería. Se evitaron explicaciones redundantes, priorizando la claridad y el enfoque en el análisis y diseño del programa.

