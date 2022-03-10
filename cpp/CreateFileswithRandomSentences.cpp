#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int files = 10;
    ofstream outfile;
    for (int i = 1; i < files; i++)
    {
        outfile.open("../txt/file" + i + ".txt");
        for (int i = 0; i < 10; i++)
        {
            string sentence = "";
            for (int j = 0; j < rand() % 10 + 1; j++)
            {
                sentence += " " + to_string(rand() % 10 + 1);
            }
            outfile << sentence << endl;
        }
        outfile.close();
    }
    return 0;
}
