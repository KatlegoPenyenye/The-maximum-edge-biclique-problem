#include <iostream>
#include <vector>

using namespace std;

vector<int> allColumnsWithOnesInEveryPositionX(int **G, vector<int> randomRows, int n){
    vector<int> columns;

    if (randomRows.size() != 0){
        int i = randomRows.at(0);
        int j = randomRows.at(1);
        for (int cols = 0 ; cols < n ; cols++){
            // all columns with 1s at random rows i, j;
                if (G[i][cols] == 1  && G[j][cols] == 1){
                    columns.push_back(cols);
                }
        }
       
    }
    if (columns.size() > 1 ){
         cout<<"------------Columns = {";
         for(int col = 0 ; col < columns.size() ; col++){
            cout<<columns.at(col)<<",";
        }
        cout<<"} have Ones In Every Position in Our Current Rows------------"<<endl;
    }
    else{
        cout<<"------------No Column have Ones In Every Position of Our current rows"<<endl;

    }
    return columns;
}