#include <iostream>
#include <vector>

using namespace std;


int addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompleteSubMatrixItGenerates(int **G, vector<int> allColumnsWithOnesInEveryPositionOfCurrentRows, vector<int> missingColumns, int generatedSize, int n, int maxSize){
    vector<int> alcols;

    alcols = allColumnsWithOnesInEveryPositionOfCurrentRows;
    int s = alcols.size();

    if (missingColumns.size() != 0 && s != 0){
        vector<int> allRowsWithOnesInEveryCurrentColumnPosition;
        for(int addColumn = 0; addColumn < missingColumns.size() ; addColumn++){
                //try adding
                int added = missingColumns.at(addColumn);
                allColumnsWithOnesInEveryPositionOfCurrentRows.push_back(added);
                cout<<"------------We add Column: "<<added<<endl;
                cout<<"------------Our Current Columns becomes, Columns: {";
                for(int col = 0 ; col < allColumnsWithOnesInEveryPositionOfCurrentRows.size() ; col++){
                    cout<<allColumnsWithOnesInEveryPositionOfCurrentRows.at(col)<<",";
                }
                cout<<"}------------"<<endl;
                // find all rows with ones in current columns
                allRowsWithOnesInEveryCurrentColumnPosition = allRowswithOnesInCurrentColumns(G, allColumnsWithOnesInEveryPositionOfCurrentRows, n);

                generatedSize = sizeOfTheGeneratedCompleteSubmatrix(allRowsWithOnesInEveryCurrentColumnPosition, allColumnsWithOnesInEveryPositionOfCurrentRows, maxSize);
                allRowsWithOnesInEveryCurrentColumnPosition.clear();

                allColumnsWithOnesInEveryPositionOfCurrentRows.pop_back();
               // break;
                
        }
    }

}