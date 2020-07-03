#include <bits/stdc++.h>

using namespace std;

struct Point 
{ 
    long long int x; 
    long long int y; 
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) {
        return true; 
    } 
  
    return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
    long long int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) {
        return 0;   
    }

    return (val > 0)? 1: 2;  
} 


bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) {
        return true; 
    }
  
    if (o1 == 0 && onSegment(p1, p2, q1)) {
        return true; 
    }

    if (o2 == 0 && onSegment(p1, q2, q1)) {
        return true; 
    }

    if (o3 == 0 && onSegment(p2, p1, q2)) {
        return true; 
    }

    if (o4 == 0 && onSegment(p2, q1, q2)) {
        return true;
    }  
  
    return false;  
} 




int main() {
    int testcases;
    cin >> testcases;

    int points, queries;
    for(int i = 0;i < testcases;i++) {
        cin >> points >> queries;

        long long int y_coordinates[points];
        for(int j = 0;j < points;j++) {
            cin >> y_coordinates[j];
        }

        long long int query[queries][3];
        for(int j = 0;j < queries;j++) {
            cin >> query[j][0] >> query[j][1] >> query[j][2];
        }

        long long int coordinates[points][2];
        for(int j = 0;j < points;j++) {
            coordinates[j][0] = j + 1;
            coordinates[j][1] = y_coordinates[j];
        }

        for(int j = 0;j < queries;j++) {
            struct Point A = {query[j][0], query[j][2]};
            struct Point B = {query[j][1], query[j][2]};

            long long int count = 0;
            for(int k = 0;k < points - 1;k++) {
                struct Point C = {coordinates[k][0], coordinates[k][1]};
                struct Point D = {coordinates[k + 1][0], coordinates[k + 1][1]};

                if(doIntersect(A, B, C, D)) {
                    count++;
                }
            }

            cout << count << endl;
        }

    }

    return 0;
}