#include <iostream>
#include <string.h>
#include <string>
#include <iterator>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
#include "inputMatrix.h"
#include "generateRandomSubsetRows.h"
#include "printTheChoosenSubset.h"
#include "allColumnsWithOnesInEveryPositionofRandomRows.h"
#include "allRowswithOnesInCurrentColumnss.h"
#include "sizeOfTheGeneratedCompleteSubmatrixx.h"
#include "allRowswithOnesInCurrentColumnsWeHavee.h"
#include "allColumnswithOnesInCurrentRowss.h"
#include "findMissingRowss.h"
#include "findMissingColumnss.h"
#include "printTheGeneratedInputMatrix.h"
#include "addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompSubMatrixItGens.h"
#include "addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompSubMatrixItGen.h"

using namespace std;

int n;
int **G;
int maxSize;


int hillClimbingAlgorithm(int **G, int n){

    vector<int> randomRows;
    randomRows = generateRandomSubsetOfRowsX();
    printTheChoosenSubsetOfRows(randomRows);

    // find all columns wi 1's in every position of current rows of the matrix
    vector<int> allColumnsWithOnesInEveryPositionOfCurrentRows;
    allColumnsWithOnesInEveryPositionOfCurrentRows = allColumnsWithOnesInEveryPositionX(G, randomRows, n);

    // find all rows with 1's in every position of current columns of the matrix'
    vector<int> allRowsWithOnesInEveryPositionOfCurrentColumns;
    allRowsWithOnesInEveryPositionOfCurrentColumns = allRowswithOnesInCurrentColumnsWeHave(G, allColumnsWithOnesInEveryPositionOfCurrentRows, n);

    // find the size of the generated complete matrix
    int generatedSize = sizeOfTheGeneratedCompleteSubmatrix(allRowsWithOnesInEveryPositionOfCurrentColumns, allColumnsWithOnesInEveryPositionOfCurrentRows, maxSize);
    
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------For every Row thats not already in the current rows we have, we can add it in and find the complete subMatrix it generates----------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  
    // find the missing rows
    vector<int> missingRows;
    missingRows = findMissingRows(allRowsWithOnesInEveryPositionOfCurrentColumns, n);
    

    // add each missing row to the current we have
    if (missingRows.size() == 0){
        if (maxSize <= generatedSize){
            maxSize = generatedSize;
            cout<<"------------Best Size: "<<maxSize<<endl;

        }else{
            cout<<"------------Best Size: "<<maxSize<<endl;

        }
    }else{
       addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrixItGenerates(G, allRowsWithOnesInEveryPositionOfCurrentColumns, missingRows, generatedSize, n, maxSize);
    }
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------For every column thats not already in the current columns we have, we can add it in and find the complete subMatrix it generates----------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


    //find missing columns
    vector<int> missingColumns;
    missingColumns = findMissingColumns(allColumnsWithOnesInEveryPositionOfCurrentRows, n);

    if (missingColumns.size() == 0){
        if (maxSize <= generatedSize){
            maxSize = generatedSize;
            cout<<"------------Best Size: "<<maxSize<<endl;

        }else{
            cout<<"------------Best Size: "<<maxSize<<endl;

        }
    }else{
            addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompleteSubMatrixItGenerates(G, allColumnsWithOnesInEveryPositionOfCurrentRows, missingColumns, generatedSize, n, maxSize);

    }

    // add each missing column to the current we have

}


double calculateTotalRunningTimeForEachIterationHillClimbingAlgorithm(){

}


int main(){
      
    cout<<"Enter n(to generate n x n matrix): ";
    cin >> n;
    G = generateRandom_N_By_N_Binary_Matrix(n);
    printTheMatrix(G, n);

    //Start hillClimbingAlgorith
    
    for (int iter = 0 ; iter < n ; iter++){
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Iter: "<<iter<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        hillClimbingAlgorithm(G, n);
        cout<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"End of Iter: "<<iter<<endl;
        cout<<"----------------------------------------------------------------"<<endl;

      //  break;
    }



    for(int i=0;i < n;i++){
        delete []G[i];
    }

    delete []G;
     


    return 0;
}