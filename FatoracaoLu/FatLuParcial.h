/*
   ==================================================================================

   Arquivo: FatLuParcial.h
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


#ifndef FATLUPARCIAL_H
#define FATLUPARCIAL_H


class FatLuParcial
{
    public:

        /**
        *   Construtor
        *   @param void
        *   @return void
        */
        FatLuParcial();

        /**
        *   Destrutor
        *   @param void
        *   @return void
        */
        virtual ~FatLuParcial();

        /**
        *   Método responsavel por chamar as demais funcoes e
        *   executar a fatoracao LU com pivotamento parcial
        *   @param void
        *   @return void
        **/
        void FatLuExecutar();

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

        /**
        *   Metodo responsavel por impimir na tela o sistema fatorado
        *   que estamos trabalhando
        *   @param void
        *   @return void
        */
        void visualizaSistema2();

        /**
        *   Funcao responsavel por fazer as operações de pivoteamente
        *   e Fatoracao LU com pivoteamento parcial. Gerando o sistema
        *   pivotado, nao gerando a solucao
        *   @param void
        *   @return void
        */
        void fatoraSistema();

        /**
        *   Metodo responsavel por imprimir a solucao do sistema(X1,X2,...,Xn)
        *   @param void
        *   @return void
        */
        void solucao();

        //Variaveis
        int ordem;
        double **matriz;
};

#endif // FATLUPARCIAL_H