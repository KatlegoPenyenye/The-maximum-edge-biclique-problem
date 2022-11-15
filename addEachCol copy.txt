#include <iostream>
#include <vector>

using namespace std;


int addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompleteSubMatrix(int **G, vector<int> allColumnsWithOnesInEveryPositionOfCurrentRows, int missingColumn, int generatedSize, int n, int maxSize){

                vector<int> allRowsWithOnesInEveryCurrentColumnPosition;
                //try adding
                int added = missingColumn;
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
                return generatedSize;
               // break;
                
 
}