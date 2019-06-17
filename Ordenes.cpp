#include<iostream>
#include<fstream>
#include<locale.h>
using namespace std;

class Orden
{
    public:
    int numero;
    Orden *next;
};

class Tecnico
{public:
    string nombre;
    Orden *primera;
    Tecnico *siguiente;

    Tecnico(string nombre)
    {
        this->nombre=nombre;
        siguiente=NULL;
        primera=NULL;
    }

    void agregar_orden(int num)
    {
        Orden *aux=new Orden();
        Orden *aux2=primera;
        if(primera=NULL)
        {
            aux->numero=num;
            primera=aux;
            return;
        }

        while(aux2)
        {
            if(aux2->next==NULL)
            {
                aux->numero=num;
                aux2->next=aux;
                return;
            }
            aux2=aux2->next;
        }
    }

    void imprimir_ordenes()
    {
        Orden *aux=primera;
        cout<<nombre<<" tiene las siguientes ordenes:"<<endl;
        int i=1;
        while(aux)
        {
            cout<<i<<") "<<aux->numero<<endl;
            i++;
            aux=aux->next;
        }
    }
};

class Ordenes
{
    public:
   ifstream ordenes, artefactos;
   Tecnico *primero;

   void cargar()
   {
       setlocale(LC_CTYPE,"Spanish");
       ordenes.open("ordenes.txt",ios::out|ios::in);
       if (ordenes.is_open()){cout<<"El archivo ordenes.txt se cargo con exito"<<endl;}
       else{cout<<"ERROR, El archivo ordenes.txt no se pudo cargar"<<endl;}
       artefactos.open("artefactos.txt",ios::out|ios::in);
       if (artefactos.is_open()){cout<<"El archivo artefactos.txt se cargo con exito"<<endl;}
       else{cout<<"ERROR, El archivo artefactos.txt no se pudo cargar"<<endl;}
   }

      void cargar_tecnicos()
   {
      setlocale(LC_CTYPE,"Spanish");
      cargar();
      Tecnico *Lucio=new Tecnico("Lucio Perez");
      Tecnico *Abel=new Tecnico("Abel Gonzalez");
      Tecnico *Pablo=new Tecnico("Pablo Abarca");
      Tecnico *Jose=new Tecnico("Jose Lopez");
      Tecnico *Luis=new Tecnico("Luis Sanchez");
      Lucio->siguiente=Abel;
      Abel->siguiente=Pablo;
      Pablo->siguiente=Jose;
      Jose->siguiente=Luis;
      primero=Lucio;
    }

   void cargar_tec()
   {
       char IoR[1], Nombre_cliente[30], Direccion [60],N_orden[8], N_tel[9],Nombre_del_tecnico[13],N_orden_artef[8],Nombre_artefacto[40];
        int numero_o;
        Tecnico *aux=primero;
      string linea,artef;
      while(getline(ordenes,linea)){
        ifstream artefactos;
        artefactos.open("artefactos.txt",ios::out|ios::in);


            cout<<endl<<"_____________________________________________________________________________________"<<endl;

            cout<<"Orden de Trabajo en Terreno                              #";
            for(int i=0;i<8;i++)
            {
                N_orden[i]=linea[i];
                cout<<N_orden[i];
            }
            IoR[0]=linea[8];
            cout<<endl<<"Instalacion: ";
            if(IoR[0]=='I'){cout<<"SI"<<endl;}
            else{cout<<"NO"<<endl;}
            cout<<"Reparacion: ";
            if(IoR[0]=='R'){cout<<"SI"<<endl;}
            else{cout<<"NO"<<endl;}
            cout<<"Nombre Cliente: ";
            for(int i=0;i<30;i++)
            {
                Nombre_cliente[i]=linea[i+9];
                cout<<Nombre_cliente[i];
            }
            cout<<endl<<"Direccion: ";
            for(int i=0;i<60;i++)
            {
                Direccion[i]=linea[i+39];
                cout<<Direccion[i];
            }
            cout<<endl<<"Telefono: ";
            for(int i=0;i<9;i++)
            {
                N_tel[i]=linea[i+99];
                cout<<N_tel[i];
            }
            cout<<endl<<endl<<"ARTEFACTOS: "<<endl;
            while(getline(artefactos,artef))
            {
                int t=0;
                for(int i=0;i<8;i++)
                {
                    N_orden_artef[i]=artef[i];
                    if(N_orden_artef[i]==N_orden[i]){t++;}
                }
                if(t>7)
                {
                    for(int i=0;i<40;i++)
                    {
                        if(artef[i+9]=='\0'){break;}
                        Nombre_artefacto[i]=artef[i+9];
                        cout<<Nombre_artefacto[i];
                    }
                    cout<<endl;
                }


            }
            cout<<endl<<"Tecnico: ";
            for(int i=0;i<13;i++)
            {
                if(linea[i+108]=='\0'&&linea[i+109]>96){break;}
                Nombre_del_tecnico[i]=linea[i+108];
                cout<<Nombre_del_tecnico[i];
            }
            delete(artefactos);

         }

            cout<<endl<<"_____________________________________________________________________________________"<<endl;
      }





};

int main()
{
    Ordenes *ordenes=new Ordenes();
    ordenes->cargar_tecnicos();
    ordenes->cargar_tec();

    return 0;
}
