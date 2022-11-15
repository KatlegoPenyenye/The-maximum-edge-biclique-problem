#include <iostream>
#include <string.h>
#include <string>
#include <iterator>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
#include "inputMatrix.h"
#include "generateRandomSubsetRows.h"
#include "printTheChoosenSubset.h"
#include "allColumnsWithOnesInEveryPositionofRandomRows.h"
#include "allRowswithOnesInCurrentColumnss.h"
#include "sizeOfTheGeneratedCompleteSubmatrixx.h"
#include "allRowswithOnesInCurrentColumnsWeHavee.h"
#include "allColumnswithOnesInCurrentRowss.h"
#include "findMissingRowss.h"
#include "findMissingColumnss.h"
#include "printTheGeneratedInputMatrix.h"
#include "addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompSubMatrixItGens.h"
#include "addEachRow.h"
#include "addEachCol.h"
#include "addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompSubMatrixItGen.h"
#include <cmath>
#include <ctime>
#include <fstream>


using namespace std;

int n;
int **G;
int maxSize;

// The hill Climbing Algorithm Implementation:


int hillClimbingAlgorithm(int **G, int n){
    

    int bestSize = 0;
    vector<int> randomRows;
    randomRows = generateRandomSubsetOfRowsX();
    printTheChoosenSubsetOfRows(randomRows);

    // find all columns wi 1's in every position of current rows of the matrix
    vector<int> allColumnsWithOnesInEveryPositionOfCurrentRows;
    allColumnsWithOnesInEveryPositionOfCurrentRows = allColumnsWithOnesInEveryPositionX(G, randomRows, n);

    // find all rows with 1's in every position of current columns of the matrix'
    vector<int> allRowsWithOnesInEveryPositionOfCurrentColumns;
    allRowsWithOnesInEveryPositionOfCurrentColumns = allRowswithOnesInCurrentColumnsWeHave(G, allColumnsWithOnesInEveryPositionOfCurrentRows, n);

    // find the size of the generated complete matrix
    int generatedSize = sizeOfTheGeneratedCompleteSubmatrix(allRowsWithOnesInEveryPositionOfCurrentColumns, allColumnsWithOnesInEveryPositionOfCurrentRows, maxSize);
    cout<<"------------Best Size is: "<<generatedSize<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------For every Row thats not already in the current rows we have, we can add it in and find the complete subMatrix it generates----------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  
    // find the missing rows
    vector<int> missingRows;
    missingRows = findMissingRows(allRowsWithOnesInEveryPositionOfCurrentColumns, n);

   // addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrixItGenerates(G, allRowsWithOnesInEveryPositionOfCurrentColumns, missingRows, generatedSize, n, maxSize);
    
    bestSize = generatedSize;
    for (int i = 0; i < missingRows.size(); i++){
        int sizeGenerated = addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrix(G, allRowsWithOnesInEveryPositionOfCurrentColumns, missingRows.at(i), generatedSize, n, maxSize);
        if (sizeGenerated <= bestSize){
            sizeGenerated = bestSize;
            cout<<"------------Best Size is: "<<bestSize<<endl;

            return bestSize;


        }else{
            bestSize = sizeGenerated;
            cout<<"------------Best Size is: "<<bestSize<<endl;
        }
    }



    
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------For every column thats not already in the current columns we have, we can add it in and find the complete subMatrix it generates----------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


    //find missing columns
    vector<int> missingColumns;
    missingColumns = findMissingColumns(allColumnsWithOnesInEveryPositionOfCurrentRows, n);

    for (int i = 0; i < missingColumns.size(); i++){
        int sizeGenerated = addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompleteSubMatrix(G, allColumnsWithOnesInEveryPositionOfCurrentRows, missingColumns.at(i), generatedSize, n, maxSize);
        if (sizeGenerated <= bestSize){
            sizeGenerated = bestSize;
            cout<<"------------Best Size is: "<<bestSize<<endl;

            return bestSize;


        }else{
            bestSize = sizeGenerated;
            cout<<"------------Best Size is: "<<bestSize<<endl;
        }
    }

    //return bestSize;

}


// The Simmulated Annealing Algorithm Implementation:

int simmulaedAnnealing(int **G, int n){
    
    int bestSize = 0;
    vector<int> randomRows;
    randomRows = generateRandomSubsetOfRowsX();
    printTheChoosenSubsetOfRows(randomRows);

    // find all columns wi 1's in every position of current rows of the matrix
    vector<int> allColumnsWithOnesInEveryPositionOfCurrentRows;
    allColumnsWithOnesInEveryPositionOfCurrentRows = allColumnsWithOnesInEveryPositionX(G, randomRows, n);

    // find all rows with 1's in every position of current columns of the matrix'
    vector<int> allRowsWithOnesInEveryPositionOfCurrentColumns;
    allRowsWithOnesInEveryPositionOfCurrentColumns = allRowswithOnesInCurrentColumnsWeHave(G, allColumnsWithOnesInEveryPositionOfCurrentRows, n);

    // find the size of the generated complete matrix
    int generatedSize = sizeOfTheGeneratedCompleteSubmatrix(allRowsWithOnesInEveryPositionOfCurrentColumns, allColumnsWithOnesInEveryPositionOfCurrentRows, maxSize);
    cout<<"------------Best Size is: "<<generatedSize<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------For every Row thats not already in the current rows we have, we can add it in and find the complete subMatrix it generates----------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  
    // find the missing rows
    vector<int> missingRows;
    missingRows = findMissingRows(allRowsWithOnesInEveryPositionOfCurrentColumns, n);

   // addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrixItGenerates(G, allRowsWithOnesInEveryPositionOfCurrentColumns, missingRows, generatedSize, n, maxSize);
    
    bestSize = generatedSize;
    int T = missingRows.size();
   // double probability = 0.0;
    for (int i = 0; i < missingRows.size(); i++){

        if (T == 0){
           // return bestSize;
           //bestSize = bestSize;
           return bestSize;
        }

        int sizeGenerated = addEachOfTheseMissingRowsToCurrentRowsAndFindTheCompleteSubMatrix(G, allRowsWithOnesInEveryPositionOfCurrentColumns, missingRows.at(i), generatedSize, n, maxSize);
        int stateChange = sizeGenerated - bestSize;

        if (stateChange > 0){
            bestSize = sizeGenerated;
            cout<<"------------Best Size is: "<<bestSize<<endl;

        }else{
            // with probability exp((∆E/T))
            double probability = exp((stateChange/T));

            // random number generator between 0 and 1
            //possibility of moving to a state with a lower value
            if (probability > ((double)rand()/(double)RAND_MAX)){
                bestSize = sizeGenerated;
                cout<<"------------Best Size is: "<<bestSize<<endl;

            }//the else below is unnecessary
            else{
               // bestSize = sizeGenerated;
                cout<<"------------Best Size is: "<<bestSize<<endl;
                return bestSize;
            }
        }
        //decrease T according to the temperature schedule.
        //The temperature schedule is some sort of function the determines the rate at which the temperature decreases.
        T = (T - i);
    }



    
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------For every column thats not already in the current columns we have, we can add it in and find the complete subMatrix it generates----------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


    //find missing columns
    vector<int> missingColumns;
    missingColumns = findMissingColumns(allColumnsWithOnesInEveryPositionOfCurrentRows, n);
    int TT = missingColumns.size();
    // double probabiliTy = 0.0;
    for (int i = 0; i < missingColumns.size(); i++){

        if (TT == 0){
           // return bestSize;
           //bestSize = bestSize;
           return bestSize;
        }

        int sizeGenerated = addEachOfTheseMissingColumnsToCurrentColumnsAndFindTheCompleteSubMatrix(G, allColumnsWithOnesInEveryPositionOfCurrentRows, missingColumns.at(i), generatedSize, n, maxSize);
        int stateChange = sizeGenerated - bestSize;

        if (stateChange > 0){
            bestSize = sizeGenerated;
            cout<<"------------Best Size is: "<<bestSize<<endl;

        }else{
            // with probability exp((∆E/T))
            double probabilityy = exp((stateChange/TT));

            // random number generator between 0 and 1
            //possibility of moving to a state with a lower value
            if (probabilityy > ((double)rand()/(double)RAND_MAX)){
                bestSize = sizeGenerated;
                cout<<"------------Best Size is: "<<bestSize<<endl;

            }//the else below is unnecessary
            else{
              //  bestSize = sizeGenerated;
                cout<<"------------Best Size is: "<<bestSize<<endl;
                return bestSize;
            }
        }
        //decrease T according to the temperature schedule.
        //The temperature schedule is some sort of function the determines the rate at which the temperature decreases.
        TT = (TT - i);
    }

   //return bestSize;

}


/*void calculateTotalRunningTimeForEachIterationHillClimbingAlgorithm(){

    clock_t startTime;
    clock_t endTime;
    float totalRunningTime;
    float averageRunningTime;
    float runTimeInMilliseconds;

    int bestSize;

    ofstream myFile;
    myFile.open("Hill-Climbing-Algorithm Runtime-results.csv"); // Create file

    myFile << "Iteration" << "," << " Best-Size, " << "Total-runtime"<<endl; 


    
    for (int iter = 0 ; iter < n ; iter++){

        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Iter: "<<iter<<endl;
        cout<<"----------------------------------------------------------------"<<endl;


        startTime = clock();
        bestSize = hillClimbingAlgorithm(G, n);
        endTime = clock();
        totalRunningTime = ((endTime) - (startTime));

        
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"End of Iter: "<<iter<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        // n averageRunningTimes
        averageRunningTime = (totalRunningTime/CLOCKS_PER_SEC);
       // runTimeInMilliseconds = (averageRunningTime * 1000);
        cout<<"Total run-time(in ms) for iter: "<<iter<<" is: "<<(averageRunningTime)<<", and the, Best Size Found is: "<<bestSize<<endl;
        myFile << iter << ", " << bestSize << ", " << averageRunningTime << endl;
        //return averageRunningTime;
    }
    myFile.close();
}*/
void generateHillClimbingVsSimmulatedAnnealingOverallRuntimeResults(int **inputMatrix, int Size){

    clock_t startTime_HA;
    clock_t startTime_SA;
    clock_t endTime_HA;
    clock_t endTime_SA;
    float totalRunningTime_SA;
    float totalRunningTime_HA;
    float total_running_time_sa;
    float total_running_time_ha;
    float total_running_time_difference;
    float total_average_running_time_difference;
    float averageRunningTime_HA;
    float averageRunningTime_SA;
    float total_average_running_time_sa;
    float total_average_running_time_ha;
    float runTimeInMilliseconds;

    int bestSize_HA = 0;
    int bestSize_SA = 0;

    ofstream myFile;
    myFile.open("Hill-Climbing-vs-Simmulated-Annealing-Algorithm-Average-runtime-results.csv"); // Create file

    myFile << "Iteration" << ", "<<"Input-matrix-size" << ", " << "Best-size-produced-by-the-hillClimbing-algorithm" <<", "<<"Best-size-produced-by-the-simmulatedAnnealing-algorithm" <<", "<<"Average-runtime-by-the-hillClimbing-algorithm"<<", "<< "Average-runtime-by-the-simmulatedAnnealing-algorithm"<<", "<<"Absolute-Total-Difference-in-average-runtimes-by-both-algorithms"<<endl;

    // 10 DATA points
    ofstream myFile2;
    ofstream myFile3;
    myFile3.open("Hill-Climbing-vs-Simmulated-Annealing-Algorithm-runtime-results-for-each-Input-size-of-the-matrix.csv");
    myFile3 << "Iteration" << ", "<<"Input-matrix-size" << ", " << "Best-size-produced-by-the-hillClimbing-algorithm" <<", "<<"Best-size-produced-by-the-simmulatedAnnealing-algorithm" <<", "<<"Total-runtime-by-the-hillClimbing-algorithm"<<", "<< "Total-runtime-by-the-simmulatedAnnealing-algorithm"<<", "<<"Absolute-Difference-in-total-runtimes-by-both-algorithms"<<endl;

    int iterr = 0;
    for (int size = Size; size < 1000 + 1; size = size + 100){
        //inputMatrix and update
        
        string charA = "Hill-Climbing-vs-Simmulated-Annealing-Algorithm-runtime-results-for-Input-size";

        string intInLoop = to_string(size);
        string fileName = charA + intInLoop + "x" + intInLoop + ".csv";

        myFile2.open(fileName); // Create file

        myFile2 << "Iteration" << ", "<<"Input-matrix-size" << ", " << "Best-size-produced-by-the-hillClimbing-algorithm" <<", "<<"Best-size-produced-by-the-simmulatedAnnealing-algorithm" <<", "<<"Total-runtime-by-the-hillClimbing-algorithm"<<", "<< "Total-runtime-by-the-simmulatedAnnealing-algorithm"<<", "<<"Absolute-Difference-in-total-runtimes-by-both-algorithms"<<endl;

        inputMatrix = generateRandom_N_By_N_Binary_Matrix(size);
        // 100 iters over same inputMatrix size
        for (int iter = 0 ; iter < 100 + 1; iter++){

                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"Iter: "<<iter<<endl;
                cout<<"----------------------------------------------------------------"<<endl;


                startTime_HA = clock();
                bestSize_HA = hillClimbingAlgorithm(inputMatrix, size);
                endTime_HA = clock();
                totalRunningTime_HA = ((endTime_HA) - (startTime_HA));

                total_running_time_ha = (totalRunningTime_HA/CLOCKS_PER_SEC);


                averageRunningTime_HA += total_running_time_ha;



                startTime_SA = clock();
                bestSize_SA = simmulaedAnnealing(inputMatrix, size);
                endTime_SA = clock();

                totalRunningTime_SA = ((endTime_SA) - (startTime_SA));


                total_running_time_sa = (totalRunningTime_SA/CLOCKS_PER_SEC);
                
                averageRunningTime_SA += total_running_time_sa;

                total_running_time_difference = abs(total_running_time_sa - total_running_time_ha);
                
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"End of Iter: "<<iter<<endl;
                cout<<"----------------------------------------------------------------"<<endl;


                
                myFile2 << iter << ", " <<size*size<<", "<<bestSize_HA <<", "<<bestSize_SA<<", " << total_running_time_ha << ", " << total_running_time_sa<<", "<<total_running_time_difference<<endl;
                myFile3 << iter << ", " <<size*size<<", "<<bestSize_HA <<", "<<bestSize_SA<<", " << total_running_time_ha << ", " << total_running_time_sa<<", "<<total_running_time_difference<<endl;


                totalRunningTime_SA = 0;
                totalRunningTime_HA = 0;
                total_running_time_sa = 0;
                total_running_time_ha = 0;
                total_average_running_time_difference = 0;
                // n averageRunningTimes
            
            // runTimeInMilliseconds = (averageRunningTime * 1000);
                //return averageRunningTime;
            }
            myFile2.close();
            total_average_running_time_sa = averageRunningTime_SA/15;
            total_average_running_time_ha = averageRunningTime_HA/15;
            total_average_running_time_difference = abs(total_average_running_time_sa - total_average_running_time_ha); 
     
            cout << "Iteration: " <<iterr<< ", "<<"Input-matrix-size: " <<size*size<<", " << "Best-size-produced-by-the-hillClimbing-algorithm: " <<bestSize_HA<<", "<<"Best-size-produced-by-the-simmulatedAnnealing-algorithm: "<<bestSize_SA <<", "<<"Average-runtime-by-the-hillClimbing-algorithm: "<<total_average_running_time_ha<<", "<< "Average-runtime-by-the-simmulatedAnnealing-algorithm: "<<total_average_running_time_sa<<", "<<"Absolute-Total-Difference-in-average-runtimes-by-both-algorithms: "<<total_average_running_time_difference<<endl;
            myFile << iterr << ", " <<size*size<<", "<<bestSize_HA <<", "<<bestSize_SA<<", " << total_average_running_time_ha << ", " << total_average_running_time_sa<<", "<<total_average_running_time_difference<<endl;
            iterr++;

            total_average_running_time_sa = 0;
            total_average_running_time_ha = 0;
            total_average_running_time_sa = 0;
            averageRunningTime_SA = 0;
            averageRunningTime_HA = 0;
            bestSize_HA = 0;
            bestSize_SA = 0;


    }
    myFile.close();
    myFile3.close();

}





int main(){
      
    cout<<"Enter n(to generate n x n matrix): ";
    cin >> n;
    G = generateRandom_N_By_N_Binary_Matrix(n);
    printTheMatrix(G, n);

    //Start hillClimbingAlgorith
    
  //  calculateTotalRunningTimeForEachIterationHillClimbingAlgorithm();
    //initial inputMatrix annd its size then handle the rest
    generateHillClimbingVsSimmulatedAnnealingOverallRuntimeResults(G, n);



    for(int i=0;i < n;i++){
        delete []G[i];
    }

    delete []G;
     


    return 0;
}