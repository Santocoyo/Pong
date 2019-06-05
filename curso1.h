#define _CURSO1_H
#include<iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 50;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
	
}
void gotoxy(int x, int y){
    HANDLE hConsoleOutput;
    COORD coord;
    hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition (hConsoleOutput, coord);
}

void setcolor(int col){
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),col);
} 

int vmenu(int x, int y, int col1, int col2, char m[][30], int n){
    int op = 1;
    char c;
    int i, j, l, lmax = 0;
    for(i=0; i<n; i++){
        l = strlen(m[i]);
        if (l>lmax) lmax = l;
    } 
    for(i=0; i<n; i++){
        l = strlen(m[i]);
        if (l<lmax) {
            for(j=l; j<lmax; j++){
                m[i][j] = ' ';
            }
            m[i][j] = '\0';
        }
    }    
    setcolor(col2); gotoxy(x,y); cout << m[0] << endl; 
    for(i=1; i<n; i++){
       setcolor(col1); gotoxy(x,y+i); cout << m[i] << endl;
    }
    while (c != 13){ 
      if (kbhit()) {                        // Teclado
            c = getch(); 
            switch(c){
                case 80:if(op < n) op ++;
                         break;
                case 72:if(op > 1) op --;         
            }
            for(i=0; i<n; i++){
                if(op == i+1) 
                   setcolor(col2);
                else
                   setcolor(col1);
                gotoxy(x,y+i); cout << m[i] << endl;
            }
     }
   }
   return op;
}
