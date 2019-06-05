/*
  Para que el código funcione
  asegurar que esté incluido el linker:
  -lwinmm
  Para asegurar o agregar el link acceder a:
  Proyecto -> Opciones de proyecto -> Argumentos para el programa -> Enlazador(linker)
*/
#include <windows.h>
#include <iostream>
#include <conio.h>
#include<string.h>
#include<MMSystem.h>
#include<fstream>
#include<string>
#include "curso1.h"
#define V 21 //Vertical
#define H 71 //Horizontal

using namespace std;

void marco(){  
	setcolor(4); 
    for(int i=0; i<V; i++){
    	for(int j=0; j<H; j++){
			if(i==0 && j==0){
				gotoxy(j, i);
				cout << (char) 201; 
			}
			else{
				if(i==0 && j<H-1){
					gotoxy(j, i);
					cout << (char) 205;	
				}
				else{
					if(i==0 && j==H-1){
						gotoxy(j, i);
						cout << (char) 187;
					}
					else{
						if(i<V-1 && j==0){
							gotoxy(j, i);
							cout << (char) 186;                
						}
						else{
							if(i<V-1 && j==H-1){
								gotoxy(j, i);
								cout << (char) 186;                                                            
							}
							else{
								if(i==V-1 && j==0){
									gotoxy(j, i);
									cout << (char) 200;
								}
								else{
									if(i==V-1 && j<H-1){
										gotoxy(j, i);
										cout << (char) 205;
									}
									else{
										if(i==V-1 && j==H-1){
											gotoxy(j, i);
											cout << (char) 188;
										}
									}
								}
							}
						}
					}
				}
			}
    	}
}

  setcolor(4);
    for(int i=0; i<V; i++){
    	for(int j=0; j<H; j++){
			if(i==0 && j==0){
				gotoxy(j, i);
				cout << (char) 201; 
			}
			else{
				if(i==0 && j<H-1){
					gotoxy(j, i);
					cout << (char) 205;	
				}
				else{
					if(i==0 && j==H-1){
						gotoxy(j, i);
						cout << (char) 187;
					}
					else{
						if(i<V-1 && j==0){
							gotoxy(j, i);
							cout << (char) 186;
						}
						else{
							if(i<V-1 && j==H-1){
								gotoxy(j, i);
								cout << (char) 186;
							}
							else{
								if(i==V-1 && j==0){
									gotoxy(j, i);
									cout << (char) 200;
								}
								else{
									if(i==V-1 && j<H-1){
										gotoxy(j, i);
										cout << (char) 205;
									}
									else{
										if(i==V-1 && j==H-1){
											gotoxy(j, i);
											cout << (char) 188;
										}
									}
								}
							}
						}
					}
				}
			}
    	}
}
}
void PongApretado(char c, int op, int x1, int x2, int y1, int y2, int pelotaX, int pelotaY, int MovimientoPelotaX, int MovimientoPelotaY, int puntos1, int puntos2, int N){
	while (c != 27 && puntos1<7 && puntos2<7){
	while (pelotaX>1 && pelotaX<H-2){ 
   gotoxy(pelotaX, pelotaY); cout <<" ";
   pelotaX+=MovimientoPelotaX;
   pelotaY+=MovimientoPelotaY;
	 gotoxy(x1,y1); cout << " ";          // Borra
     gotoxy(x1,y1-1); cout << " ";
     gotoxy(x1,y1-2); cout << " ";
     gotoxy(x1,y1+1); cout << " ";
     gotoxy(x1,y1+2); cout << " ";
     
     gotoxy(x2,y2); cout << " ";          // Borra
     gotoxy(x2,y2-1); cout << " ";
     gotoxy(x2,y2-2); cout << " ";
     gotoxy(x2,y2+1); cout << " ";
     gotoxy(x2,y2+2); cout << " ";
	 if(kbhit()==1){
		c=getch();
		if(c=='w'||c=='W'){
			if(y1>=4){
			y1-=1;
		}
		}
		if(c=='s'||c=='S'){
			if(y1<=V-5){
			y1+=1;
		}
		}
		if(c==72){
			if(y2>=4){
			y2-=1;
		}
		}
		if(c==80){
			if(y2<=V-5){
			y2+=1;
		}
		}
	}
setcolor(13); 
	 gotoxy(x1, y1); cout << (char) 219;
	 gotoxy(x1, y1-1); cout << (char) 219;
	 gotoxy(x1, y1-2); cout << (char) 219;
	 gotoxy(x1, y1+1); cout << (char) 219;
	 gotoxy(x1, y1+2); cout << (char) 219;
	 
	 gotoxy(x2, y2); cout << (char) 219;
	 gotoxy(x2, y2-1); cout << (char) 219;
	 gotoxy(x2, y2-2); cout << (char) 219;
	 gotoxy(x2, y2+1); cout << (char) 219;
	 gotoxy(x2, y2+2); cout << (char) 219;     
	if(pelotaY==1 || pelotaY==V-2){
		Beep(3000, 100);
		MovimientoPelotaY*=-1; 
	}
	if(pelotaX==3){
		for(int f=y1-2; f<=y1+2; f++){
				if(f==pelotaY){
					Beep(3000, 100);
					MovimientoPelotaX*=-1;
				}
		}
	}
	if(pelotaX==H-4){
		for(int a=y2-2; a<=y2+2; a++){
				if(a==pelotaY){
					Beep(3000, 100);
					MovimientoPelotaX*=-1;
			
			}
			}
	}   
    setcolor(3); gotoxy(pelotaX, pelotaY); cout << (char) 79; 
    Sleep(N);  
   		}
   	Beep(5000, 200);
	Sleep(1000);
   	N-=5;
	gotoxy(pelotaX, pelotaY); cout<<" ";
   	if(pelotaX==1){
   		puntos2+=1;
    }
   	if(pelotaX==H-2){
		puntos1+=1;
   	}
   	pelotaX=H/2;
   	pelotaY=V/2;
   	gotoxy(1,21); cout<<"Jugador 1: "<<puntos1;
   	gotoxy(59, 21); cout<<"Jugador 2: "<<puntos2;
	}
}
void Pong1x1(char c, int op, int x1, int x2, int y1, int y2, int pelotaX, int pelotaY, int MovimientoPelotaX, int MovimientoPelotaY, int puntos1, int puntos2, int N){
	while (c != 27 && puntos1<7 && puntos2<7){
	while (pelotaX>1 && pelotaX<H-2){ 
   gotoxy(pelotaX, pelotaY); cout <<" ";
   pelotaX+=MovimientoPelotaX;
   pelotaY+=MovimientoPelotaY;
	  if (kbhit()) { 
            c = getch(); 
            switch(c){
                case 115:op = 1;
                         break;
                case 83:op=1; break;
                case 119:op = 2;
                         break;
                case 87:op=2; break;
                case 72:op=3; break;
                case 80:op=4; break;
                case 113:op = 5;
                case 81:op=5;
				case 77: op=6;                  
            }
     }
     gotoxy(x1,y1); cout << " ";          // Borra
     gotoxy(x1,y1-1); cout << " ";
     gotoxy(x1,y1-2); cout << " ";
     gotoxy(x1,y1+1); cout << " ";
     gotoxy(x1,y1+2); cout << " ";
     
     gotoxy(x2,y2); cout << " ";          // Borra
     gotoxy(x2,y2-1); cout << " ";
     gotoxy(x2,y2-2); cout << " ";
     gotoxy(x2,y2+1); cout << " ";
     gotoxy(x2,y2+2); cout << " ";
	 switch(op){                             // Mueve   
                case 1:if(y1<V-4) y1++;
                         break;
                case 2:if(y1>3) y1--;
                         break;
				case 3:if(y2>3) y2--; break;
				case 4:if(y2<V-4) y2++; break; 
				case 5:y1=y1; break;
				case 6:y2=y2; break;        
            }              
     setcolor(13); 
	 gotoxy(x1, y1); cout << (char) 219;
	 gotoxy(x1, y1-1); cout << (char) 219;
	 gotoxy(x1, y1-2); cout << (char) 219;
	 gotoxy(x1, y1+1); cout << (char) 219;
	 gotoxy(x1, y1+2); cout << (char) 219;
	 
	 gotoxy(x2, y2); cout << (char) 219;
	 gotoxy(x2, y2-1); cout << (char) 219;
	 gotoxy(x2, y2-2); cout << (char) 219;
	 gotoxy(x2, y2+1); cout << (char) 219;
	 gotoxy(x2, y2+2); cout << (char) 219;     
	if(pelotaY==1 || pelotaY==V-2){
		Beep(3000, 100);
		MovimientoPelotaY*=-1; 
	}
	if(pelotaX==3){
		for(int f=y1-2; f<=y1+2; f++){
				if(f==pelotaY){
					Beep(3000, 100);
					MovimientoPelotaX*=-1;
				}
		}
	}
	if(pelotaX==H-4){
		for(int a=y2-2; a<=y2+2; a++){
				if(a==pelotaY){
					Beep(3000, 100);
					MovimientoPelotaX*=-1;
				}
			}
	}   
    setcolor(3); gotoxy(pelotaX, pelotaY); cout << (char) 79; 
    Sleep(N);  
   		}
   	Beep(5000, 200);
	Sleep(1000);
   	N-=5;
	gotoxy(pelotaX, pelotaY); cout<<" ";
   	if(pelotaX==1){
   		puntos2+=1;
    }
   	if(pelotaX==H-2){
		puntos1+=1;
   	}
   	pelotaX=H/2;
   	pelotaY=V/2;
   	gotoxy(1,21); cout<<"Jugador 1: "<<puntos1;
   	gotoxy(59, 21); cout<<"Jugador 2: "<<puntos2;
	}
}
void titulo(){
	char title[8][47]={
		"                                              ",
		"                         XXXX XXXX X  X XXXX X",
		"                         X  X X  X XX X X    X",
		"                         X  X X  X XX X X    X",
		"                         XXXX X  X X XX X XX X",
		"                         X    X  X X XX X  X  ",
		"                         X    XXXX X  X XXXX X",  	
	};
	for(int i=0; i<8; i++){
		for(int j=0; j<47; j++){
			if(title[i][j]=='X'){
				gotoxy(j, i);
				cout<<char (178);
			}
		}
	}
}
int main(){
	PlaySound(TEXT("MortalKombat.wav"),NULL,SND_LOOP|SND_ASYNC);                                                    //Música
	OcultarCursor();                                                                                        //Oculta el cursor
   char c = 0;                                                                                              //Inicio de declaración de variables
   int op = 0, x1 = 2, y1 = 11, x2=H-3, y2=11, N=70, mn, repetir=1; 
   int pelotaX = H/2, pelotaY = V/2, MovimientoPelotaX=-1, MovimientoPelotaY=1;
   int puntos1=0, puntos2=0;
   char letra;
   char item[][30]={"Jugar Pong 1x1", "Jugar Pong TabTab", "Instrucciones", "Creditos", "Salir"};                                         //Fin de declaración de variables
   marco();                                                                                                 //Presentación del programa
   setcolor(0xA9);
   gotoxy(1,1);
   titulo();
   gotoxy(25, 7);
   cout<<"By Angie & Alex, 2018";
   gotoxy(26, 8);
   cout<<"Antes de iniciar...";
   gotoxy(12,10);
   cout << "Expanda la pantalla hasta ver un marco completo";
   gotoxy(15,12);
   system("PAUSE");
   do{
   setcolor(0x00);
   system("CLS");
   marco();
	mn=vmenu(1,1,0x4F, 0xF4, item, 5);
	   setcolor(0x00);
	   system("CLS");
	   marco();
	   switch(mn){
	   	case 1: Pong1x1(c, op, x1, x2, y1, y2, pelotaX, pelotaY, MovimientoPelotaX, MovimientoPelotaY, puntos1, puntos2, N); 
		   if(puntos1==7){
		   	gotoxy(H/2, V/2); cout<<"El jugador 1 ha ganado";
		   }
		   if(puntos2==7){
		   	gotoxy(H/2, V/2); cout<<"El jugador 2 ha ganado";
		   }
		   break;
		case 2: PongApretado(c, op, x1, x2, y1, y2, pelotaX, pelotaY, MovimientoPelotaX, MovimientoPelotaY, puntos1, puntos2, N); 
		   if(puntos1==7){
		   	gotoxy(H/2, V/2); cout<<"El jugador 1 ha ganado"; getch();
		   }
		   if(puntos2==7){
		   	gotoxy(H/2, V/2); cout<<"El jugador 2 ha ganado"; getch();
		   }
		   break;
	   	case 3: setcolor(0xA9); gotoxy(1,1);
	   		/*string line;
	   		ifstream myfile ("instrucciones.txt");
	   		if(myfile.is_open())
	   		{
	   			while (getline (myfile,line)){
	   				cout<<line<<"\n";
	   			}
	   			myfile.close();
	   		}*/
			cout<<"Pong 1x1\nControles:\nJugador 1:    | Jugador 2:\nArriba: W o w | Arriba: Tecla Up"<<endl;
			cout<<" Abajo : S o s | Abajo : Tecla Down\nFrenar: Q o q | Frenar: Tecla Right"<<endl;
			cout<<" En este modo de juego solo se mueve una raqueta a la vez por lo que "<<endl;
			cout<<" aumenta la competitividad entre jugadores."<<endl;
			cout<<" Tambien con solo apretar la tecla correspondiente, sin mantenerla,"<<endl;
			cout<<" la raqueta mantiene su movimiento."<<endl;
			cout<<" -------------------------------------"<<endl;
			cout<<" Pong TabTab\nControles:\nJugador 1:    | Jugador 2:"<<endl;
			cout<<" Arriba: W o w | Arriba: Tecla Up\nAbajo : S o s | Abajo : Tecla Down"<<endl;
			cout<<" En este modo de juego cada jugador se mueve independientemente del"<<endl; 
			cout<<" otro jugador por lo que ya no habran trampas entre jugadores, la"<<endl; 
			cout<<" cuestión es que ahora tendrás que apretar varias veces la tecla.";
			   getch();
		    break;
	   	case 4: setcolor(0xA9); gotoxy(1,1);
	   	/*string line;
	   		ifstream myfile ("creditos.txt");
	   		if(myfile.is_open())
	   		{
	   			while (getline (myfile,line)){
	   				cout<<line<<"\n";
	   			}
	   			myfile.close();
	   		}*/

	   		cout<<"Pong! v1.0\n Universidad Autonoma de Yucatan\n \n Angeles Mena"<<endl;
			gotoxy(1,5);cout<<"Alejandro Santoscoy\n\n 2018";
		   gotoxy(1,8); cout<<"Presiona cualquier tecla para continuar...";
		   getch();
		   break;
	   	case 5: gotoxy(1,1); cout<<"¡Adios!"; Beep(5000, 1000); Sleep(1000); mn=6; repetir=0; break;
	   }
}while(mn!=6);

   return 0; 
}
