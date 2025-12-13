#include <vector>
#include <utility> // create x-y pairs for path tracing
using namespace std;

class Robot {

    private:
    float x, y, heading;
    vector<pair<float, float>> path;

    public:
    Robot (float x, float y, float heading, pair<float, float> pair):
        x(x), y(y), heading(heading) {
            path.push_back(pair);
        }
    void move(float distance);
    void rotate(float angle);
    void reset();
    void printPose();
    void distanceFromOrigin();
    void setPose (float newX, float newY, float newHeading);
    void printPath();
    float headingNormalizer(float h); // keep heading between 0 and 360

};
