#include <algorithm>
#include<vector>
#include <iostream>
#include <tuple>

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

tuple<string, string> RouteTracer(matrix Route, int i_max,int j_max, string a, string b){

    int maxValue = Route[i_max][j_max];
    int currentValue = maxValue;
    int current_i = i_max;
    int current_j = j_max;
    string SeqA = "";
    string SeqB = "";

    while(currentValue != 0){

        if(currentValue == 1){

            SeqA += a[current_i];
            SeqB += b[current_j];

            current_i = current_i - 1;
            current_j = current_j - 1;
            currentValue = Route[current_i][current_j];

        } else if(currentValue == 2){

            SeqA += a[current_i];
            SeqB += "-";

            current_i -= 1;
            currentValue = Route[current_i][current_j];

        }else if(currentValue == 3){

            SeqA += "-";
            SeqB += b[current_j];

            current_j -= 1;
            currentValue = Route[current_i][current_j];


        }
    }

    reverse(SeqA.begin(), SeqA.end());
    reverse(SeqB.begin(), SeqB.end());

    return make_tuple(SeqA, SeqB);

}

tuple<matrix, matrix> Heuristica_SW(matrix H, int n, int m, string a, string b, matrix Route){
    int del, diag, ins, candidato,w;
    


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            w = calcula_valor(a[i],b[j]);
            diag = H[i-1][j-1] + w;
            
            del = H[i-1][j] - 1;

            ins = H[i][j-1] - 1;

            candidato = max({0,diag,del,ins});
            H[i][j] = candidato;

            if(H[i][j] == 0 ){

                Route[i][j] = 0;

            } else if(H[i][j] == diag){

                Route[i][j] = 1;

            }else if(H[i][j] == del){

                Route[i][j] = 2;

            }else if(H[i][j] == ins){

                Route[i][j] = 3;
            }
        }
    }
   
    return make_tuple(H, Route);
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

    // Criação da moldura
    string a = "#" + a_OLD;
    string b = "#" + b_OLD;

     cout << a << endl << b << endl;

  
    // Matrix Init
    matrix H;
    H.resize(n+1);
    for(int zero = 0; zero <=n; zero++){
        H[zero].resize(m+1);
    }

    matrix Route;
    Route.resize(n+1);
    for(int zero = 0; zero <=n; zero++){

        Route[zero].resize(m+1);
    }
  

    tie(H, Route) = Heuristica_SW(H,n,m,a,b, Route);
    printador(H,n,m);
    cout << "" << endl;
    cout << "Matrix Route" << endl;
    printador(Route,n,m);
    
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

    string SeqA,SeqB;

	tie(SeqA,SeqB) = RouteTracer(Route,i_max,j_max,a,b);

    cout << "SeqA: " << SeqA << endl;
    cout << "SeqB: " << SeqB << endl;
    cout << "EOF";
    
    return 0;

}

// Referências:
// [1] - http://web.tecnico.ulisboa.pt/ana.freitas/bioinformatics.ath.cx/bioinformatics.ath.cx/index2568.html?id=49#:~:text=Alinhamento%20Local%20%2D%20Smith%2DWaterman,em%20todo%20o%20seu%20comprimento
// [2] - https://github.com/ngopal/SimpleSmithWatermanCPP/blob/master/SmithWaterman.cpp
// [3] - //https://codereview.stackexchange.com/questions/26100/maximum-of-three-values-in-c
// [4] - https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
