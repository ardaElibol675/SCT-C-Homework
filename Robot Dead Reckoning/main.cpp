#include <string>
#include "robot.cpp"

int main() {

    Robot robot(0, 0, 0, {0, 0}); // x, y, heading(degrees), x-y pair

    while(true) {

        cout << setfill('-') << setw(41) << ""  << setfill(' ') << endl;
        cout << right << setw(27) << "Robot Control\n";
        cout << setfill('-') << setw(41) << ""  << setfill(' ') << endl;
        cout << left << setw(26) << "1. Move" << "2. Rotate\n"
             << left << setw(26) << "3. Current Pose" << "4. Reset Pose\n"
             << left << setw(26) << "5. Distance From Origin" << "6. Set Pose\n"
             << left << setw(26) << "7. Traveled Path" << "8. Exit\n"; 
        cout << setfill('-') << setw(41) << ""  << setfill(' ') << endl;
        cout << "-> ";
        string s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case user provides extra input

        try {

            if (s == "8") {
                cout << "Program Terminated\n\n";
                break;
            } else if (s == "1") {
                float distance;
                cout << "Enter Distance: ";
                if (!(cin >> distance)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid Input! Input Must Be A Number");
                } else if (distance <= 0)
                    throw logic_error("Invalid Input! Input Must Be Positive");
                cout << setfill('-') << setw(41) << ""  << setfill(' ') << endl;
                robot.move(distance);
            } else if (s == "2") {
                float angle_deg;
                cout << "Enter Angle (In Degrees): ";
                if (!(cin >> angle_deg)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid Input! Inputs Must Be Numbers");
                }
                cout << setfill('-') << setw(41) << ""  << setfill(' ') << endl;
                robot.rotate(angle_deg);
            } else if (s == "3") {
                robot.printPose();
            } else if (s == "4") {
                robot.reset();
            } else if (s == "5") {
                robot.distanceFromOrigin();
            } else if (s == "6") {
                float newX, newY, newHeading;
                cout << "Enter New Pose (x, y, θ):\n-> ";
                if (!(cin >> newX >> newY >> newHeading)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid Input! Inputs Must Be Numbers");
                }
                cout << setfill('-') << setw(41) << ""  << setfill(' ') << endl;
                robot.setPose(newX, newY, newHeading);
            } else if (s == "7") {
                robot.printPath();
            } else {
                cout << "Invalid Entry!\n";
            }

        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        } catch (const logic_error& e) {
            cout << e.what() << endl;
        }

    }

    return 0;
}
