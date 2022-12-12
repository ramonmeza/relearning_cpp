#include <cstdlib>
#include <iostream>

#include <exercises/chapter_01.hh>
#include <exercises/chapter_02.hh>
#include <exercises/chapter_03.hh>
#include <exercises/chapter_04.hh>
#include <exercises/chapter_05.hh>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));

    chapter_05::game();

    return EXIT_SUCCESS;
}
