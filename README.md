# TP2: Verificador eBPF

## Ezequiel Zbogar - 102216

### Taller de Programación I

​	Diagrama con las principales clases del trabajo práctico:

![Class Diagram](https://github.com/ezezbogar/TP2-Taller/blob/main/Images/Class-Diagram.png)

​	La clase "TP" funciona como hilo principal del programa y era redundante incluirla en el diagrama. Esta se encarga simplemente de inicializar los threads y quedarse a la espera de que terminen de ejecutarse.

​	La clase "eBPFVerifier" es la principal clase del TP, la cual se encarga de preguntar por nombres de archivos a "Repository", procesarlos, verificando si tienen ciclos o instrucciones que nunca son ejecutadas, y guardar los resultados en "Results".

​	El verificamiento de los archivos se lleva a cabo de la siguiente manera: Una vez que se tiene el nombre del archivo a procesar se crea una instancia de "Parser" el cual lee el archivo una primera vez y obtiene la cantidad de instrucciones (Nodos) y asocia cada label del programa a uno de estos. Luego se crea una instancia de "Graph" ya sabiendo la cantidad de instrucciones que tiene el programa y por lo tanto la cantidad de nodos que debe tener el grafo y acto seguido "Parser" escanea el archivo y lo modela como un grafo (El cual se carga en la clase "Graph") donde cada instrucción es un nodo, y los posibles saltos son las aristas.

​	Luego se llama al método "DFS" de "Graph", el cual verifica si es posible programa caiga en un loop infinito, lo cual es equivalente a que el grafo tenga un ciclo. Esto es mediante el algoritmo "Deep search First" para grafos dirigidos.

​	Como por naturaleza este algoritmo recorre todo el grafo, es posible ir marcando los nodos como visitados para después simplemente ver que nodos no fueron marcados como tales. Y en el caso de que alguno no haya sido visitado significa que el programa tiene instrucciones las cueles nunca van a ser ejecutadas no importa como se de el flujo del programa. De esto se encarga el método "checkUnusedInstructions" el cual se ejecuta seguido de "DFS".

​	Por último, mediante los métodos "programhasCicles" y "programhasUnusedInstructions" de la clase "Graph" se puede saber cual es la situación del programa y en base a eso saber que resultado guardar en "Results".

​	Diagrama de secuencia de eBPFVerifier:

![Sequence Diagram](https://github.com/ezezbogar/TP2-Taller/blob/main/Images/Sequence-Diagram.png)

​	Tanto las clases "Result" y "Repository" están implementadas a modo de monitor, esto es, cuentan con un mutex para que solo pueda acceder a las critical sections un thread a la vez y de esta forma evitar race conditions

- Link al repositorio de GitHub: https://github.com/ezezbogar/TP2-Taller

#### Reentrega

​	A continuación se listan los cambios realizados para la reentrega:

##### Issue 1:

​	Se eliminó en todas las clases los constructores por copia y el operador = y a las clases las cuales eran pasadas por copia en algun momento del programa se les declaro un constructor por movimiento.

​	También se cambió el pasaje por copia de distintos objetos como strings a pasaje por referencia.

​	Además, se implementó el uso de "unique_lock" para los mutex que tiene la ventaja de ser RAII.

 