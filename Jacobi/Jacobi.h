/*
   ==================================================================================

   Arquivo: Jacobi.h
   Comentarios: Declaração da classe responsável pela fatoração Lu com pivotamento
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


#ifndef JACOBI_H
#define JACOBI_H


class Jacobi
{
    public:

        Jacobi();

        virtual ~Jacobi();

        /**
        *   Método responsavel por chamar as demais funcoes e
        *   executar o método de Jacobi
        *   @param void
        *   @return void
        **/
        void executarJacobi();

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

        bool verificaMax(double xProx[], double xAnt[]);

        /**
        *   Funcao responsavel por fazer as operações do método de Jacobi,
        *   gerando a solucao.
        *   @param void
        *   @return void
        */
        void aplicaJacobi();

        /**
        *   Metodo responsavel por imprimir a solucao.
        *   @param void
        *   @return void
        */
        void solucao(double xProx[]);

        //Variaveis
        int ordem;
        double **matriz;
        double erro;
};

#endif // JACOBIL_H
