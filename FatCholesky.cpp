/*
   ==================================================================================
   Arquivo: FatCholesky.cpp
   Comentarios: Implementação da classe responsável pela fatoração de Cholesky.
   ==================================================================================
   Autor..............: Hiago Mayk Gomes de Araujo Rocha
                        Vitor de Godeiro Marques
                        Instito Metropole Digital
                        Universidade Federal do Rio Grande do Norte
                        Natal, Rio Grande do Norte, Brasil
   Data Criação.......: 28/02/2015
   Ultima Modificação.: 01/04/2017
   ==================================================================================
*/

/* ==================================================================================*/
// Includes
#include "FatCholesky.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>


/* ==================================================================================*/
//Impleementação

FatCholesky::FatCholesky()
{
    //ctor
}

FatCholesky::~FatCholesky()
{
    //dtor
}

void FatCholesky::menu()
{
    std::cout << "\t\t\tFatoracao de Cholesky:" << std::endl;
}

int FatCholesky::menuDados()
{
    this->menu();
    std::cout << "Digite a ordem da matriz: " << std::endl;
    std::cin >> this->ordem;

    //criando a matriz n X n+1
    this->matriz = new double*[this->ordem];
    for (int i = 0; i< this->ordem; ++i) { this->matriz[i] = new double[this->ordem +1]; }
    return 0;
}

void FatCholesky::prencheMatriz()
{
    int limite_i = this->ordem;
    int ordemMenor = this->ordem ;

    for(int i = 0; i < limite_i; i++)
    {
        for(int j = 0; j < limite_i; j++)
        {
            system("clear");
            this->menu();

            std::cout << "Digite o valor do elemento: ("<< i+1 <<","<< j+1 <<")" << std::endl;
            std::cin >> this->matriz[i][j];
        }
    }

    for(int i = 0; i < limite_i; i++)
    {
        system("clear");
        this->menu();

        std::cout << "Digite o vetor: \n";
        std::cout << "Elemento ("<< i+1 <<"):" << std::endl;
        std::cin >> this->matriz[i][ordemMenor];
    }
}

void FatCholesky::visualizaSistema()
{
    system("clear");
    this->menu();
    std::cout << "Sistema: \n|¯¯¯\n|\n";

    int limite_i = this->ordem;
    int limite_j = this->ordem + 1;

    for(int i = 0; i < limite_i; i++)
    {
        for(int j = 0; j < limite_j; j++)
        {
            if(j < this->ordem)
            {
                if(j != 0 && this->matriz[i][j] >=0 )
                    std::cout << "+";
                if(j == 0)
                    std::cout <<"|  ";
                std::cout << this->matriz[i][j] <<"X" << j+1;
            }
            else
                 std::cout << " = " << this->matriz[i][j] <<"\n";
        }
        std::cout << "|\n";
    }
    std::cout << "|___\n";
}

void FatCholesky::FatExecutar()
{
    this->menuDados();
    this->prencheMatriz();
    this->visualizaSistema();
    this->fatoraSistema();
    this->solucao();
}

void FatCholesky::fatoraSistema()
{

    //variaveis
    double aux;
    double matrizAux[this->ordem][this->ordem];
    double matrizG[this->ordem][this->ordem];
    double matrizU[this->ordem][this->ordem];
    double matrizL[this->ordem][this->ordem];
    double matrizD[this->ordem][this->ordem];

   for(int i = 0; i < this->ordem; i++)
    {
        for(int j = 0; j < this->ordem; j++)
        {
            matrizL[i][j] = 1;
        }
    }

    for(int i = 0; i < this->ordem; i++)
    {
        for(int j = 0; j < this->ordem; j++)
        {
            matrizU[i][j] = this->matriz[i][j];
            if(i == j)
                matrizL[i][j] = 1;
            else
                matrizL[i][j] = 0;
        }

    }

    for(int i = 0; i < this->ordem -1; i++)
    {
        //G_1 = I
        for(int k = 0; k < this->ordem; k++)
        {
            for(int j = 0; j < this->ordem; j++)
            {
                if(k == j)
                    matrizG[k][j] = 1;
                else
                    matrizG[k][j] = 0;
            }
        }

        //para j de i+1 ate n faça
        for(int j = i +1; j < this->ordem; j++)
        {
            matrizG[j][i] = -matrizU[j][i]/matrizU[i][i];
        }

        //L^-1 = G_i*L^-1
        for(int a = 0; a < this->ordem; a++)
        {
            for (int b = 0; b < this->ordem; b++)
            {
                aux = 0;
                for (int c = 0; c <   this->ordem; c++)
                    aux = aux + (matrizG[a][c] * matrizL[c][b]);
                matrizL[a][b] = aux;
            }
        }

        //U = G_i*U
         for(int a = 0; a < this->ordem; a++)
        {
            for (int b = 0; b < this->ordem; b++)
            {
                aux = 0;
                for (int c = 0; c <   this->ordem; c++)
                    aux = aux + (matrizG[a][c] * matrizU[c][b]);
                matrizU[a][b] = aux;
            }
        }

    }

    for(int k = 0; k < this->ordem -1; k++)
    {

        for(int i = k+1;  i < this->ordem; i++)
        {
            this->matriz[i][this->ordem] = this->matriz[i][this->ordem ] - this->matriz[k][this->ordem ]*this->matriz[i][k]/this->matriz[k][k];
            for(int j = 0; j < this->ordem; j++)
                matrizAux[i][j] = this->matriz[i][j] - this->matriz[k][j]*this->matriz[i][k]/this->matriz[k][k];
        }

        for(int i = k+1;  i < this->ordem; i++)
        {
            for(int j = 0; j < this->ordem; j++)
            {
                this->matriz[i][j] = matrizAux[i][j];
            }
        }
    }

    //Calcular D^(-1/2)
    for(int i = 0; i < this->ordem; i++)
    {
         for(int j = 0;  j < this->ordem; j++)
        {
            if(i == j && this->matriz[i][j] != 0)
                matrizD[i][j] = 1/(this->matriz[i][j]);
            else
                matrizD[i][j] = 0;
        }
    }

    //transposta de l
    for(int i = 0; i < this->ordem; i++)
    {
        for(int j = i + 1;  j < this->ordem; j++)
        {
            if (j != i)
            {
                aux = matrizL[i][j];
                matrizL[i][j] = matrizL[j][i];
                matrizL[j][i] = aux;
            }

        }
    }

    for(int i = 0; i < this->ordem; i++)
        this->matriz[i][this->ordem] = matrizD[i][i]*this->matriz[i][this->ordem];


    for(int k = 0; k < this->ordem; k++)
    {
        aux = 0;
        for(int i = 0; i < this->ordem; i++)
            aux += matrizL[k][i]*this->matriz[i][this->ordem];
        this->matriz[k][this->ordem] = aux;
    }
}

void FatCholesky::solucao()
{
    std::cout << "Solução:\n";
    for(int i = 0; i < this->ordem; i++)
        std::cout << "X" << i+1 << " = " << this->matriz[i][this->ordem] << "\n";
    delete this->matriz;
}
