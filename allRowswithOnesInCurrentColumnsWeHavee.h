#include <iostream>
#include <vector>

using namespace std;

vector<int> allRowswithOnesInCurrentColumnsWeHave(int **G,vector<int> columns, int n){
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