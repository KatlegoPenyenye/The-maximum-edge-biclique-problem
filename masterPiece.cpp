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

using namespace std;

int n;
int **G;


// Random subset of rows:
vector<int> generateRandomSubsetOfRowsX(){
    vector<int> randomRows;
    int i = rand() % 4;
    int j = rand() % 3;
    randomRows.push_back(i);
    randomRows.push_back(j);
    return randomRows;
}
// Print thr random subset of rows:
void printTheChoosenSubsetOfRows(vector <int> randomRows){

    if (randomRows.size() != 0){
            cout<<"------------Rows: X = {"<<randomRows.at(0)<<", "<<randomRows.at(1)<<"} are the choosen random subset of rows we start with.------------"<<endl;    
            cout<<"----------------------------------------------------------------"<<endl;  
    }else{
        cout<<"------------No random subset of rows call again:"<<endl;
    }

}

// All columns with 1s in every position in X (random subset of rows)
vector<int> allColumnsWithOnesInEveryPositionX(vector<int> randomRows){
    //vector<int> crandomRows;
    vector<int> columns;
    int i = randomRows.at(0);
    int j = randomRows.at(1);
    for (int cols = 0 ; cols < n ; cols++){
        // all columns with 1s at random rows i, j;
            if (G[i][cols] == 1  && G[j][cols] == 1){
                columns.push_back(cols);
            }
    }

    return columns;
}

// 2. Print all Columns With Ones In Every Position X
void printallColumnsWithOnesInEveryPositionX(vector<int> columns){
    
    if (columns.size() != 0){
        cout<<"------------Columns = {";
         for(int col = 0 ; col < columns.size() ; col++){
            cout<<columns.at(col)<<",";
        }
        cout<<"} have Ones In Every Position in X------------"<<endl;
    }else{
        cout<<"------------No Column have Ones In Every Position in X call again"<<endl;
    }
}

//All rows with 1s in every position in ( All columns with 1s in every position in X (random subset of rows) )
vector<int> allRowswithOnesInCurrentColumns(vector<int> columns){
    vector<int> allRows;
    for (int roows = 0 ; roows < n ; roows++){
            int coutIndex = 0;
            for (int r = 0 ; r < columns.size() ; r++){

                if (G[roows][columns.at(r)] == 1){
                    coutIndex+=1;
                }
                
            }
            if (coutIndex == columns.size()){
                allRows.push_back(roows);
            }
    }
    return allRows;
}
// 2. Print All rows with 1s in every position in ( All columns with 1s in every position in X (random subset of rows) )
void printallRowswithOnesInCurrentColumns(vector<int> rows){
    
    if (rows.size() != 0){
        int count = 0;
        cout<<"------------Rows = {";
         for(int row = 0 ; row < rows.size() ; row++){
            cout<<rows.at(row)<<",";
            count+=1;
        }
        cout<<"} (Have / Do not have) Ones In Every Position in the Current Columns ( All columns with 1s in every position in X (random subset of rows))------------"<<endl;
    }else{
        cout<<"------------No Column with Ones In Every Position in X call again"<<endl;
    }
}

// 2.Find the size of the generated complete submatrix
int sizeOfTheGeneratedCompleteSubmatrix(vector<int> rows, vector<int> columns){

    if (rows.size() != 0 && columns.size() != 0){
        cout<<"------------The size of the generated complete submatrix is the product of the lengths: |Rows : {";
        for(int row = 0 ; row < rows.size() ; row++){
            cout<<rows.at(row)<<",";
        }
        cout<<"}| x |Columns: {";
         for(int col = 0 ; col < columns.size() ; col++){
            cout<<columns.at(col)<<",";
        }
        int size = (rows.size()*columns.size());
        cout<<"}| that is: "<<rows.size()<<" x "<<columns.size()<<" = "<<size<<"------------"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        return size;
    }else{
        cout<<"------------No generated complete submatrix: "<<endl;
        return 0;
    }
}

// show complete submat generated
void printGeneratedCompleteSubMatrix(vector<int> rows, vector<int> columns){
    
    if (rows.size() != 0 && columns.size() != 0){

        cout<<"------------The Generated complete submatrix is on Rows : {";
        for(int row = 0 ; row < rows.size() ; row++){
            cout<<rows.at(row)<<",";
        }
        cout<<"} and Columns: {";
         for(int col = 0 ; col < columns.size() ; col++){
            cout<<columns.at(col)<<",";
        }
        cout<<"}------------"<<endl;

    }else{
        cout<<"------------No Complete sub matrix can be generated."<<endl;
    }

}

vector<int> missingRows(vector<int> allRows){

    vector<int> missRows;
    for (int missingRows = 0 ; missingRows < n ; missingRows++){
        int miss = 0;
        for (int rs = 0 ; rs < allRows.size() ; rs++){
            if (missingRows != allRows.at(rs)){
                miss+=1;
            }
        }
        if (miss >= allRows.size()){
            missRows.push_back(missingRows);
        }
    }
    return missRows;
}
vector<int> missingColumns(vector<int> columns){

    vector<int> missCols;
    for (int missingCols = 0 ; missingCols < n ; missingCols++){
        int miss = 0;
        for (int rs = 0 ; rs < columns.size() ; rs++){
            if (missingCols != columns.at(rs)){
                miss+=1;
            }
        }
        if (miss == columns.size()){
            missCols.push_back(missingCols);
        }
    }
    return missCols;
}
void printmissingColumns(vector<int> missingColumns, vector<int> allColumns){
    if (missingColumns.size() != 0 && allColumns.size() != 0){
        cout<<"------------Columns: {";
        for (int Column = 0 ; Column < missingColumns.size() ; Column++){
            cout<<missingColumns.at(Column)<<",";
        }
        cout<<"} are not already in current Columns: {";
        for (int Column = 0 ; Column < allColumns.size() ; Column++){
            cout<<allColumns.at(Column)<<",";
        }
        cout<<"}-----------"<<endl;
    }else{
        cout<<"------------No Column thats not already in Columns"<<endl;
    }
}
void printmissingRows(vector<int> missingRows, vector<int> allRows){
    if (missingRows.size() != 0 && allRows.size() != 0){
        cout<<"------------Rows: {";
        for (int row = 0 ; row < missingRows.size() ; row++){
            cout<<missingRows.at(row)<<",";
        }
        cout<<"} are not already in current Rows: {";
        for (int row = 0 ; row < allRows.size() ; row++){
            cout<<allRows.at(row)<<",";
        }
        cout<<"}-----------"<<endl;
    }else{
        cout<<"------------No row thats not already in Rows"<<endl;
    }
}
//All Columns with 1s in every position in Current rows
vector<int> allColumnswithOnesInCurrentRows(vector<int> currentRows){
    vector<int> allColumns;
   
    int coutIndex = 0;
    for (int cools = 0 ; cools < n ; cools++){
        for (int r = 0 ; r < currentRows.size() ; r++){
            if (G[currentRows.at(r)][cools] == 1){
                coutIndex+=1;
            }
        }
        if (coutIndex == currentRows.size()){
            allColumns.push_back(cools);
        }
    }
    return allColumns;
}

int addEachoFtheseMissingRowsToTheCurrentRowsWeHaveAndFindTheCompleteSubMatrixItGenerates(vector<int> missRows, vector<int> allRows){

    vector<int> allColumns;
    int sizeGenerated;

    if (missRows.size() != 0 && allRows.size() != 0){
        for(int addRow = 0 ; addRow < missRows.size() ; addRow++){
            //try adding
            int added = missRows.at(addRow);
            allRows.push_back(added);
            cout<<"------------We add row: "<<added<<endl;
            cout<<"------------Our Current Rows becomes Rows: {";
            for(int row = 0 ; row < allRows.size() ; row++){
                cout<<allRows.at(row)<<",";
            }
            cout<<"}"<<endl;
            // Finda all columns with 1s in every position in Current Rows we have:
            allColumns = allColumnswithOnesInCurrentRows(allRows);
            // print these columns
            if (allColumns.size() != 0){
                printGeneratedCompleteSubMatrix(allRows, allColumns);
                //2. Find the size of the generated complete submatrix
                int sizeGenerated = sizeOfTheGeneratedCompleteSubmatrix(allRows, allColumns);

            }else{
                cout<<"------------No Columns with Ones In Every Position in current rows we have"<<endl;
                cout<<"------------Size is: 0"<<endl;
            }
            allRows.pop_back();
            
        }

    }else{
        cout<<"------------No Missing rows in the current rows we have"<<endl;
        cout<<"------------Size is: 0"<<endl;
    }

}
int addEachoFtheseMissingColumnsToTheCurrentColumnsWeHaveAndFindTheCompleteSubMatrixItGenerates(vector<int> missColumns, vector<int> allColumns){

    vector<int> allRows;
    int sizeGenerated;

    if (missColumns.size() != 0 && allColumns.size() != 0){
        for(int addColumn = 0 ; addColumn < missColumns.size() ; addColumn++){
            //try adding
            int added = missColumns.at(addColumn);
            allColumns.push_back(added);
            cout<<"------------We add Column: "<<added<<endl;
            cout<<"------------Our Current Columns becomes Columns: {";
            for(int Column = 0 ; Column < allColumns.size() ; Column++){
                cout<<allColumns.at(Column)<<",";
            }
            cout<<"}"<<endl;
            // Finda all rows with 1s in every position in Current Columns we have:
            allRows = allRowswithOnesInCurrentColumns(allColumns);
            // print these columns
            if (allRows.size() != 0){
                printGeneratedCompleteSubMatrix(allRows, allColumns);
                //2. Find the size of the generated complete submatrix
                int sizeGenerated = sizeOfTheGeneratedCompleteSubmatrix(allRows, allColumns);

            }else{
                cout<<"------------No Rows with Ones In Every Position in current Columns we have"<<endl;
                cout<<"------------Size is: 0"<<endl;
            }
            allColumns.pop_back();
            
        }

    }else{
        cout<<"------------No Missing Columns in the current Columns we have"<<endl;
        cout<<"------------Size is: 0"<<endl;
    }

}

// Hiill Climber
void hillClimbingAlgorithm(){
        
        vector<int> randomSubsetOfRows;
        vector<int> allRows;
        vector<int> cols;
        vector<int> missRows;
        vector<int> missCols;
        int sizeOf;

        //1. Generate rand subset of rows X
        cout<<"------------1. Start with a random subset of rows X------------"<<endl;

        randomSubsetOfRows = generateRandomSubsetOfRowsX();

        //2. Print the choosen random subset of rows:
        printTheChoosenSubsetOfRows(randomSubsetOfRows);

        cout<<"------------2. Find All columns with 1s in every position in X, and rows with 1s in every position in these columns to get the complete sub matrix generated and its size.------------"<<endl;


        //2. Find All columns with 1s in every position in X (random subset of rows) to get a complete submatrix and the its size
        cols = allColumnsWithOnesInEveryPositionX(randomSubsetOfRows);
        //2. Print All columns with 1s in every position in X (random subset of rows) to get a complete submatrix and the its size

        printallColumnsWithOnesInEveryPositionX(cols);

        //2. Find All rows with 1s in every position in ( All columns with 1s in every position in X (random subset of rows) )
        allRows = allRowswithOnesInCurrentColumns(cols);

        //2. Print All rows with 1s in every position in ( All columns with 1s in every position in X (random subset of rows) )
        printallRowswithOnesInCurrentColumns(allRows);

        //2. Print the Complete submatrix generated from rows and cols
        printGeneratedCompleteSubMatrix(allRows, cols);

        //2. Find the size of the generated complete submatrix
        sizeOf = sizeOfTheGeneratedCompleteSubmatrix(allRows, cols);


        cout<<"------------3. Now for every Row thats not already in the current rows we have, we can add it in and find the complete subMatrix it generates-----------"<<endl;

        //3. lets Find these missing rows:
        missRows = missingRows(allRows);
        //3. Print the missing rows
        printmissingRows(missRows, allRows);

        //3. Lets add each of these missing rows to the current rows we have and find the complete subMatrix it generates:
        addEachoFtheseMissingRowsToTheCurrentRowsWeHaveAndFindTheCompleteSubMatrixItGenerates(missRows, allRows);

        cout<<"------------4. For every Column thats not already in the current columns we have, we can add it in and find the complete subMatrix it generates-----------"<<endl;

        //4. lets Find these missing columns:
        missCols = missingColumns(cols);
        //4. Print the missing columns:
        printmissingColumns(missCols, cols);

        //4. Lets add each of these missing columns to the current columns we have and find the complete subMatrix it generates:
        addEachoFtheseMissingColumnsToTheCurrentColumnsWeHaveAndFindTheCompleteSubMatrixItGenerates(missCols, cols);

        randomSubsetOfRows.clear();
        missRows.clear();
        missCols.clear();
        cols.clear();
        allRows.clear();

}

int main(){
    
    int rows;
    int cols;
    string sname;
    string destinationVertex, sourceVertex, vertexToDelete;

    cout<<"Enter n(to generate n x n matrix): ";
    cin >> n;

    G = generateRandom_N_By_N_Binary_Matrix(n);

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


    for (int rows = 0 ; rows < 3 ; rows++){
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Iter: "<<rows<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        hillClimbingAlgorithm();
        cout<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"End of Iter: "<<rows<<endl;
        cout<<"----------------------------------------------------------------"<<endl;

      //  break;
    }
    

    
    for(int i=0;i < n;i++){
        delete []G[i];
     }

    delete []G;
     
    return 0;
}