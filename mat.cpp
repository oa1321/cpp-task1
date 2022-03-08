#include <iostream>
#include <stdexcept>
using namespace std;
#include <string>
#include <algorithm>
#include "mat.hpp"


string ariel::mat(int w, int h, char ch1, char ch2 )
{
    //A manufacturing company wants to print a design on mats of varying dimensions, and they hired you to program a robot to make these mats. The design consists of alternating rings of each symbols on a mat.
    //The robot is given a mat of dimensions w x h, and a symbol to print. The robot should print the design on the mat, and return the mat as a string.
    if (w%2==0 || h%2==0)
    {
        throw invalid_argument("Mat size is always odd");
    }
    string mat;
    string mat2;
    char filler = ch1;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            mat+=filler;
        }
    }
    for(int x=0; x<h; x+=1)
    {
        for(int i=0+x; i<h-x; i++)
        {
            for(int j=0+x; j<w-x; j++)
            {
                mat[i*w+j]=filler;
            }
        }
        if(filler==ch2)
        {
            filler=ch1;
        }
        else
        {
            filler=ch2;
        }
    }
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            mat2+=mat[i*w+j];
        }
        mat2+="\n";
    }
    return mat2; 
}
