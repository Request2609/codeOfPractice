#include <iostream>
#include "Fanotify.h"

int main(int argc, char** argv) {
    for(int i=0; i<argc; i++) {
        std :: cout << argv[i] << std::endl ;
    }

    Fanotify notify ;
    notify.workCwd() ;
    string abPath = notify.getCwd() ;
    abPath=abPath+'/'+argv[1] ;
    //初始化
    notify.initFanotify(abPath.c_str()) ;
    notify.setNotifyObject(abPath.c_str()) ;
    notify.startListen() ;
    return 0;
}

