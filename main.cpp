#include <algorithm>
#include<vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> matrix;

int calcula_valor(char a, char b){
    if(a==b){
        return 2;
    }else{
        return -1;
    }
}

void printador(matrix H, int n, int m){

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            cout << H[i][j] << "  ";
        }
        cout << endl;
    }
}

matrix Heuristica_SW(matrix H, int n, int m, string a, string b){
    int del, diag, ins, candidato,w;
    


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            w = calcula_valor(a[i],b[j]);
            diag = H[i-1][j-1] + w;
            
            del = H[i-1][j] - 1;

            ins = H[i][j-1] - 1;

            //https://codereview.stackexchange.com/questions/26100/maximum-of-three-values-in-c
            candidato = max({0,diag,del,ins});
            H[i][j] = candidato;
        }
    }
   
    return H;
}


int main(){

    int n, m;    
    string a_OLD, b_OLD;

    cin >> n;
    cin >> m;
    cin >> a_OLD;
    cin >> b_OLD;

    string a = "#" + a_OLD;
    string b = "#" + b_OLD;

     cout << a << endl << b << endl;

    matrix H;
    H.resize(n+1);
    for(int zero = 0; zero <=n; zero++){
        H[zero].resize(m+1);
    }

    H = Heuristica_SW(H,n,m,a,b);
    printador(H,n,m);
    

    cout << "END";
    
    return 0;

}