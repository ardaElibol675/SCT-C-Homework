#include <iostream>
#include <iomanip>
#include <cmath> // for M_PI
#include "robot.h"

void Robot::move(float distance) {
    x = x + distance * cos(heading * M_PI / 180);
    y = y + distance * sin(heading * M_PI / 180);
    cout << "Robot Moved\n";
    printPose();
    path.push_back({x, y});
}

void Robot::rotate(float angle) {
    heading = headingNormalizer(heading + angle);
    cout << "Robot Rotated\n";
    printPose();
}

void Robot::reset() {
    // if previous position was (0, 0), this reset won't be added to the path
    if (x != 0 || y != 0) {
        x = 0;
        y = 0;
        heading = 0;
        cout << "Pose Reseted\n";
        path.push_back({x, y});
    } else if (heading != 0) {
        heading = 0;
        cout << "Pose Reseted\n";
    } else {
        throw logic_error("Robot is Already at the Initial Point!");
    }
}

void Robot::printPose() {
    cout << "Current Pose:\n"
         << "x: " << x << "\ty: " << y << "\tθ: " << heading << endl;
}

void Robot::distanceFromOrigin() {
    printPose();
    cout << "Distance From Origin: " << sqrt(x*x + y*y) << endl;
}

void Robot::setPose(float newX, float newY, float newHeading) {
    //if the new position is the same as previous one,
    //the new position won't be added to the path
    if (x != newX || y != newY) {
        x = newX;
        y = newY;
        heading = headingNormalizer(newHeading);
        printPose();
        path.push_back({x, y});
    } else {
        heading = headingNormalizer(newHeading);
        printPose();
    }
}

void Robot::printPath() {
    cout << "Traveled Path:\n";
    for (const auto& p: path)
        cout << "(" << p.first << ", " << p.second << ")" << endl;
}

float Robot::headingNormalizer(float h) {
    while (h < 0)
        h += 360;
    while (h >= 360)
        h -= 360;
    return h;
}
