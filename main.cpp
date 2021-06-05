#include<iostream>
#include"GLibExample.h"
#include <unistd.h>

int main(int argc, char **argv){

    auto example = glib::GLibExample::create();
    std::cout << "***Hi GLib***" << std::endl;
    while(1)
    {
	example->SourceEventTest();
        sleep(1);
    }
}
