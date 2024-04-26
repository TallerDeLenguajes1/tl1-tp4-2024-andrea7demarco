#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;
struct Nodo{
Tarea T; // T dato
Nodo *Siguiente; // puntero al siguiente
}typedef Nodo;

Nodo * CrearNodo(int id); // crea Tarea
Nodo * CrearListaVacia();
void InsertarNodo(Nodo ** ListaTareas_P , int *id);


int main ()
{  
   int id = 1000;
   //creo las listas
   Nodo * ListaTareas_P = CrearListaVacia();
   Nodo * ListaTareas_R = CrearListaVacia();
   // inserto nodos a la lista 
   printf("Elija la operacion:")


    


   

  return 0;
}

Nodo * CrearNodo(int id) // crearTarea
{
   char *buff;
   Nodo *NuevoNodo = (Nodo*)malloc(sizeof(Nodo));

   NuevoNodo->T.TareaID = id;
   puts("Ingresar descripcion de la tarea{%d}:",T.TareaID);
   fflush(stdin);
   gets(buff);  
   T.Descripcion = (char*)malloc(sizeof(char*)*strlen(buff)+1);
   strcpy(T.Descripcion,buff);
   free(buff);
   NuevoNodo->T.Duracion = 10 + rand () % (100 - 10 + 1); 
   NuevoNodo->T.Descripcion;
   NuevoNodo->Siguiente = NULL;
   return NuevoNodo;
}

Nodo * CrearListaVacia()
{
    return NULL;
}

void InsertarNodo(Nodo ** ListaTareas_P , int *id)
{   int agregar = 0;

   do {
    Nodo * nuevo = CrearNodo(*id);
    if (*ListaTareas_P == NULL ){
       *ListaTareas_P= nuevo;
    } 
    else
    {
        nuevo->Siguiente = *ListaTareas_P;
        *ListaTareas_P = nuevo;
        (*id)++;

    }

    printf("Agrega otra tarea si : 0 , no : 1");
    scanf("%d",&agregar);
    }while(agregar !=1)
    


}
