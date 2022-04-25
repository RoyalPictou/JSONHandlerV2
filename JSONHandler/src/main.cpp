#include "Handler.h"
#include <cstddef>



int main(void)
{
    int rv = 0;
    Handler* h = new Handler();
    delete(h);

    h = NULL;


    return rv;

}