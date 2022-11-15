#include <iostream>
#include <vector>

using namespace std;


vector<int> findMissingRows(vector<int> currentRows, int n){
    vector<int> missRows;
    for (int missingRows = 0 ; missingRows < n ; missingRows++){
        int miss = 0;
        for (int rs = 0 ; rs < currentRows.size() ; rs++){
            if (missingRows != currentRows.at(rs)){
                miss+=1;
            }
        }
        if (miss >= currentRows.size()){
            missRows.push_back(missingRows);
        }
    }
    if (missRows.size() > 1 && currentRows.size() > 1){
        cout<<"------------Rows: {";
        for (int row = 0 ; row < missRows.size() ; row++){
            cout<<missRows.at(row)<<",";
        }
        cout<<"} are not already in our current Rows: {";
        for (int row = 0 ; row < currentRows.size() ; row++){
            cout<<currentRows.at(row)<<",";
        }
        cout<<"}------------"<<endl;
        return missRows;
    }else{
        cout<<"------------No row thats not already in Rows"<<endl;
        return missRows;
    }
    

}