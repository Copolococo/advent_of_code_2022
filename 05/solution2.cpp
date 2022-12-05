#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <regex>
#include <stack>

using namespace std;

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    vector<list<char>> boxes;
    getline(input_file, line, '\n');

    int n_elements = ((line.size()-1) / 4) + 1;
    boxes.resize(n_elements);
    do
    {
        if (line[1] == '1') break;

        for (int i = 0; i < n_elements; ++i)
        {
            char character = line[1 + (i*4)];
            if (character != ' ')
                boxes[i].push_back(character);
        }
    } while (getline(input_file, line, '\n'));

    regex number_regex("[0-9]+");

    while (getline(input_file, line, '\n'))
    {
        smatch number_match;

        auto numbers_begin = sregex_iterator(line.begin(), line.end(), number_regex);
        auto numbers_end = sregex_iterator();
        if (1 > distance(numbers_begin, numbers_end))
            continue;
        
        sregex_iterator it = numbers_begin;
        smatch match = *it;
        int count = stoi(match.str());
        match = *(++it);
        int from = stoi(match.str()) - 1;
        match = *(++it);
        int to = stoi(match.str()) - 1;

        stack<char> tmp;

        for (unsigned i = 0; i < count; ++i)
        {
            tmp.push(boxes[from].front());
            boxes[from].pop_front();
        }
        
        for (unsigned i = 0; i < count; ++i)
        {
            boxes[to].push_front(tmp.top());
            tmp.pop();
        }

    }

    for(size_t i = 0; i < boxes.size(); ++i)
    {
        cout << boxes[i].front();
    }
    cout << endl;

    return 0;
}