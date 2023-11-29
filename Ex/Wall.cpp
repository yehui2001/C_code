#include <iostream>
#include <cmath>
using namespace std;

struct City {
    double x;
    double y;
    double radius;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int calculateWalls(const City cities[], int numCities) {
    int numWalls = 0;
    
    for (int i = 0; i < numCities; ++i) {
        for (int j = i+1; j < numCities; ++j) {
            double d = distance(cities[i].x, cities[i].y, cities[j].x, cities[j].y);
            double sumRadii = cities[i].radius + cities[j].radius;
            
            if (d < sumRadii) {
                numWalls++;
            }
        }
    }
    
    return numWalls;
}

int main() {
    const int numCities = 8;
    City cities[numCities] = {
        {19,8,8},
        {28,15,3},
        {22,12,8},
        {18,10,6},
        {19,9,8},
        {8,12,13},
        {9,14,10},
        {8,15,12},
        // 添加剩余城市的坐标和半径
        // {x, y, radius}
    };
    
    int numWalls = calculateWalls(cities, numCities);
    
    cout << "The number of walls between cities is: " << numWalls << endl;
    
    return 0;
}

