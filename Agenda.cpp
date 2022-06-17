#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){

    string Nome[100], Email[100], Telefone[100], Busca, Name;
    int D_aniversario[100], M_aniversario[100];
    int Escolha=1, I=0, J=0, Tbusca=0, Mes;
    
    for(int i=0; i<100; i++){
        D_aniversario[i]=0;M_aniversario[i]=0;
        Nome[i]="";Email[i]="";Telefone[i]="";
    }

    while(Escolha!=0){
        cout<<"----------------------AGENDA-----------------------"<<endl;
        cout<<"Digite "<<endl;
        cout<<"[1] Para inserir um novo contato "<<endl;
        cout<<"[2] Para consultar um contato ja existente "<<endl;
        cout<<"[3] Para listar todos os contatos "<<endl;
        cout<<"[4] Para verificar os aniversariantes do mes "<<endl;
        cout<<"[5] Para visualizar o uso da agenda "<<endl;
        cout<<"[0] Para sair da agenda "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Operacao: ";
        cin>>Escolha;

        if(Escolha==1 && I<100){
            cout<<"Nome: ";cin>>Nome[I];
            cout<<"E-mail: ";cin>>Email[I];
            cout<<"Telefone: ";cin>>Telefone[I];
            cout<<"Dia do aniversario: ";cin>>D_aniversario[I];
            cout<<"Mes do aniversario: ";cin>>M_aniversario[I];
            while(M_aniversario[I]<0||M_aniversario[I]>12)
            {
                cout<<"Mes informado invalido!"<<endl;
                cout<<"informe novamente o mes do aniversario: ";cin>>M_aniversario[I];
            }
            if(M_aniversario[I]==2){
                while(D_aniversario[I]<0 || D_aniversario[I]>28 && M_aniversario[I]==2){
                    cout<<"Dia informado invalido!"<<endl;
                    cout<<"informe novamente o dia do aniversario: ";cin>>D_aniversario[I];
                    cout<<"informe novamente o mes do aniversario: ";cin>>M_aniversario[I];
                }
            }
            else if(M_aniversario[I]==4||M_aniversario[I]==6||M_aniversario[I]==9){
                while(D_aniversario[I]<0||D_aniversario[I]>30){
                    cout<<"Dia informado invalido!"<<endl;
                    cout<<"informe novamente o dia do aniversario: ";cin>>D_aniversario[I];
                }
            }
            else{
                while(D_aniversario[I]<0||D_aniversario[I]>31){
                    cout<<"Dia informado invalido!"<<endl;
                    cout<<"informe novamente o dia do aniversario: ";cin>>D_aniversario[I];
                }
            }
            I++;
        }
        else if(Escolha==2){
            int Encontrados=0;
            cout<<"Buscar por: ";
            cin>>Busca;
            Tbusca=Busca.size();
            for(int i=0;i<I;i++){
                Name=Nome[i];
                for( J=0; J<Tbusca && Name[J]==Busca[J];J++);
                if(J==Tbusca){
                    cout<<fixed<<setprecision(0);
                    cout<<i<<"- "<<"Nome: "<<Nome[i]<<" Email: "<<Email[i]<<" Tel: "<<Telefone[i];printf(" Aniversario: %02i/%02i\n", D_aniversario[i], M_aniversario[i]);
                    Encontrados++;
                }
            }
            if(Encontrados>=0){
                cout<<"Registros encontrados: "<<Encontrados<<endl;
            }
        }
        else if(Escolha==3){
            int Encontrados=0;
            for(int i=0; i<I;i++){
                cout<<i<<"- "<<"Nome: "<<Nome[i]<<" Email: "<<Email[i]<<" Tel: "<<Telefone[i];printf(" Aniversario: %02i/%02i\n", D_aniversario[i], M_aniversario[i]);
                Encontrados++;
            }
            if(Encontrados>=0){
                cout<<"Total de registros: "<<Encontrados<<endl;
            }
        }
        else if(Escolha==4){
            cout<<"Informe o mes para pesquisa: ";cin>>Mes;
            int k=0;
            for(int i=0; i<I; i++){
                if(M_aniversario[i]==Mes){
                    cout<<"Nome: "<<Nome[i];printf(" Aniversario: %02i/%02i\n", D_aniversario[i], M_aniversario[i]);
                    k++;
                }
            }
            if(k==0){
                cout<<"Nenhum aniversariante no mes informado!"<<endl;
            }
        }
        else if(Escolha==5){
            int Restante;
            Restante=100-I;
            printf("Foram usados %.i posicoes da agenda, e ainda restam %.i posicoes para salvar contatos.\n", I, Restante);
        }
    }
    return 0;
}