
/*
   ==================================================================================

   Arquivo: GaussSeidel.h
   Comentarios: Declaração da classe responsável pelo método de GaussSeidel

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

#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

class GaussSeidel
{
    public:

        GaussSeidel();

        virtual ~GaussSeidel();

        /**
        *   Método responsavel por chamar as demais funcoes e
        *   executar o método de GaussSeidel
        *   @param void
        *   @return void
        **/
        void executarGaussSeidel();
  
    private:
        //Funcoes

        /**
        *   Funcao responsavel por imprimir o cabecalho do menu
        *   @param void
        *   @return void
        **/
        void menu();

        /**
        *   Funcao responsavel por pegar a ordem da matriz e cria-la
        *   @param void
        *   @return
        **/
        int menuDados();

        /**
        *   Metodo responsavel por prencher a matriz completa do sistema
        *   @param void
        *   @return void
        */
        void prencheMatriz();

        /**
        *   Metodo responsavel por impimir na tela o sistema que estamos trabalhando
        *   @param void
        *   @return void
        */
        void visualizaSistema();

        bool verificaMax(float xProx[], float xAnt[]);

        /**
        *   Funcao responsavel por fazer as operações do método de Jacobi,
        *   gerando a solucao.
        *   @param void
        *   @return void
        */
        void aplicaGaussSeidel();

        /**
        *   Metodo responsavel por imprimir a solucao.
        *   @param void
        *   @return void
        */
        void solucao(float xProx[]);

        //Variaveis
        int ordem;
        float **matriz;
        float erro;
};

#endif // GAUSSSEIDEL_H
