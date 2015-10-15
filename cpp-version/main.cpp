#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[])
{
    // select mode
    // 1 = slow using std::vector
    // 2 = using set
    // 3 = using std::unordered_set - thanks for 0xe2.0x9a.0x9b from go-nuts
    // 4 = using std::set_difference - thanks for Rajanikanth from go-nuts - it not show the correct data

    int mode = 3;

    if (mode == 1)
    {
        // get data from file A
        vector<string> dataA;
        ifstream streamA;

        streamA.open(argv[1]);

        while(!streamA.eof())
        {
            string line;
            streamA >> line;
            dataA.push_back(line);
        }

        streamA.close();

        // get data from file B
        vector<string> dataB;
        ifstream streamB;

        streamB.open(argv[2]);

        while(!streamB.eof())
        {
            string line;
            streamB >> line;
            dataB.push_back(line);
        }

        streamB.close();

        // show debug data
        printf("> Data in A: %zu | Data in B: %zu\n", dataA.size(), dataB.size());

        // process data
        for(vector<string>::const_iterator i = dataA.begin(); i != dataA.end(); ++i)
        {
            string value = *i;

            if (std::find(dataB.begin(), dataB.end(), value) == dataB.end())
            {
                printf("%s\n", value.c_str());
            }
        }
    }
    else if (mode == 2)
    {
        // get data from file A
        std::set<string> dataA;
        ifstream streamA;

        streamA.open(argv[1]);

        while(!streamA.eof())
        {
            string line;
            streamA >> line;
            dataA.insert(line);
        }

        streamA.close();

        // get data from file B
        std::set<string> dataB;
        ifstream streamB;

        streamB.open(argv[2]);

        while(!streamB.eof())
        {
            string line;
            streamB >> line;
            dataB.insert(line);
        }

        streamB.close();

        // show debug data
        printf("> Data in A: %zu | Data in B: %zu\n", dataA.size(), dataB.size());

        // process data
        for(string value : dataA)
        {
            auto search = dataB.find(value);

            if (search == dataB.end())
            {
                printf("%s\n", value.c_str());
            }
        }
    }
    else if (mode == 3)
    {
        // version from: 0xe2.0x9a.0x9b

        // get data from file A
        std::unordered_set<string> dataA;
        ifstream streamA;

        streamA.open(argv[1]);

        while(!streamA.eof())
        {
            string line;
            streamA >> line;
            dataA.insert(line);
        }

        streamA.close();

        // get data from file B
        std::unordered_set<string> dataB;
        ifstream streamB;

        streamB.open(argv[2]);

        while(!streamB.eof())
        {
            string line;
            streamB >> line;
            dataB.insert(line);
        }

        streamB.close();

        // show debug data
        printf("> Data in A: %zu | Data in B: %zu\n", dataA.size(), dataB.size());

        // process data
        for(string value : dataA)
        {
            auto search = dataB.find(value);

            if (search == dataB.end())
            {
                printf("%s\n", value.c_str());
            }
        }
    }
    else if (mode == 4)
    {
        // version from: Rajanikanth

        // general
        std::set<string> result;

        // get data from file A
        std::unordered_set<string> dataA;
        ifstream streamA;

        streamA.open(argv[1]);

        while(!streamA.eof())
        {
            string line;
            streamA >> line;
            dataA.insert(line);
        }

        streamA.close();

        // get data from file B
        std::unordered_set<string> dataB;
        ifstream streamB;

        streamB.open(argv[2]);

        while(!streamB.eof())
        {
            string line;
            streamB >> line;
            dataB.insert(line);
        }

        streamB.close();

        // show debug data
        printf("> Data in A: %zu | Data in B: %zu\n", dataA.size(), dataB.size());

        std::set_difference(dataA.begin(), dataA.end(), dataB.begin(), dataB.end(), inserter(result, result.end()));

        // process data
        for (auto elem: result)
        {
            printf("%s\n", elem.c_str());
        }
    }
}
