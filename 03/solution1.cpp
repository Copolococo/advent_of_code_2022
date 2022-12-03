#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    int sum_prios = 0;

    while (getline(input_file, line, '\n'))
    {
        set<char> left(line.begin(), line.begin() + (line.size() / 2));
        set<char> right(line.begin() + (line.size() / 2), line.end());

        set<char> intersection;
        set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(intersection, intersection.begin()));

        for (char c : intersection)
        {
            if (c < 'a')
                sum_prios += 26 + c - '@';
            else
                sum_prios += c - '`';
        }
    }

    cout << "Sum of priorities: " << sum_prios << endl;

    return 0;
}