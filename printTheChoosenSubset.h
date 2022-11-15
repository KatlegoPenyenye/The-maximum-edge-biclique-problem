#include <iostream>
#include <vector>

using namespace std;

void printTheChoosenSubsetOfRows(vector <int> randomRows){

    if (randomRows.size() != 0){
            cout<<"------------Rows: X = {"<<randomRows.at(0)<<", "<<randomRows.at(1)<<"} are the choosen random subset of rows we start with.------------"<<endl;    
            cout<<"----------------------------------------------------------------"<<endl;  
    }else{
        cout<<"------------No random subset of rows call again:"<<endl;
    }

}