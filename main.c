#include <stdio.h>
#include <stdlib.h>

void neto(n_pid) {
        printf("-----------------NETO------------------------------------\n");
        printf("Processo neto diz:\"Meu PID eh = %d\"\n", getpid());
        printf("Processo neto diz:\"Sou filho do = %d\"\n", getppid());
        int iNeto;
        for (iNeto = 300; iNeto <= 700; iNeto++) {
                if ((iNeto % 100) == 0 && iNeto != 300) {
                        printf("%d\n", iNeto);
                        sleep(2);
                }
        }
        printf("O processo Neto vai morrer...\n");
}

void pai(int n_pid) {
        printf("-----------------PAI------------------------------------\n");
        printf("Processo pai diz: \"Para mim, o fork retornou: %d\"\n", n_pid);
        printf("Processo pai diz: \"Meu PID eh = %d\"\n", getpid());
        int iPai;
        for (iPai = 0; iPai <= 50; iPai++) {
                if ((iPai % 10) == 0 && iPai != 0) {
                        printf("%d\n", iPai);
                        sleep(2);
                }
        }
        printf("O processo Pai vai morrer...\n");
}

void filho(int n_pid) {
        int n_filho_pid = fork();
        if(n_filho_pid == 0) {
                neto(n_filho_pid);
                exit(0);
        }
        wait(n_filho_pid);
        printf("---------------FILHO-----------------------------------\n");
        printf("Processo filho diz:\"Meu PID eh = %d\"\n", getpid());
        printf("Processo filho diz:\"Sou filho do = %d\"\n", getppid());
        int iFilho;
        for (iFilho = 100; iFilho <= 200; iFilho++) {
                if ((iFilho % 50) == 0 && iFilho != 100) {
                        printf("%d\n", iFilho);
                        sleep(2);
                }
        }
        printf("O processo Filho vai morrer...\n");
}

int main(void) {
        int n_pid;
        int t, status;

        printf ("-- PID Original do Programa = %d --- \n", getpid());

        n_pid = fork();

        if ( n_pid < 0 )
        {
                printf("Erro na criacao do processo\n");
                return -1;
        }

        else if (n_pid == 0)
        {
                filho(n_pid);
                exit(0);
        }
        else
        {
                wait(n_pid);
                pai(n_pid);
        }

        return 0;
}