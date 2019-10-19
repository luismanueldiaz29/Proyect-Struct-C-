#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

using namespace std;

//ESTRUCTURA
int t=1,i=0,opn,opn2, suma=0, cen[100], a=10000;;
float porc;

struct persona{
        char nombre[20];
        char apellido[20];
        char cc[10];
        int  factura[5];
        char servicio[30];   
		char costo[20]; 
    }p[100];   
    
// INGRESAR PERSONAS
void ingresar(){
    char op; 
    int ops;             
 do{
        system("CLS");
	    //factura
		/*srand(time(NULL));
        for(int b=0; b<=4; b++){
        	
           p[i].factura[b]= 1 + rand() % (5 - 1);
           //para guardarlo en otra variable como entero
           cen[i]=cen[i]+(p[i].factura[b]*a);
           a=a/10;
        }
            cout<<"**INGRESAR LOS DATOS**\n\n";
            cout<<"REGUISTRO #"<<i<<endl;
            cout<<"\nCODIGO DE FACTURA"<<endl;
            fflush(stdin);
            cout<<"-----"<<endl;
                for(int b=0; b<=4; b++){
                    cout<<p[i].factura[b];
                }cout<<endl;
            cout<<"-----"<<endl;
            //------*/
            cout<<"\t\t**INGRESAR LOS DATOS**";
            fflush(stdin);
			cout<<endl;
            cout<<"\n\nNOMBRE: ";cin>>p[i].nombre;
            cout<<"\nAPELLIDO: ";cin>>p[i].apellido;
            cout<<"\nCEDULA: ";cin>>p[i].cc;
            fflush(stdin);  
			cout<<"\nSERVICIO OFRECIDO: ";
            cin.getline(p[i].servicio,40,'\n');
            cout<<"\nCOSTO: ";
            cin.getline(p[i].costo,20,'\n');
            
			//suma de el costo
            suma=suma+atol(p[i].costo);
            
            for(int n=0;n<i;n++){
             if(atol(p[i].cc)==atol(p[n].cc)){                         
               cout<<"CEDULA YA EXISTE\n";
               cout<<"PREISONES UNA TECLA Y ESCRIBA DE NUEVO\n";
               system("PAUSE");
               i--;
              break;
                }
            }
            
        i++;
		       
        cout<<"\nPARA CONTINUAR PULSE (S) O (N)"<<endl;
        cin>>op;
    }while(op=='s'||op=='S');
}

//MENU CONSULTAR

void menu_consultar(){
	cout<<"\t\t**CONSULTAR DATOS** ";
    cout<<"\n\n\t1.) CONSULTA GENERAL";
    cout<<"\n\t2.) CONSULTA POR CEDULA";
    //cout<<"\n\t3.) CONSULTAR POR FACTURA";
    cout<<"\n\t3.) SALIR ";
}
                   
//CONSULTAR PERSONAS
void consultar(){
    int a;
    char op;  
    do{
        
        system("CLS");
	   //MENU DE CONSULTAR
       menu_consultar();
        cout<<"\n\n ESCOJA UNA OPCION: ";
          cin>>a;
         //SELECCIONAR CADA CASO DEL MENU CONSULTA
            switch(a){
         //CONSULTA GENERAL
            case 1: 
		do{
                for(int n=0;n<i;n++){     
                    system("CLS");
                    cout<<"\n\tREGISTRO Nº: "<<n<<endl;
                    /*cout<<"CODIGO DE FACTURA:"<<endl;
					cout<<"------"<<endl; 
				    cout<<cen[i]<<endl;
					cout<<"-------"<<endl<<endl;*/
                    cout<<"\n\tNOMBRE  : "<<p[n].nombre;
                    cout<<"\n\tAPELLIDO: "<<p[n].apellido;
                    cout<<"\n\tCEDULA  : "<<p[n].cc;
                    cout<<"\n\tSERVICIO: "<<p[n].servicio;
                    cout<<"\n\tCOSTO: "<<p[n].costo;
                    porc=(atol(p[n].costo)*100)/suma;
                    cout<<"\n\n\tREPRECENTA UN "<<porc<<"% LAS GANACIAS";
                    cout<<"\n\nPRECIONE UNA TECLA PARA CONTINUAR..."<<endl;
                    system("PAUSE");
                    cout<<endl;
                    cout<<"         -----------------------------";
				   //PARA PASAR REGISTRO POR REGISTRO
                    if(n<i-1){
                        cout<<"\n\tPRECIONE UNA TECLA PARA CONTINUAR..."<<endl;
                        system("PAUSE");
                    }
                }
                  //SEGUIR EN CONSULTA GENERAL        
                   cout<<"\nSEGUIR EN UNA CONSULTA GENERAL: "<<endl;
                   cin>>op;
            }while(op=='s'||op=='S');
                break;
                   //CONSULTA POR CEDULA
                    case 2: long ced,k;
                         do{
                            system("CLS");
                            cout<<"\n\tINGRECE LA CEDULA: ";
                            cin>>ced;
                                for(int n=0;n<i;n++){
                                    k=atol(p[n].cc);
                                    if(k==ced){
                                    	cout<<"\n\tREGISTRO Nº: "<<n<<endl;
                                    	cout<<"CODIGO DE FACTURA:"<<endl;
										cout<<"------"; 
										cout<<cen[i]<<endl;
										cout<<"-------"<<endl<<endl;
                                        cout<<"\n\tNOMBRE  : "<<p[n].nombre;
                                        cout<<"\n\tAPELLIDO: "<<p[n].apellido;
                                        cout<<"\n\tCEDULA  : "<<p[n].cc;
                                        cout<<"\n\tSERVICIO: "<<p[n].servicio;
                                        cout<<"\n\tCOSTO: "<<p[n].costo;
                                        porc=(atol(p[n].costo)*100)/suma;
                                        cout<<"\n\n\tREPRECENTA UN "<<porc<<"% LAS GANACIAS";
                                        cout<<"\n\nPRECIONE UNA TECLA PARA CONTINUAR..."<<endl;
                                        system("PAUSE");
                                        break;
                                   }
						         //SI LA CEDULA NO EXISTE
                                }
                                    cout<<"\n\tSEGUIR EN CONSULTA INDIVIDUAL (S) O (N): "<<endl;
                                    cin>>op; 
                                    }while(op=='s'||op=='S');
                                    break;
                               /*            
                                case 3:
                                    char codigo[5];
                                    system("cls");
                                    cout<<"ingrece el codigo ";
                                    cin>>codigo;
                                   for(int n=0; n<5; n++){
                                        if (cen[n]==atol(codigo)){
                                    	cout<<"\n\tREGISTRO Nº: "<<n;
                                    	cout<<"CODIGO DE FACTURA:"<<endl;
										cout<<"------"; 
										cout<<cen[i]<<endl;
										cout<<"-------"<<endl<<endl;
                                        cout<<"\n\tNOMBRE  : "<<p[n].nombre;
                                        cout<<"\n\tAPELLIDO: "<<p[n].apellido;
                                        cout<<"\n\tCEDULA  : "<<p[n].cc;
                                        cout<<"\n\tSERVICIO: "<<p[n].servicio;
                                        cout<<"\n\tCOSTO: "<<p[n].costo;
                                        porc=(atol(p[n].costo)*100)/suma;
                                        cout<<"\n\n\tREPRECENTA UN "<<porc<<"% LAS GANACIAS";
                                        cout<<"\n\nPRECIONE UNA TECLA PARA CONTINUAR..."<<endl;
                                        system("PAUSE");
                                          system("PAUSE");
										}
									}
                                           	break;
                                   //SALIR DEL SUBMENU CONSULTA
                                    case 4: 
									  break;*/
                                    } //SERRAR SWITCH
                    system("cls");      
                    cout<<"\n\tSEGUIR EN SUDMENU (S) O (N): "<<endl;
                    cin>>op;
                   }while(op=='s'||op=='S');
                }

//MODIFICAR PERSONAS
void modificar(){
    char op;
 do{            
     int a,c;
     long ced,k;
     //MENU MODIFICAR
     system("CLS");
     cout<<"\t\n\n¨QUE QUIERE MODIFICAR?: ";
     cout<<"\n\t1.) CEDULA";
     cout<<"\n\t2.) NOMBRE";
     cout<<"\n\t3.) APELLIDO ";
     cout<<"\n\t4.) SERVICIO";
     cout<<"\n\t5.) COSTO";
     cout<<"\n\t6.) Salir";
     cout<<"\n\t DIJITE UNA OPCION ";
     cin>>a;
     //SELECCIONAR CADA CASO DEL MENU MODIFICAR
        switch(a){
            //MODIFICAR LA CEDULA
            case 1: 
			 do{
			    system("CLS");
                cout<<"\n\t\aINGRECE LA CEDULA DEL CLIENTE QUE QUIERE MODIFICAR";
                cin>>ced;
                for(int n=0;n<i;n++){
                k=atol(p[n].cc);
                    if(ced==k){
                        cout<<"\n\t\DATOS A MODIFICAR:";
                        cout<<"\n\t\NOMBRE : "<<p[n].nombre;
                        cout<<"\n\t\APELLIDOS : "<<p[n].apellido;
                        cout<<"\n\t\CEDULA  : "<<p[n].cc;
                        cout<<"\n\t\SERVICIOS : "<<p[n].servicio;
                        cout<<"\n\t\COSTO : "<<p[n].costo;
                        cout<<"\n\t\INGRECE LAS NUEVA CEDULA ";
                        cin>>p[n].cc;
                    break;
                   }        
                }
                //SI LA CEDULA NO EXISTE
                   if(k!=ced){
                        cout<<"\n\t\ESTE REGISTRO NO EXISTE";
                        cout<<"\n\t\ESCRIBE BIEN LA CEDULA"<<endl;
                        system("PAUSE");
                        break;
                      }
                                      
                        cout<<"\nMODIFICAR OTRA CEDULA (S) O (N) "<<endl;
                        cin>>op; 
            }while(op=='s'||op=='S');
                break;
              //MODIFICAR EL NOMBRE
                    case 2:
					do{
                        system("CLS");
                        cout<<"\n\t\aINGRECE LA CEDULA DEL REGUISTRO QUE DESEA ELIMINAR: ";
                        cin>>ced;
                            for(int n=0;n<i;n++){
                                k=atol(p[n].cc);
                                if(ced==k){
                        cout<<"\n\t\DATOS A MODIFICAR:";
                        cout<<"\n\t\NOMBRE : "<<p[n].nombre;
                        cout<<"\n\t\APELLIDOS : "<<p[n].apellido;
                        cout<<"\n\t\CEDULA  : "<<p[n].cc;
                        cout<<"\n\t\SERVICIOS : "<<p[n].servicio;
                        cout<<"\n\t\COSTO : "<<p[n].costo;
                        cout<<"\n\t\INGRECE LAS EL NUEVO NOMBRE ";
                                    cin>>p[n].nombre;
                               break;
                                }        
                            }
                           //SI LA CEDULA NO EXISTE
                                if(k!=ced){
                                    cout<<"\n\t\NO EXISTE";
                                    cout<<"\n\t\ASEGURATE DE ESCRIBIR BIEN"<<endl;
                                    system("PAUSE");
                                        break;
                                        }
                                    cout<<"\nSEGUIR MODIFICANDO (S) O (N): "<<endl;
                                     cin>>op; 
                    }while(op=='s'||op=='S');
                        break;
                        case 3:       	
					do{
                        system("CLS");
                        cout<<"\n\t\aINGRECE LA CEDULA QUE QUIERE MODIFICAR: ";
                        cin>>ced;
                            for(int n=0;n<i;n++){
                                k=atol(p[n].cc);
                                if(ced==k){
                                    cout<<"\n\t\DATOS DE EL REGISTRO:";
                                    cout<<"\n\t\Nombre  : "<<p[n].nombre;
                                    cout<<"\n\t\Apellido: "<<p[n].apellido;
                                    cout<<"\n\t\Cedula  : "<<p[n].cc;
                                    cout<<"\n\tcosto : "<<p[n].costo;
                                    cout<<"\n\t\Ingrese el nuevo nombre del registro: ";
                                    cin>>p[n].servicio;
                               break;
                                }        
                            }
                           //SI LA CEDULA NO EXISTE
                                if(k!=ced){
                                    cout<<"\n\t\!!! Este registro no existe !!!";
                                    cout<<"\n\t\!!! Presione una tecla y asegurese de escribir bien la cedula !!!"<<endl;
                                    system("PAUSE");
                                        break;
                                        }
                                    cout<<"\ndesea seguir modificando nombres S/N: "<<endl;
                                     cin>>op; 
                    }while(op=='s'||op=='S');
                        	break;
                        //MODIFICAR EL APELLIDO
                        case 4: do{
                            system("CLS");
                            cout<<"\n\t\aIngrese la cedula del registro que desea modificar: ";
                            cin>>ced;
                            for(int n=0;n<i;n++){
                                k=atol(p[n].cc);
                                    if(ced==k){
                                        cout<<"\n\t\Estos son los datos del registro que se va a modificar";
                                        cout<<"\n\t\Nombre  : "<<p[n].nombre;
                                        cout<<"\n\t\Apellido: "<<p[n].apellido;
                                        cout<<"\n\t\Cedula  : "<<p[n].cc;
                                        cout<<"\n\t\Ingrese el servicio: ";
                                        cin>>p[n].servicio;
                                     break;
                                    }        
                            }
                           //SI LA CEDULA NO EXISTE
                            if(k!=ced){
                            	for(int n=0;n<i;n++){
                                cout<<"\n\t\!!! Este registro no existe !!!";
                                cout<<"\n\t\!!! Presione una tecla y asegurese de escribir bien la cedula !!!"<<endl;
                                system("PAUSE");
                                    cout<<"\n\t\DATOS DE EL REGISTRO:";
                                    cout<<"\n\t\Nombre  : "<<p[n].nombre;
                                    cout<<"\n\t\Apellido: "<<p[n].apellido;
                                    cout<<"\n\t\Cedula  : "<<p[n].cc;
                                    cout<<"\n\t\servicio : "<<p[n].servicio;
                                    cout<<"\n\t\Ingrese el costo verdadero: ";
                                    cin>>p[n].costo;
                                    break;
                                    }
                            }
                                cout<<"\ndesea seguir modificando apellidos S/N: "<<endl;
                                cin>>op; 
        }while(op=='s'||op=='S');
            break;
            case 5: do{
                            system("CLS");
                            cout<<"\n\t\aIngrese la cedula del registro que desea modificar: ";
                            cin>>ced;
                            for(int n=0;n<i;n++){
                                k=atol(p[n].cc);
                                    if(ced==k){
                                     break;
                                    }        
                            }
                           //SI LA CEDULA NO EXISTE
                            if(k!=ced){
                                cout<<"\n\t\!!! Este registro no existe !!!";
                                cout<<"\n\t\!!! Presione una tecla y asegurese de escribir bien la cedula !!!"<<endl;
                                system("PAUSE");
                                    break;
                                    }
                                cout<<"\ndesea seguir modificando apellidos S/N: "<<endl;
                                cin>>op; 
        }while(op=='s'||op=='S');
            break;
            //SALIR DEL SUBMENU MODIFICAR
               case 6:
			    break;  
              }//SERRAR SWITCH         
                   
                system("cls");      
                cout<<"\n\tDesea seguir en el submenu modificar S/N: "<<endl;
                cin>>op;
                }while(op=='s'||op=='S');
	}          
//ELIMINAR PERSONAS
void eliminar(){
        char op='S';
        long moment, cedaux;
        int ask,val=0;
        while(op=='S'){
            val=0;
            while(val==0){
                system("CLS");
                cout<<"\n\tPor favor ingrese la cedula del registro que desea eliminar: ";
                cin>>cedaux;
                for(int n=0;n<i;n++){
                    moment=atol(p[n].cc);
                    if(moment==cedaux){
                        val=1;
                        cout<<"\n\t\Estos son los datos que va a eliminar",
                        cout<<"\n\t\Nombre  : "<<p[n].nombre;
                        cout<<"\n\t\Apellido: "<<p[n].apellido;
                        cout<<"\n\t\Cedula  : "<<p[n].cc;             
                do{
                    cout<<"\n\t\¨Estas seguro que deseas elminar este registro S/N?"<<endl;
                    cin>>op;
                    op=toupper(op);
                }while(op!='S'&&op!='N');
                
                if(op=='S'){
                   i=i-1;
                   system("CLS");
                   cout<<"\n\tELIMINANDO";
                   
                for(n=1;n<=20;n++){
                cout<<"Û";
                                  }
                for(ask=n;ask<i;ask++){
                     p[ask]=p[ask+1];
                }
            }
        }
    }
        if(val==0){
        cout<<"\n\t!!! Este registro no existe !!!";
        cout<<"\n\t!!! Presione una tecla y asegurese de escribir bien la cedula !!!";
        system("PAUSE");
        }
                                              }
        do{
        system("CLS");
         cout<<"\n\tDesea eliminar otro registro S/N: "<<endl;
         cin>>op;
        op=toupper(op);
        }while(op!='S'&&op!='N');
        }
        }
//MOSTRAR MENU
void menu(){
          cout<<"\n\t\t**INFORMACION DE UN SALON DE BELLEZA**";
          cout<<"\n\n\t\t\t\t**MENU**\n\n";
          cout<<"\n\t1.) INGRESAR DATOS";
          cout<<"\n\t2.) CONSULTAR DATOS";
          cout<<"\n\t3.) MODIFICAR DATOS";
          cout<<"\n\t4.) ELIMINAR DATOS";
          cout<<"\n\t5.) SALIR"<<endl<<endl;
                   }
 
int opcion1(){
             int a;
             system("CLS");
             menu();
             do{
                cout<<"\n\tDIGITE UNA OPCION: ";
                cin>>a;
               }while((a<1)||(a>5));
               cout<<"                ";
               return(a);
             }
char opcion2(){
         int a;
     do{   
	     system("CLS");
         cout<<"\n\tDESEA VOLVER AL MENU PRINCIPAL (S) O (N): ";
         a=getch();
         a=toupper(a);
        }while((a!='S')&&(a!='N'));
        return(a);
    }
        
int main(int argc, char *argv[]){
    char op='S';
    while(op=='S'){  
        opn=opcion1();
            switch(opn){
                case 1:
                    ingresar();
                    break;
                case 2:
                    consultar();
                    break;
                case 3:
                    modificar();
                    break;
                case 4:
                    eliminar();
                    break;
                case 5:
                    exit (opn);
                    break;
            }
        op=opcion2();
                 }
    system("PAUSE");
    return EXIT_SUCCESS;
}
