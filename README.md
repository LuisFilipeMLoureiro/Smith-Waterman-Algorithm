# Smith-Waterman-Algorithm

## Autores: Luís Filipe Loureiro e Murilo Lima


A Heurística de Alinhamento Local de Smith-Waterman tem como objetivo maximizar o alinhamento entre duas sequências (inputs). Para tanto, definimos como padrão
de score um 2 quando as letra é correspondente e -1 quando há mismatch ou gap.

A construção da matriz foi feita seguindo seu algoritmo, de acordo com o pseudo-código:

`Calcular diagonal = H[i-1,j-1] + w(a[i],b[j]), onde w(a[i],b[j])=2 se houve match, 
                           w(a[i],b[j])= -1 se houve mismatch e  
                           w(a[i],b[j])= -1 se houve gap`
                           
 No mesmo `for` que construímos a matriz Smith-Waterman, nós também realizamos a construção de uma segunda Matriz, a `Route`. Ela tem como objetivo mapear as direções realizadas
 de acordo com qual valor a matriz original recebeu. Ou seja:
 
 | Valor na Matriz SW  | Valor na Matriz Route |
| ------------- | ------------- |
| 0  | 0 |
| diagonal  | 1  |
| deleção | 2  |
| inserção  | 3  |

Com a `Route` construída, foi realizado a identificação do valor máximo na Matriz SW e sua respectiva posição. A partir dele, foi seguido o caminho que maximizava alinhamento,- de acordo com os valores na `Route` - retornando 
as sequências como output.
