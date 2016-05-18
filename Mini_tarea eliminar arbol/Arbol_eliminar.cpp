#include<iostream>
using namespace std;
class Nodo
{
    public:
    int data;
    Nodo *izq;
    Nodo *der;
};

class Arbol
{
    public:
    Nodo *root;

    Arbol(){root=NULL;}  //Nunca mas dejo una lista, pila, cola o arbol sin constructor... ¬¬

    void eliminar(Nodo *Buscado,Nodo *Padre,Nodo *aux)//al llamar al metodo eliminar, "Padre" siempre se ingresa como un "NULL","aux" siempre se ingresa como el "root" del arbol
    {
        if(aux==NULL){return;}
        if(aux->data==Buscado->data)
        {
            if(aux->izq==NULL && aux->der==NULL)
            {
                if(Padre==NULL){root=NULL;}
                else if(Padre->izq==aux){Padre->izq==NULL;}
                else if(Padre->der==aux){Padre->der==NULL;}
                delete (aux);
                return;
            }

            else if (aux->izq)
            {
                Nodo *hoja = aux->izq;
                Padre=aux;
                int data_temp;
                while(hoja->der)
                {
                    Padre=hoja;
                    hoja=hoja->der;
                }
                data_temp=hoja->data;
                hoja->data=aux->data;
                aux->data=data_temp;
                delete(hoja);
                return;
            }
            else if (aux->der)
            {
                Nodo *hoja = aux->der;
                Padre=aux;
                int data_temp;
                while(hoja->izq)
                {
                    Padre=hoja;
                    hoja=hoja->izq;
                }
                data_temp=hoja->data;
                hoja->data=aux->data;
                aux->data=data_temp;
                delete(hoja);
                return;
            }
            else if(aux->data>Buscado->data){eliminar(Buscado,aux,aux->izq);}
            else if(aux->data<Buscado->data){eliminar(Buscado,aux,aux->der);}
        }

    }
};

int main(){
return 0;
}
