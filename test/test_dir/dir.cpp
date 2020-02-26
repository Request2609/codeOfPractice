#include <iostream>
#include <unistd.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent* ptr ;
    if((dir=opendir(".")) != NULL) {
        while((ptr = readdir(dir)) != NULL) {
            std::cout << ptr->d_name << std:: endl ;
        }
        closedir(dir) ;
    }
    return 0;
}

