#include "GLibExample.h"
#include <iostream>
namespace glib{


std::shared_ptr<GLibExample> GLibExample::create(){

    auto glib_example = std::shared_ptr<GLibExample>(new GLibExample);

    glib_example->init();

    return glib_example;
}


bool GLibExample::init(){
    std::cout << "GLibExample::init" << std::endl;

    m_workerContext = g_main_context_new();

    if (nullptr == m_workerContext) {
        return false;
    }

    m_eventLoop = g_main_loop_new(m_workerContext, false);
    if (nullptr == m_eventLoop) {
        return false;
    }

    m_eventThread = std::thread(&GLibExample::mainLoopThread, this);
 
    return true;
}

void GLibExample::mainLoopThread(){
    g_main_context_push_thread_default(m_workerContext);
    do{
        std::cout << "mainLoopThread running" << std::endl;
        g_main_loop_run(m_eventLoop);
    }while(false);

}

void GLibExample::SourceEventTest(){
    
    auto source = g_idle_source_new();
    g_source_set_callback(source, reinterpret_cast<GSourceFunc>(&onEventCallback), this, nullptr);
    g_source_attach(source, m_workerContext);
    g_source_unref(source);
}

gboolean GLibExample::onEventCallback(gpointer pointer) {
    auto glib_example = static_cast<GLibExample*>(pointer);
    std::cout << "onEventCallback"<< std::endl;
    return false;
}





}
