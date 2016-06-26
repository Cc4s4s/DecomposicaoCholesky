					/*
   ==================================================================================

   Arquivo: Jacobi.cpp
   Comentarios: Implementação da classe responsável pele execução do método de Jacobi

   ==================================================================================

   Autor..............: Hiago Mayk Gomes de Araujo Rocha
                        Vitor de Godeiro Marques
                        Instito Metropole Digital
                        Universidade Federal do Rio Grande do Norte
                        Natal, Rio Grande do Norte, Brasil
   Data Criação.......: 28/02/2016
   Ultima Modificação.: 16/03/2016

   ==================================================================================
*/

/* ==================================================================================*/
// Includes
#include "Jacobi.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>

/* ==================================================================================*/
//Impleementação

Jacobi::Jacobi()
{
    //ctor
}

Jacobi::~Jacobi()
{
    //dtor
}

void Jacobi::menu()
{
    std::cout << "\t\t\tMétodo de Jacobi:" << std::endl;
}

int Jacobi::menuDados()
{
    this->menu();
    std::cout << "Digite a ordem da matriz: " << std::endl;
    std::cin >> this->ordem;

    //criando a matriz n X n+1
    this->matriz = new double*[this->ordem];
    for (int i = 0; i< this->ordem; ++i) { this->matriz[i] = new double[this->ordem +1]; }
    return 0;
}

void Jacobi::prencheMatriz()
{
    int limite_i = this->ordem;
    int ordemMenor = this->ordem;

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
        std::cin >> this->matriz[i][this->ordem];
    }

    std::cout << "Digite o erro: \n";
    std::cin >> erro;
}

void Jacobi::visualizaSistema()
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

void Jacobi::executarJacobi()
{
    this->menuDados();
    this->prencheMatriz();
    this->visualizaSistema();
    this->aplicaJacobi();
}

bool Jacobi::verificaMax(double xProx[], double xAnt[])
{
    double maximo = fabs(xProx[0] - xAnt[0]);

    for(int i = 1; i < this->ordem; i++)
    {
        if(maximo < fabs(xProx[i] - xAnt[i]))
        {
            maximo = fabs(xProx[i] - xAnt[i]);
        }
    }

    std::cout << "Aproximação: " << maximo << std::endl;
    return maximo > this->erro;
}

void Jacobi::aplicaJacobi()
{
    //variaveis
    double xAnt[this->ordem] = {0};
    double xProx[this->ordem] = {0};
    double somatorio = 0;

    int interacao = 0;
    do
    {
        for(int i = 0; i < this->ordem; i++)
        {
            xAnt[i] = xProx[i];
        }

        for(int i = 0; i < this->ordem; i++)
        {
            somatorio = 0;
            for(int j = 0; j < this->ordem; j++)
            {
                if(i != j)
                {
                    somatorio = somatorio + this->matriz[i][j] * xAnt[j];
                }
            }
            xProx[i] = (this->matriz[i][this->ordem] - somatorio) / this->matriz[i][i];
        }

        interacao = interacao + 1;
        std::cout << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Iteranção: " << interacao << std::endl;
        for(int i = 0; i < this->ordem; i++)
        {
            std::cout << xProx[i] << std::endl;
        }
    }
    while(verificaMax(xProx, xAnt));

    std::cout << "----------------------------------------" << std::endl;
    solucao(xProx);
}

void Jacobi::solucao(double xProx[])
{
    std::cout << "Solução:\n";

    for(int i = 0; i < this->ordem; i++)
        std::cout << "X" << i+1 << " = " << xProx[i] << "\n";
    delete this->matriz;
}