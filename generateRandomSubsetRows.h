//Choose a start state s (randomly, or otherwise)
#include <iostream>
#include <vector>

using namespace std;

vector<int> generateRandomSubsetOfRowsX(){
    vector<int> randomRows;
    int i = rand() % 4;
    int j = rand() % 3;
    // if i and j are equal we recursively call this function untill we generate different i and j.
    if (i != j){
        randomRows.push_back(i);
        randomRows.push_back(j);
    }else {
        return generateRandomSubsetOfRowsX();
    }
    return randomRows;
}