#include<bits/stdc++.h>
using namespace std;
ifstream f("permis.in");
ofstream g("permis.out");
void citire(int a[51][51],int &n,int &m)
{
    int i,j;
    f>>n>>m;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            f>>a[i][j];
        }
    }
}
void afisare(int a[51][51],int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            g<<a[i][j]<<' ';
        g<<endl;
    }
}
int verifscresc(int a[51][51], int n)
{
    for(int i=1; i<=n; i++)
        if(a[i-1][0]>=a[i][0])
            return 0;
        else
            return 1;
}

void swp(int a[51][51],int l1,int l2,int m)
{
    int aux=0;
    for(int i=0; i<m; i++)
    {
        aux=a[l1][i];
        a[l1][i]=a[l2][i];
        a[l2][i]=aux;;
    }
}

void sortare(int a[51][51],int n,int m)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i][0]>a[j][0])
                swp(a,i,j,m);
}
int  pregatire_oras(int b[51][51],int n,int m)
{
    int i,j,k=0;
    for(i=0; i<n; i++)
    {
        if(b[i][1]==1)
            k++;

    }
    return k;
}
void stergere_respinsi_teorie(int b[51][51],int &n,int &m)
{
    int k=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(b[i][1]==0)
            {
                for(int k = i; k< n - 1; k++)
                {
                    for(int j = 0; j < m; j++)
                        b[k][j] =b[k + 1][j];
                }
                n--;
            }
        }
}

int main()
{
    int n,m,o,p,a[51][51],b[51][51],i,j,k,c,x,y,z[51][51],x1=0;
    citire(a,n,m);
    x=n;
    y=m;
    g<<"Formatul initial al tabelului de persoane inscrise este:";
    g<<endl;
    afisare(a,n,m);
    g<<verifscresc(a,n);
    g<<endl;
    if(verifscresc(a,n)==0)
        g<<"Persoanele nu sunt programate la examenul teoretic in ordinea inscrierii";
    else
        g<<"Persoanele sunt programate la examenul teoretic in ordinea inscrierii";
    g<<endl;
    g<<"Ordinea de desfasurare a probei scrise este:";
    g<<endl;
    sortare(a,n,m);
    afisare(a,n,m);
    g<<"Pentru cei ce trec de proba scrisa vom avea un nou tabel cu a  doua coloana continand cifra 1,iar ceilalti vor avea 0";
    g<<endl;
    citire(b,n,m);
    g<<"Formatul noului tabel de persoane  este:";
    g<<endl;
    afisare(b,n,m);
    g<<"Persoanele pregatite pentru oras sunt in numar de:"<<" ";
    g<<pregatire_oras(b,n,m);
    g<<endl;
    stergere_respinsi_teorie(b,n,m);
    g<<"Participantii la proba practica sunt:";
    g<<endl;
    afisare(b,n,m);
    g<<"Ordinea de desfasurare a probei practice este:";
    g<<endl;
    sortare(b,n,m);
    afisare(b,n,m);
    g<<"Pentru cei ce trec de proba practica vom avea un nou tabel cu a treia coloana continand cifra 1,iar ceilalti vor avea 0";
    g<<endl;
    citire(z,n,m);
    for(i=0; i<n; i++)
    {
        if(z[i][2]==1)
            x1++;
    }
    g<<"Procentul de promovabilitate este:"<<(x1*100)/n<<"%";
    return 0;
}
