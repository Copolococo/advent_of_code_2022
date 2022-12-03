#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    int sum_prios = 0;
    vector<set<char>> input;

    while (getline(input_file, line, '\n'))
    {
        input.push_back(set<char>(line.begin(), line.end()));
    }

    for (auto it = input.begin(); it != input.end(); it += 3)
    {
        set<char> intersection1;
        set<char> intersection2;

        set_intersection(it->begin(), it->end(), (it + 1)->begin(), (it + 1)->end(), inserter(intersection1, intersection1.begin()));
        set_intersection((it + 2)->begin(), (it + 2)->end(), intersection1.begin(), intersection1.end(), inserter(intersection2, intersection2.begin()));

        if (*intersection2.begin() < 'a')
            sum_prios += 26 + *intersection2.begin() - '@';
        else
            sum_prios += *intersection2.begin() - '`';
    }

    cout << "Sum of priorities: " << sum_prios << endl;

    return 0;
}