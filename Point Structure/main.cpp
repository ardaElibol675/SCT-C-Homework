#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Point {
    float x,y,z;
    string name;
    bool is_invalid = true; // check for valid input
};

float zero_distance(Point p) {
    return sqrt(pow(p.x, 2)+pow(p.y, 2)+pow(p.z, 2));
}

float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2)+pow(p1.z-p2.z, 2));
}

Point compare(Point p1, Point p2) {
    if (zero_distance(p1) > zero_distance(p2)) {
        return p1;
    } else {
        return p2;
    }
}

int region(Point p) {
    
    if (p.x == 0 || p.y == 0 || p.z == 0)
        return 0; // the point doesn't belong to any octan
    else if(p.x>0 && p.y>0 && p.z>0)
        return 1;
    else if (p.x<0 && p.y>0 && p.z>0)
        return 2;
    else if (p.x<0 && p.y<0 && p.z>0)
        return 3;
    else if (p.x>0 && p.y<0 && p.z>0)
        return 4;
    else if (p.x>0 && p.y>0 && p.z<0)
        return 5;
    else if (p.x<0 && p.y>0 && p.z<0)
        return 6;
    else if (p.x<0 && p.y<0 && p.z<0)
        return 7;
    else // p.x>0 && p.y<0 && p.z<0
        return 8;

}

bool is_in_same_region(Point p1, Point p2) {
    
    if (region(p1) == region(p2) != 0) {
        return true; // points are at the same region
    } else {
        return false; // points may not have a region
    }

}

int main() {

    // Generate the points
    Point point1, point2;
    point1.name = "Point-1";
    point2.name = "Point-2";
    
    // Get the coordinates for the points
    do {
        try {
            cout << "Coordinates For Point 1: ";
            if(!(cin >> point1.x >> point1.y >> point1.z)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid Input! Inputs Must Be Numbers");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case user provides extra input
            point1.is_invalid = false;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (point1.is_invalid);

    do {
        try {
            cout << "Coordinates For Point 2: ";
            if (!(cin >> point2.x >> point2.y >> point2.z)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid Input! Inputs Must Be Numbers");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case user provides extra input
            point2.is_invalid = false;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (point2.is_invalid);
    
    // Distances to the origin of the points
    cout << endl << "Distances to the origin" 
         << endl << "Point 1: " << zero_distance(point1)
         << endl << "Point 2: " << zero_distance(point2);

    // Distance between points
    cout << "\n\n" << "Distance between points: " << distance(point1, point2);

    // Furthest point from the origim
    cout << "\n\n" << "The furthest point: " << compare(point1, point2).name;

    // Regions of the points
    cout << "\n\n" << "Regions: "
         << endl << "Point 1: " << region(point1)
         << endl << "Point 2: " << region(point2);

    // Are the points at the same region?
    if (is_in_same_region(point1, point2)) {
        cout << endl << "The points are at the same region." << "\n\n";
    } else {
        cout << endl << "The points are not at the same region." << "\n\n";
    }

    return 0;
}
