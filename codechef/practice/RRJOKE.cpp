#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int testcases;

    cin >> testcases;

    for(int i = 1;i <= testcases;i++){
        int numPoints;
        cin >> numPoints;

        int coordinates[numPoints][2];
        for(int j = 0;j < numPoints;j++){
            cin >> coordinates[j][0];
            cin >> coordinates[j][1];
        }        

        int size = (numPoints * (numPoints - 1)) / 2;
        int distance[size];
        int index = 0;
        for(int j = 0;j < numPoints - 1;j++){
            for(int k = j+1;k < numPoints;k++){
                distance[index++] = min(abs(coordinates[j][0]-coordinates[k][0]),abs(coordinates[j][1]-coordinates[k][1]));
            }
        }

        int output = distance[0];
        for(int j = 1;j < size;j++){
            output = output ^ distance[j];
        } 

        cout << output << endl;
    }

    return 0;
}