#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    void contaNos();
    void contaFolha();
    int Altura();
    void contaImpar();
    void imprimeNivel(int x);
    void troca();
    void imprime();
    void noMaisEsquerda();
    void noMaisDir();
    void minSubArvore();
  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    int auxcontaNos(NoArv *p);
    int auxcontaFolha(NoArv *p);
    int auxAltura(NoArv *p);
    int auxcontaImpar(NoArv *p);
    int auxNivel(NoArv *p, int atual, int k);
    int auxTroca(NoArv *p);
    int auxImprime(NoArv *p);
    int auxnoMaisEsquerda(NoArv *p);
    int auxnoMaisDir(NoArv *p);
    int auxminSubArvore(NoArv *p);
};

#endif // ARVBIN_H_INCLUDED
