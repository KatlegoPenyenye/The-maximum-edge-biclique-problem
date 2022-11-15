#include <iostream>
#include <vector>

using namespace std;

int sizeOfTheGeneratedCompleteSubmatrix(vector<int> rows, vector<int> columns, int maxSize){

    // Keep track of the best successor matrix size 


    if (rows.size() > 1 && columns.size() > 1){
        cout<<"------------The Size of the generated complete submatrix is (or lies on): |Rows : {";
        for(int row = 0 ; row < rows.size() ; row++){
            cout<<rows.at(row)<<",";
        }
        cout<<"}| x |Columns: {";
         for(int col = 0 ; col < columns.size() ; col++){
            cout<<columns.at(col)<<",";
        }
        int size = (rows.size()*columns.size());
     
        cout<<"}| that is: "<<rows.size()<<" x "<<columns.size()<<" = "<<size<<"------------"<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        
      /*if (maxSize <= size){
            maxSize = size;
            cout<<"------------Best Size is: "<<maxSize<<"------------"<<endl;
            return maxSize;
        }else{
            size = maxSize;
            cout<<"------------Best Size is: "<<maxSize<<"------------"<<endl;
            return maxSize;
        }*/
        return size;
        

        
    }else{
          cout<<"------------No complete submatrix can be generated from these rows and columns, Size = 0"<<endl;
      //  cout<<"------------Best Size is: "<<maxSize<<"------------"<<endl;
          return 0;

    }

}