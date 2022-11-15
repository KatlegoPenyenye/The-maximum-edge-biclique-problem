#include <iostream>
#include <vector>

using namespace std;


vector<int> findMissingColumns(vector<int> currentColumns, int n){
    vector<int> missColumns;
    for (int missCol = 0 ; missCol < n ; missCol++){
        int miss = 0;
        for (int rs = 0 ; rs < currentColumns.size() ; rs++){
            if (missCol != currentColumns.at(rs)){
                miss+=1;
            }
        }
        if (miss >= currentColumns.size()){
            missColumns.push_back(missCol);
        }
    }
    if (missColumns.size() > 1 && currentColumns.size() > 1){
        cout<<"------------Columns: {";
        for (int row = 0 ; row < missColumns.size() ; row++){
            cout<<missColumns.at(row)<<",";
        }
        cout<<"} are not already in our current Columns: {";
        for (int row = 0 ; row < currentColumns.size() ; row++){
            cout<<currentColumns.at(row)<<",";
        }
        cout<<"}------------"<<endl;
        return missColumns;
    }else{
        cout<<"------------No Column thats not already in Columns"<<endl;
        return missColumns;
    }
    

}