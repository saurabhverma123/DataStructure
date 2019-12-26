#include<memory>
#include "string.h"
using namespace std;

// Reverse string 1234_567_89_12 to 12_89_567_1234
void reverse(char* arg, int start, int end)
{
    for ( auto i=0; i <= static_cast<int>((end-start)/2) ; ++i)
    {
        auto temp = arg[start+i];
        arg[start+i] = arg[end-i];
        arg[end-i] = temp;
    }
}

void fun(char* arg)
{
    int len = strlen(arg);
    int start=0;
    for(auto i = 0; i < len; ++i)
    {
        if (arg[i] == '_')
        {
            reverse(arg, start, i-1);
            start = i+1;
        }
    }
    reverse(arg, start, len-1);
    reverse(arg, 0, len-1);
}

int main()
{
    char a[] = "abcd_def_nmop_xyz";
    cout << a << endl;
    fun(a);
    cout << a << endl;
    return 0;
}
