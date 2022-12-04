#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    int n_contained = 0;
    int n_overlap = 0;

    while (getline(input_file, line, '\n'))
    {
        string left = line.substr(0, line.find(','));
        string right = line.substr(line.find(',')+1);

        int min_left = stoi(left.substr(0, left.find('-')));
        int max_left = stoi(left.substr(left.find('-')+1));

        int min_right = stoi(right.substr(0, right.find('-')));
        int max_right = stoi(right.substr(right.find('-')+1));

        if ((min_left >= min_right && max_left <= max_right) ||
            (min_left <= min_right && max_left >= max_right))
            n_contained++;
        
        if ((min_left <= min_right && max_left >= min_right) ||
            (min_right <= min_left && max_right >= min_left))
            n_overlap++;
    }

    cout << "Sum of contained sets: " << n_contained << endl;
    cout << "Sum of overlapped sets: " << n_overlap << endl;

    return 0;
}