#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

//Ver si hay algun barco donde se va a crear otro nuevo
int verBarcos(int matriz[][10], int orientacion, int fila, int col, int barco)
{
    //horizontal=0
    //vertical=1
    //barco=tama;o del barco
    
    int c=0;
    
    if (orientacion==0)
    {
        for (int i=col; i<col+barco; i++)
        {
            if (matriz[fila][i]==1)
            {
                c=1;
            }
        }
    }
    
    if (orientacion==1)
    {
        for (int i=fila; i<fila+barco; i++)
        {
            if (matriz[i][col]==1)
            {
                c=1;
            }
        }
    }
    
    return c;
}

//Comparar dos matrices para ver si ya se hundieron todos los barcos
int compare(int matriz[][10], int matriz0[][10])
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (matriz[i][j]!=matriz0[i][j])
            {
                return 0;
            }
        }
    }
    
    return 1;
}

//crear los barcos
void barcos(int matriz[][10], int orientacion, int fila, int col, int tbarco, int limite)
{
    //horizontal=0
    //vertical=1
    //tbarco=tamaño del barco
    //barco=tamaño del barco anterior
    //limite=la ultima posicion en la que puede estar el barco antes de salirse de la matriz
    
    orientacion=rand()%2;
    //cout << orientacion;
    //cout << "\n";
    
    if (orientacion==0)
    {
        while (col>limite)
        {
            fila=rand()%10;
            col=rand()%10;
            //cout << fila;
            //cout << col;
            //cout << "\n";
            
            while (verBarcos(matriz, orientacion, fila, col, tbarco)==1)
            {
                fila=rand()%10;
                col=rand()%10;
                //cout << fila;
                //cout << col;
                //cout << "\n";
            }
        }
            for (int i=col; i<col+tbarco; i++)
            {
                matriz[fila][i]=1;
            }
    }
    
    if (orientacion==1)
    {
        while (fila>limite)
        {
            fila=rand()%10;
            col=rand()%10;
            //cout << fila;
            //cout << col;
            //cout << "\n";
            
            while (verBarcos(matriz, orientacion, fila, col, tbarco)==1)
            {
                fila=rand()%10;
                col=rand()%10;
                //cout << fila;
                //cout << col;
                //cout << "\n";
            }
        }
            for (int i=fila; i<fila+tbarco; i++)
            {
                matriz[i][col]=1;
            }
            
    }
}

//meter los barcos al la matriz
void meterBarcos(int matriz[][10])
{
    int orientacion5=0;
    int fila5=9;
    int col5=9;
    int orientacion4=0;
    int fila4=9;
    int col4=9;
    int orientacion3=0;
    int fila3=9;
    int col3=9;
    int orientacion2=0;
    int fila2=9;
    int col2=9;
    int orientacion1=0;
    int fila1=9;
    int col1=9;
    
    barcos(matriz, orientacion5, fila5, col5, 5, 5);
    barcos(matriz, orientacion4, fila4, col4, 4, 6);
    barcos(matriz, orientacion3, fila3, col3, 4, 6);
    barcos(matriz, orientacion2, fila2, col2, 3, 7);
    barcos(matriz, orientacion1, fila1, col1, 2, 8);
    

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            cout << setw(3) << matriz[i][j];
        }
        cout << "\n";
    }

    
}

//El de los 9, para ver si los barcos estan hundidos
void otroGrid (int matriz[][10], int matriz0[][10])
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (matriz[i][j]==1)
            {
                matriz0[i][j]=9;
            }
            //cout << setw(3) << matriz0[i][j];
        }
        //cout << "\n";
    }
}

int main()
{
    int fila=0;
    int col=0;
    int intentos=0;
    
    int matriz[10][10]=
    {

    };
    
    int matriz0[10][10]=
    {

    };
    
    int matriz2[10][10]=
    {
        
    };
    
    srand(time(nullptr));
    
    meterBarcos(matriz);
    
    cout << "\n";
    
    otroGrid(matriz,matriz0);
    
    cout << "SHIP WARS!" << endl;
    cout << "Elije un numero del 0-9 para atacar una fila y otro para la columna con el objetivo de hundir el barco. El juego termina cuando logras hundir todos los barcos" << endl;
    cout << "Son 5 barcos en total: 1 de 5 espacios, 2 de 4 espacios, 1 de 3 espacios y otro de 2 espacios." << endl;
    cout << "El 1 significa que le diste al barco y el 2 que fallaste." << endl <<endl;
    
    while (compare(matriz, matriz0)==0)
    {
        cout << "Fila (izquierda - derecha): ";
        cin >> fila;
        cout << "Columna (arriba - abajo): ";
        cin >> col;
        

        cout << "\n";
        
        if (fila<10 && col<10)
        {
            /*
            tablero
            cout << "Jugador\n";
            
            cout << "     0  1  2  3  4  5  6  7  8  9\n\n";
            
            for (int i=0; i<10; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (j==0)
                    {
                        cout << i << "  ";
                    }
                    cout << setw(3) << matriz[i][j];
                }
                cout << "\n";
            }
            
            cout << "\n";
            */
            
            cout << "CPU\n";
            
            cout << "     0  1  2  3  4  5  6  7  8  9\n\n";
            
            for (int i=0; i<10; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (j==0)
                    {
                        cout << i << "  ";
                    }
                    if (matriz[fila][col]==1)
                    {
                        matriz2[fila][col]=1;
                        matriz[fila][col]=9;
                    }
                    if (matriz[fila][col]==0)
                    {
                        matriz2[fila][col]=2;
                    }
                    cout << setw(3) << matriz2[i][j];
                }
                cout << "\n";
            }
            
            cout << "\n";
            
            if (matriz2[fila][col]==1)
            {
                cout << "HIT\n";
            }
            
            if (matriz2[fila][col]==2)
            {
                cout << "MISS\n";
            }
    
            cout << "\n";
        }
        else
        {
            cout << "Ingresa un numero del 0-9\n\n";  
        }
        
        intentos+=1;
    }
    
    cout << "Ganaste\n";
    
    cout << "Numero de intentos: " << intentos << endl;
    
    return 0;
}