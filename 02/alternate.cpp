#include <fstream>
#include <iostream>

using namespace std;

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
        int left = line[0] - 'A' + 1;
        int right = line[2] - 'X' + 1;
        score_pt1 += ((4 + right - left) % 3) * 3 + right;
        score_pt2 += 1 + ((left + right) % 3) + ((right - 1) * 3);
    }

    cout << "Total Score pt1: " << score_pt1 << endl;
    cout << "Total Score pt2: " << score_pt2 << endl;

    return 0;
}