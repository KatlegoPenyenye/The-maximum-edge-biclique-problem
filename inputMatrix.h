int **generateRandom_N_By_N_Binary_Matrix(int n) {


    int rows=n;
    int cols=n;
    int **arr;

    arr = new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i]=new int[cols];
    }
    // statements
    for(int i = 0 ; i < n  ; i++){
            arr[0][0] = 0;

        for(int j = 0 ; j < n ; j++){
            arr[i][j] = rand() % 2;
        }
    }
    for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < n ; j++){
            if (arr[i][j] == 0 && arr[i][j+1] == 0){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < n ; j++){
         if ((j + 1) < n ){
            if (arr[j][i] == 0 && ((arr[j+1][i] == 0))){
                arr[j][i] = 1;
            }
         }
        }
    }
   /* for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < n ; j++){
            if ((j + 1) < n ){
                if (arr[i][j] == 1){
                  arr[i][j+1] = 0;
            }
            }
            
        }
    }
    for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < n ; j++){
         if ((j + 1) < n ){
            if (arr[j][i] == 1){
                arr[j+1][i] = 0;
            }
         }
        }
    }*/
    for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < n ; j++){
         if ((j + 1) < n ){
            if (arr[j][i] == 0){
                arr[j+1][i] = 1;
            }
         }
        }
    }
    return arr;

}