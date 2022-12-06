#include <fstream>
#include <iostream>
#include <list>

using namespace std;

const int window_size = 4;

int main()
{
    string line;
    ifstream input_file("input.txt");

    if (!input_file.is_open())
        return 1;

    int n_lines = 0;
    if (!getline(input_file, line, '\n'))
        return 1;

    list<char> char_queue;
    int index = 1;
    for (char c : line)
    {
        char_queue.push_front(c);
        if (char_queue.size() != window_size+1)
        {
            index++;
            continue;
        }
        
        char_queue.pop_back();
        bool repeated = false;
        
        for (list<char>::iterator it = char_queue.begin(); it != char_queue.end(); ++it)
        {
            for (list<char>::iterator pit = next(it); pit != char_queue.end(); ++pit)
            {
                if (*it == *pit)
                    repeated = true;

            }
        }

        if (repeated == false)
            break;

        index++;
    }

result:
    cout << index << endl;

    return 0;
}