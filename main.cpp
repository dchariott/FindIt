#include "Params.hpp"
#include "Tools.hpp"

int main( int argc, char * argv[] ) {
    banner();
    Params params(argc, argv);
    params.print();
    bye();
    return 0;
}
