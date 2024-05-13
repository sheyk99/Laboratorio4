//Arreglos y recursividad
 #include <stdio.h>
 #include <stdbool.h>

int busca_lineal (int array[], int tama, int valor){ //recibe como parametros el arreglo, su tamano y el entero buscado
    int i; //contador para iterar el array
    bool encontrado = false; //contador para determinar si se encuentra el numero buscado

    for (i = 0; i <= tama - 1; i++){
        encontrado = false; //no esta el numero buscado
        if (array[i] == valor){ //si alguna posicion del array es igual al valor buscado
            encontrado = true; //si esta el numero buscado
            break;
            
        }
        
    }

    if (encontrado == true) { 
        return i; //retorna la posicion en la que se encuentra el valor buscado
    } else {
        return -1;  
    }
}

int busca_binaria (int array[], int valor, int inicio, int fin){
    
    int m;
    bool encontrado = false;


    while (inicio <= fin){
        m = (inicio + fin) / 2; //establece la mitad del array

        if (array[m] == valor){ //cuando el valor corresponda el valor en medio del array
            encontrado = true; //se encontro el numero buscado en el array
            break;
        } else if (valor < array[m]){ //bisca si el valor es menor al medio de array
            m--; //resta el valor de m para encontrar la siguiente mitad
            fin = m;
        } else { //busca si el valor es mayor al medio del array
            m++;//aumenta el valor de m para encontrar la siguiente mitad
            inicio = m;
        }
    }

    if (encontrado == true) { 
        return m; //retorna la posicion en la que se encuentra el valor buscado
    } else {
        return -1;  
    }
    

}


int busca_recursivo (int array[], int valor, int inicio, int fin){
//base de la funcion
    int m = (inicio + fin) / 2;
    if (array[m] == valor){
        return m;
    }
    if (inicio > fin)
    return -1;

//casos recursivos
    if (valor < array[m]) {
        return busca_recursivo (array, valor, inicio, m - 1); //el valor final se asigna como el medio restado 
    } else {
        return busca_recursivo (array, valor, m + 1, fin); //si el valor es mayor a la mitad del array, el valor inicial se asigna como el medio aumentado
    }

    

}


int main() {
    int array[] = {2,4,6,23,56,79}; //arreglo ordenado dado
    int tama = (sizeof(array)/sizeof(array[0])); //tamano del array
    int valor;
    printf("Ingrese un valor entero:\n"); //permite al usuario ingresar un entero
    scanf("%d", &valor);

//busqueda lineal
    //asigna el valor de retorno de la funcion a una variable
    int lineal = busca_lineal(array, tama, valor); 
    if (lineal != -1){//-1 es el valor de retorno en caso de que no se encuentre el valor en el array 
        printf("La posicion de %d en el arreglo lineal es: %d\n", valor, lineal);
    } else {
        printf("El valor lineal no fue encontrado\n");
    }

//busqueda binaria
    int binario = busca_binaria(array, valor, 0, tama-1); 
    if (binario != -1){ 
        printf("La posicion de %d en el arreglo binario es: %d\n", valor, binario);
    } else {
        printf("El valor binario no fue encontrado\n");
    }

//busqueda recursiva
    int recursivo = busca_recursivo(array, valor, 0, tama-1); 
    if (recursivo != -1){
        printf("La posicion de %d en el arreglo recursivo es: %d\n", valor, binario);
    } else {
        printf("El valor recursivo no fue encontrado\n");
    }


    return 0;

}