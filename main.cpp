#include <algorithm>
#include <initializer_list>
#include <iostream>

using namespace std;

// https://slaystudy.com/initialize-2d-array-c-to-zero/
void Print2DArray(int arr[][20], int r, int c){
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			cout<<arr[i][j]<<' ';
		}	
		cout<<endl;
	}
	cout<<endl;
}
int calcula_valor(char a, char b){
    if(a==b){
        return 2;
    }else{
        return -1;
    }
}

vector<vector<int>> Heuristica_SW(int n, int m, string a, string b, int w){
    int del, diag, ins, candidato;
    int H[n][m] = {0};
    

    for(int i = 1; i<=n; i++){
        for(int j; i<=m; i++){
            w = calcula_valor(a[i],b[j]);
            diag = H[i-1][j-1] + w;
            
            del = H[i-1][j] - 1;

            ins = H[i][j-1] - 1;

            //https://codereview.stackexchange.com/questions/26100/maximum-of-three-values-in-c
            candidato = max({0,diag,del,ins});
        }
    }
    Print2DArray(H,n,m); //printando matriz feita
    return H;
}