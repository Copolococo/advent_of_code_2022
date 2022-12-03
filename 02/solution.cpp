#include <fstream>
#include <iostream>
#include <map>

using namespace std;

static map<string, int> pt1LUT = {
    {"A X", 1 + 3},
    {"A Y", 2 + 6},
    {"A Z", 3 + 0},
    {"B X", 1 + 0},
    {"B Y", 2 + 3},
    {"B Z", 3 + 6},
    {"C X", 1 + 6},
    {"C Y", 2 + 0},
    {"C Z", 3 + 3},
};

static map<string, int> pt2LUT = {
    {"A X", 0 + 3},
    {"A Y", 3 + 1},
    {"A Z", 6 + 2},
    {"B X", 0 + 1},
    {"B Y", 3 + 2},
    {"B Z", 6 + 3},
    {"C X", 0 + 2},
    {"C Y", 3 + 3},
    {"C Z", 6 + 1},
};

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    int score_pt1 = 0;
    int score_pt2 = 0;

    while (getline(input_file, line, '\n'))
    {
        score_pt1 += pt1LUT[line];
        score_pt2 += pt2LUT[line];
    }

    cout << "Total Score pt1: " << score_pt1 << endl;
    cout << "Total Score pt2: " << score_pt2 << endl;

    return 0;
}