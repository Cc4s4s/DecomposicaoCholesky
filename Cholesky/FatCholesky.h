#ifndef FATCHOLESKY_H
#define FATCHOLESKY_H

class FatCholesky
{
    public:

        /**
        *   Construtor
        *   @param void
        *   @return void
        */
        FatCholesky();

        /**
        *   Destrutor
        *   @param void
        *   @return void
        */
        virtual ~FatCholesky();

        /**
        *   Método responsavel por chamar as demais funcoes e
        *   executar a fatoracao LU com pivotamento parcial
        *   @param void
        *   @return void
        **/
        void FatExecutar();
    
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
        *   Funcao responsavel por fazer a operação de Deconposição de Cholesky
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

#endif // FATCHOLESKY_H