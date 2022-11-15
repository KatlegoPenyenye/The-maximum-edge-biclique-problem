#include <iostream>
#include <vector>

using namespace std;


int addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrix(int **G, vector<int> allRowsWithOnesInEveryPositionOfCurrentColumns, int missingRow, int generatedSize, int n, int maxSize){
    
    
        vector<int> allColumnsWithOnesInEveryMissingRow;
        
    
        //try adding
        int added = missingRow;
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
        return generatedSize;
        // break;
                
        
    

}