#include<iostream>
#include<cmath>
using namespace std;

struct Point{
    int x,y;
};

int calculateEuclidianDistance(Point p1, Point p2){
    return pow((p1.x - p2.x),2) + pow(p1.y-p2.y,2);
}


bool isSquare(Point p1, Point p2, Point p3, Point p4){
    int d12 = calculateEuclidianDistance(p1,p2); // from P1 to P2
    int d13 = calculateEuclidianDistance(p1,p3); // from P1 to P3
    int d14 = calculateEuclidianDistance(p1,p4); // from P1 to P4
    
	if (d12 == d13 && 2 * d12 == d14 && 2 * d12 == calculateEuclidianDistance(p2, p3)) { 
        int d = distSq(p2, p4); 
        return (d == distSq(p3, p4) && d == d12); 
    } 
  
    // The below two cases are similar to above case 
    if (d13 == d14 && 2 * d13 == d12 && 2 * d13 == distSq(p3, p4)) { 
        int d = distSq(p2, p3); 
        return (d == distSq(p2, p4) && d == d13); 
    } 
    if (d12 == d14 && 2 * d12 == d13 && 2 * d12 == distSq(p2, p4)) { 
        int d = distSq(p2, p3); 
        return (d == distSq(p3, p4) && d == d12); 
    } 
    return false;
}
int main() 
{ 
        Point p1 = { 20, 10 }, p2 = { 10, 20 }, 
            p3 = { 20, 20 }, p4 = { 10, 10 }; 
        isSquare(p1, p2, p3, p4) ? cout << "Yes" : cout << "No"; 
        return 0; 
} 
