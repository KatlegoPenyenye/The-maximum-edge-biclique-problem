#include <iostream>
#include <vector>

using namespace std;


int addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrixItGenerates(int **G, vector<int> allRowsWithOnesInEveryPositionOfCurrentColumns, vector<int> missingRows, int generatedSize, int n, int maxSize){
    
    vector<int> alrows;

    alrows = allRowsWithOnesInEveryPositionOfCurrentColumns;
    int s = alrows.size();
    if (missingRows.size() != 0 && s != 0){
        vector<int> allColumnsWithOnesInEveryMissingRow;
        
        for(int addRow = 0; addRow < missingRows.size() ; addRow++){
                //try adding
                int added = missingRows.at(addRow);
                allRowsWithOnesInEveryPositionOfCurrentColumns.push_back(added);
                cout<<"------------We add row: "<<added<<endl;
                cout<<"------------Our Current Rows becomes, Rows: {";
                for(int row = 0 ; row < allRowsWithOnesInEveryPositionOfCurrentColumns.size() ; row++){
                    cout<<allRowsWithOnesInEveryPositionOfCurrentColumns.at(row)<<",";
                }
                cout<<"}------------"<<endl;
                // find all columns with ones in current rows
                allColumnsWithOnesInEveryMissingRow = allColumnswithOnesInCurrentRows(G, allRowsWithOnesInEveryPositionOfCurrentColumns, n);

                generatedSize = sizeOfTheGeneratedCompleteSubmatrix(allRowsWithOnesInEveryPositionOfCurrentColumns, allColumnsWithOnesInEveryMissingRow, maxSize);
                allColumnsWithOnesInEveryMissingRow.clear();

                allRowsWithOnesInEveryPositionOfCurrentColumns.pop_back();
               // break;
                
        }
    }

}