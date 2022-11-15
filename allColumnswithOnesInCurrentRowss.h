#include <iostream>
#include <vector>

using namespace std;

vector<int> allColumnswithOnesInCurrentRows(int **G, vector<int> currentRows, int n){
    vector<int> allColumns;
   
    for (int cools = 0 ; cools < n ; cools++){
        int coutIndex = 0;
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