#include "Sniff.hpp"

int main( int argc, char * argv[] ) {
    banner();
    Sniff sniff(argc, argv);
    sniff.run();
    bye();
    return 0;
}
