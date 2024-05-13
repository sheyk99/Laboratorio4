//Arreglos y recursividad
 #include <stdio.h>

 //funcion para encontrar el valor minimo
int encontrarMin(int array[], int tama){
    int min = array[0]; //empieza el minimo en el primer valor del array
    int i; //contador para iterar en el array

    for (i =1; i <tama; i++){
        if (array[i] < min) { //cada vez que encuentra un valor menor que el minimo preestablecido
            min = array[i]; //guarda el nuevo minimo
        }
    }
    return min;
}

//funcion que retorna el valor maximo
int encontrarMax(int array[], int tama){
    int max = array[0]; //empieza el maximo en el primer valor del array
    int i; //contador para iterar en el array

    for (i =1; i <tama; i++){
        if (array[i] > max) { //cada vez que encuentra un valor mayor que el minimo preestablecido
            max = array[i]; //guarda el nuevo maximo
        }
    }
    return max;

}

//funcion que encuentra minimo y maximo con punteros

void encontrarMinMax(int *array, int * minimo, int * maximo, int tama){
//repite la logica de las funciones anteriores pero asignando punteros
    int i;
    *minimo = array[0];
    *maximo = array[0];
 
//apunt a las variables maximo y minimo para asignar los valores
    for (i = 1; i <tama; i++){
        if (array[i] < *minimo) { 
            *minimo = array[i]; 
        } 
        if (array[i] > *maximo){
            *maximo = array[i]; 
        }
    }
}


//Main
 int main() {
    int array[] = {21, 24, 65, 3, 56, 12, 35, 15}; //array dado
    int tama = (sizeof(array)/sizeof(array[0])); //longitud del array

    //valor minimo del array
    printf("El valor minimo en el arreglo es: %d\n", encontrarMin(array, tama));
   
    //valor maximo del array
    printf("El valor maximo en el arreglo es: %d\n", encontrarMax(array, tama));
    
    //valores minimo y maximo con punteros
    int minimo, maximo;
    //asignar las variables a los punteros
    encontrarMinMax(array, &minimo, &maximo, tama);
    printf("El valor minimo con puntero es: %d\n", minimo);
    printf("El valor maximo con puntero es: %d\n", maximo);
   

 }