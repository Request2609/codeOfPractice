#include <iostream>
#include "Fanotify.h"

int main(int argc, char** argv) {
    for(int i=0; i<argc; i++) {
        std :: cout << argv[i] << std::endl ;
    }

    Fanotify notify ;
    notify.setNotifyObject(argv[1]) ;
    notify.startListen() ;
    return 0;
}

