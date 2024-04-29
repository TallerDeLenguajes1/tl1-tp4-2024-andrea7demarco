#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;
struct Nodo{
Tarea T; // T dato
struct Nodo *Siguiente; // puntero al siguiente
}typedef Nodo;

Nodo * CrearNodo(int id); // crea Tarea
Nodo * CrearListaVacia();
void InsertarNodo(Nodo ** ListaTareas_P , int *id);
void MostrarLista(Nodo ** Lista);
void MarcarTarea_a_Realizada(Nodo **ListaTareas_P, Nodo **ListaTareas_R);
Nodo *QuitarNodo(Nodo **ListaTareas_P,int id);
void BuscarTareaPorID(Nodo **ListaTareas_P, Nodo ** ListaTareas_R, int id);
void MostrarTarea(Nodo **Lista);
void BuscarTareaPorClave(Nodo **ListaTareas_P, Nodo **ListaTareas_R, char *clave);
int main ()
{  
   int id = 1000;
   int rta = 1;
   int op,busca;
   char *clave;
   char *buff =(char*)malloc(sizeof(char)*100);
   //creo las listas
   Nodo * ListaTareas_P = CrearListaVacia();
   Nodo * ListaTareas_R = CrearListaVacia();
   // inserto nodos a la lista 
   while(rta!=0)
   {
    printf("Elija la operacion:\n");
    printf("1)Agregar tarea\n");
    printf("2)Mostrar LISTAS\n");
    printf("3) Marcar tareas como REALIZADAS:\n");
    printf("4)Buscar tarea por ID:\n");
    printf("5)Buscar tarea por palabra clave:\n");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        InsertarNodo(&ListaTareas_P, &id);
        break;
    
    case 2:
    printf("Tareas PENDIENTES\n");
        MostrarLista( &ListaTareas_P );
    printf("Tareas REALIZADAS:\n");
        MostrarLista(&ListaTareas_R);
        break;
    case 3:
    printf("Tareas realizadas:\n");
    MarcarTarea_a_Realizada(&ListaTareas_P,&ListaTareas_R);
    break;

    case 4:
    printf("Buscar Tarea por ID:\n");
    fflush(stdin);
    scanf("%d",&busca);
    BuscarTareaPorID(&ListaTareas_P,&ListaTareas_R,busca);
    break;

    case 5:
    printf("Busca Tarea por clave:\n");
    fflush(stdin);
    gets(buff);
    strcpy(clave,buff);
    free(buff);
    BuscarTareaPorClave(&ListaTareas_P,&ListaTareas_R,clave);
    free(clave);
    break;

    default:
        break;
    }

    printf("Desea relizar otra operacion ? si:1 , no: 0\n");
    scanf("%d", &rta);
   }



    


   

  return 0;
}

Nodo * CrearNodo(int id) // crearTarea
{
   char *buff = (char *)malloc(sizeof(char)*100);
   Nodo *NuevoNodo = (Nodo*)malloc(sizeof(Nodo));

   NuevoNodo->T.TareaID = id;
   puts("Ingresar descripcion de la tarea:");
   fflush(stdin);
   gets(buff);  
   fflush(stdin);
   NuevoNodo->T.Descripcion = (char*)malloc(sizeof(char*)*strlen(buff)+1);
   strcpy(NuevoNodo->T.Descripcion,buff);
 
   NuevoNodo->T.Duracion = 10 + rand () % (100 - 10 + 1); 
   NuevoNodo->Siguiente = NULL;
   free(buff);
   return NuevoNodo;
}

Nodo * CrearListaVacia()
{
    return NULL;
}

void InsertarNodo(Nodo **ListaTareas_P, int *id) {
    int agregar;

    do {
        Nodo *nuevo = CrearNodo(*id);

        nuevo->Siguiente = *ListaTareas_P;
        *ListaTareas_P = nuevo;
        (*id)++;

        printf("Agregar otra tarea? (1 para sí, 0 para no):\n");
        scanf("%d", &agregar);

        if (agregar != 1 && agregar != 0) {
            printf("Opción no válida. Ingrese 1 para sí o 0 para no.\n");
        }
    } while (agregar != 0);
}


void MostrarLista(Nodo ** Lista)
{
    int i;
    Nodo *aux = *Lista;
    while(aux != NULL)
    { printf("/////////////////////////////\n");
      MostrarTarea(&aux);
      aux = aux->Siguiente;
      i++;
    }
}

Nodo *QuitarNodo(Nodo **ListaTareas_P,int id)
{
    Nodo *aux = *ListaTareas_P;
    Nodo *aux_anterior = *ListaTareas_P;
    while(aux != NULL && aux->T.TareaID != id)
    {
        aux_anterior = aux;
        aux = aux->Siguiente;
    }
    if(aux!=NULL)
    {
        aux_anterior->Siguiente = aux->Siguiente;
        aux->Siguiente = NULL;
    }

    return aux;
}

void MarcarTarea_a_Realizada(Nodo **ListaTareas_P, Nodo **ListaTareas_R)
{
   int id_tarea;
   printf("Ingrese Id de la tarea que quiere marcar como REALIZADA:\n");
   scanf("%d",&id_tarea);
   Nodo *NodoBorrado = QuitarNodo(ListaTareas_P,id_tarea);
   NodoBorrado ->Siguiente = *ListaTareas_R;
   *ListaTareas_R = NodoBorrado;
    
}

void BuscarTareaPorID(Nodo **ListaTareas_P, Nodo ** ListaTareas_R, int id)
{
    Nodo *auxP = *ListaTareas_P;
    Nodo *auxR = *ListaTareas_R;
    printf("BUSCADI :%d",id);
    while(auxP != NULL)
    {
        if(auxP->T.TareaID == id)
        {   printf("Pendientes:\n");
            MostrarTarea(&auxP);
        }

    auxP = auxP->Siguiente;
    } 

    while(auxR != NULL)
    {
        if(auxR->T.TareaID == id)
        {   printf("Realizadas:\n");
            MostrarTarea(&auxR);
        }

    auxR = auxR->Siguiente;
    } 


    }




void MostrarTarea(Nodo ** Lista)
{
    Nodo *aux = *Lista;
    printf("ID [%d]\n", aux -> T.TareaID);
    printf("Descripcion [%s]\n", aux->T.Descripcion);
    printf("Duracion [%d]\n", aux->T.Duracion);
}

void BuscarTareaPorClave(Nodo **ListaTareas_P, Nodo **ListaTareas_R, char *clave)
{
    Nodo *aux_P = *ListaTareas_P;
    Nodo *aux_R = *ListaTareas_R;

    while (aux_P!=NULL)
    {
        if(strstr(aux_P->T.Descripcion,clave) !=NULL ){
            MostrarTarea(&aux_P);
        }

        aux_P = aux_P ->Siguiente;
    }

        while (aux_R!=NULL)
    {
        if(strstr(aux_R->T.Descripcion,clave) !=NULL ){
            MostrarTarea(&aux_R);
        }

        aux_R = aux_R ->Siguiente;
    }
    

}
