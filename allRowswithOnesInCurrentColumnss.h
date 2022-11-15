#include <iostream>
#include <vector>

using namespace std;
vector<int> allRowswithOnesInCurrentColumns(int **G, vector<int> columns, int n){
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
    if (allRows.size() > 1 ){
         cout<<"------------allRows = {";
         for(int col = 0 ; col < allRows.size() ; col++){
            cout<<allRows.at(col)<<",";
        }
        cout<<"} have Ones In Every Position in Our Current Columns = {";
        for(int col = 0 ; col < columns.size() ; col++){
            cout<<columns.at(col)<<",";
        }
        cout<<"}"<<endl;
    }
    return allRows;
}