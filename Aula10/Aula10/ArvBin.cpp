#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

void ArvBin::contaNos(){
  cout << endl << "Nos:" <<auxcontaNos(raiz) << endl;
 }

 int ArvBin::auxcontaNos(NoArv* p){
     int nd=0, ne=0;
    if(p==NULL){
        return 0;
    }
    else{
        ne=auxcontaNos(p->getEsq());
        nd=auxcontaNos(p->getDir());
        return 1+ne+nd;
    }
 }

void ArvBin::contaFolha(){
    cout << endl << "Folhas:" <<auxcontaFolha(raiz) << endl;
}

int ArvBin::auxcontaFolha(NoArv *p){
    int nd, ne;
    if(p==NULL){
        return 0;
    }
    if(p->getDir()==NULL&&p->getEsq()==NULL){
        return 1;
    }
    else{
        ne=auxcontaFolha(p->getEsq());
        nd=auxcontaFolha(p->getDir());
        return ne+nd;
    }
}

int ArvBin::Altura(){
    cout << endl << "Altura:" <<auxAltura(raiz)<< endl;
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p){
    int nd, ne;
    if(p==NULL){
        return -1;
    }
    else{
     ne=auxAltura(p->getEsq());
     nd=auxAltura(p->getDir());
     return 1+(ne>nd ? ne : nd);
    }
}

void ArvBin::contaImpar(){
    cout << endl << "Impares:" <<auxcontaImpar(raiz)<< endl;
}

int ArvBin::auxcontaImpar(NoArv *p){
    int ne,nd;
    if(p==NULL){
        return 0;
    }
    if(p->getInfo()%2!=0){
            ne=auxcontaImpar(p->getEsq());
            nd=auxcontaImpar(p->getDir());
            return 1+ne+nd;
    }
    else{
            ne=auxcontaImpar(p->getEsq());
            nd=auxcontaImpar(p->getDir());
            return ne+nd;
    }
}

int ArvBin::auxNivel(NoArv *p, int atual, int k)
{
    if(p!=NULL){
        if(atual==k)
            cout << p->getInfo() << " ";
        else{
            auxNivel(p->getEsq(), atual+1, k);
            auxNivel(p->getDir(), atual+1, k);
        }
    }
}


void ArvBin::imprimeNivel(int k)
{
    int atual = 0;
    auxNivel(raiz, atual, k);
}

void ArvBin::troca(){
    auxTroca(raiz);
}

int ArvBin::auxTroca(NoArv *p){
        if(p!=NULL){
        NoArv *aux=p->getEsq();
        NoArv *aux2=p->getDir();
        p->setEsq(p->getDir());
        p->setDir(aux);
        auxTroca(p->getEsq());
        auxTroca(p->getDir());
        p->setEsq(aux2);
        p->setDir(aux);
    }
}

void ArvBin::noMaisEsquerda(){
    auxnoMaisEsquerda(raiz);
}

int ArvBin::auxnoMaisEsquerda(NoArv *p){
    if(p->getEsq()==NULL){
        cout<<endl<<"no mais a E"<< p->getInfo()<<endl;
    }
    else{
       auxnoMaisEsquerda(p->getEsq());
    }
}

void ArvBin::noMaisDir(){
    auxnoMaisDir(raiz);
}

int ArvBin::auxnoMaisDir(NoArv *p){
    if(p->getDir()==NULL){
        cout<<endl<<"no mais a D"<< p->getInfo()<<endl;
    }
    else{
       auxnoMaisDir(p->getDir());
    }
}

void ArvBin::minSubArvore(){
    auxminSubArvore(raiz,raiz->getInfo());
}

int ArvBin::auxminSubArvore(NoArv *p,int mini){
    if(p != NULL){
            if(p->getInfo()<mini){
                mini=p->getInfo();
            }
        auxminSubArvore(p->getEsq(),mini);
        auxminSubArvore(p->getDir(),mini);
    }

}

