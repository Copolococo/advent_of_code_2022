#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    int curr_calories = 0;
    vector<int> total_calories;

    // preprocess file
    while (getline(input_file, line, '\n'))
    {
        if (line.empty())
        {
            total_calories.push_back(curr_calories);
            curr_calories = 0;
        }
        else
        {
            curr_calories += stoi(line);
        }
    }

    input_file.close();

    // sort 3 highest
    partial_sort(total_calories.begin(), total_calories.begin() + 3, total_calories.end(), [](int a, int b) { return (a > b); });

    int sum_top_3 = total_calories[0] + total_calories[1] + total_calories[2];

    cout << "max_calories: " << total_calories[0] << endl;
    cout << "sum of top 3: " << sum_top_3 << endl;

    return 0;
}