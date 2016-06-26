/*
   ==================================================================================

   Arquivo: FatLuParcial.cpp
   Comentarios: Implementação da classe responsável pela fatoração Lu com pivotamento
                parcial.

   ==================================================================================

   Autor..............: Hiago Mayk Gomes de Araujo Rocha
                        Vitor de Godeiro Marques
                        Instito Metropole Digital
                        Universidade Federal do Rio Grande do Norte
                        Natal, Rio Grande do Norte, Brasil
   Data Criação.......: 28/02/2015
   Ultima Modificação.: 28/02/2015

   ==================================================================================
*/

/* ==================================================================================*/
// Includes
#include "FatLuParcial.h"
#include <iostream>
#include <stdlib.h>

/* ==================================================================================*/
//Impleementação



FatLuParcial::FatLuParcial()
{
    //ctor
}

FatLuParcial::~FatLuParcial()
{
    //dtor
}

void FatLuParcial::menu()
{
    std::cout << "\t\t\tFatoracao LU com Pivoteamento Parcial:" << std::endl;
}

int FatLuParcial::menuDados()
{
    this->menu();
    std::cout << "Digite a ordem da matriz: " << std::endl;
    std::cin >> this->ordem;

    //criando a matriz n X n+1
    this->matriz = new double*[this->ordem];
    for (int i = 0; i< this->ordem; ++i) { this->matriz[i] = new double[this->ordem +1]; }
    return 0;
}

void FatLuParcial::prencheMatriz()
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

void FatLuParcial::visualizaSistema()
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

void FatLuParcial::visualizaSistema2()
{
    std::cout << "\n\nAplicação do método de Gauss no sistema: \n|¯¯¯\n|\n";

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

void FatLuParcial::FatLuExecutar()
{
    this->menuDados();
    this->prencheMatriz();
    this->visualizaSistema();
    this->fatoraSistema();
    this->visualizaSistema2();
    this->solucao();
}

void FatLuParcial::fatoraSistema()
{
    //variaveis
    double aux;
    double matrizAux[this->ordem][this->ordem];
    double semente;
    int pos;

    for(int k = 0; k < this->ordem -1; k++)
    {
        semente = this->matriz[k][k];
        pos = -1;
        for(int i = k + 1; i < this->ordem; i++)
        {
            if(this->matriz[i][k] > semente || (semente == 0 && this->matriz[i][k] != 0))
            {
                semente = this->matriz[i][k];
                pos = i;
            }
        }

        aux = 0;

        for(int i = 0;  i < this->ordem + 1 && pos != -1; i++)
        {
            aux = this->matriz[k][i];
            this->matriz[k][i] = this->matriz[pos][i];
            this->matriz[pos][i] = aux;
        }


        for(int i = k+1;  i < this->ordem; i++)
        {
            this->matriz[i][this->ordem] = this->matriz[i][this->ordem ] - this->matriz[k][this->ordem ]*this->matriz[i][k]/this->matriz[k][k];
            for(int j = 0; j < this->ordem; j++)
                matrizAux[i][j] = this->matriz[i][j] - this->matriz[k][j]*this->matriz[i][k]/this->matriz[k][k];
        }


        for(int i = k+1;  i < this->ordem; i++)
        {
            for(int j = 0; j < this->ordem; j++)
                this->matriz[i][j] = matrizAux[i][j];
        }

    }
}

void FatLuParcial::solucao()
{
    std::cout << "Solução:\n";
    double resposta[this->ordem];
    
    for(int i = 0; i < this->ordem; i++) resposta[i] = 0;

    for(int i = this->ordem -1 ; i >= 0; i--)
    {
        for(int j = i+1; j < this->ordem; j++)
        {
            resposta[i] = resposta[j]*this->matriz[i][j] + resposta[i];
        }

        resposta[i] = this->matriz[i][this->ordem]- resposta[i];
        resposta[i] = resposta[i]/this->matriz[i][i];
    }
    for(int i = 0; i < this->ordem; i++)
        std::cout << "X" << i+1 << " = " << resposta[i] << "\n";
    delete this->matriz;
}