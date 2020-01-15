#include <iostream>
#include "Fanotify.h"

int main(int argc, char** argv) {
    Fanotify notify ;
    notify.setNotifyObject(argv[1]) ;
    notify.startListen() ;
    return 0;
}

