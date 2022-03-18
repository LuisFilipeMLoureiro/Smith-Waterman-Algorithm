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

vector<int> findMax_matrix(matrix H, int n, int m){
	
    vector<int> result;
    int matrix_max = 0;
	int i_max=0, j_max=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
            cout << "valores: " << H[i][j] << endl;
			if(H[i][j]>matrix_max)
			{
				matrix_max = H[i][j];
				i_max=i;
				j_max=j;
			}
		}
	}
    result.push_back(matrix_max);
    result.push_back(i_max);
    result.push_back(j_max);
    return result;
        
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

            candidato = max({0,diag,del,ins});
            H[i][j] = candidato;
        }
    }
   
    return H;
}


int main(){

    int n, m;    
    string a_OLD, b_OLD;

    cout << "Size Sequence A" << endl;
    cin >> n;
    cout << "Size Sequence B" << endl;
    cin >> m;
    cout << "Sequence A" << endl;
    cin >> a_OLD;
    cout << "Sequence B" << endl;
    cin >> b_OLD;

    cout << "You typed in " << endl << a_OLD << endl << b_OLD << endl;

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
    
    int matrix_max,i_max, j_max;
    
    vector<int>  MAXs;
    MAXs = findMax_matrix( H, n, m);

    matrix_max = MAXs[0];
    i_max = MAXs[1];
    j_max = MAXs[2];

    cout << "" << endl;
    cout << "Score: " << matrix_max << endl;
    cout << "" << endl;
    cout << "i max: " << i_max << endl;
    cout << "" << endl;
    cout << "j max: " << j_max << endl;

	
    cout << "EOF";
    
    return 0;

}

// Referências:
// [1] - http://web.tecnico.ulisboa.pt/ana.freitas/bioinformatics.ath.cx/bioinformatics.ath.cx/index2568.html?id=49#:~:text=Alinhamento%20Local%20%2D%20Smith%2DWaterman,em%20todo%20o%20seu%20comprimento
// [2] - https://github.com/ngopal/SimpleSmithWatermanCPP/blob/master/SmithWaterman.cpp
// [3] - //https://codereview.stackexchange.com/questions/26100/maximum-of-three-values-in-c
