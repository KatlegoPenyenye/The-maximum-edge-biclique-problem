#include <iostream>
#include <vector>

using namespace std;

void printTheMatrix(int **G, int n){

   

    cout<<"Below is the random generated matrix as described in the problem"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"  ";
    for(int j = 0 ; j < n ; j++){
            string charA = "A"; 
            string intInLoop = to_string(j + 1);
            string destinationVertex = charA + intInLoop;
            cout<< destinationVertex <<" ";
            
    }
    cout<<endl;
    for(int i = 0 ; i < n  ; i++){
        //print x1
        string sourceVertex = to_string(i + 1);
        string stateNames = "x";
        string sname = stateNames + sourceVertex;
        cout<<sname<<" ";
        for(int j = 0 ; j < n ; j++){
            cout<<G[i][j]<<" "<<" ";
        }
        cout<<endl;
        sname = "";
    }
    cout<<endl;
}