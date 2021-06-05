#include <gio/gio.h>
#include <future>
#include <thread>
#include <memory>

namespace glib{

class GLibExample{

public:
    static std::shared_ptr<GLibExample> create();
    void SourceEventTest();

private:
    bool init();

    /// Thread procedure to setup and handle GLib events
    void mainLoopThread();
	
    ///
    
    static gboolean onEventCallback(gpointer pointer);

    /// Event loop to listen for signals.
    GMainLoop* m_eventLoop;

    /// GLib context to run event loop in.
    GMainContext* m_workerContext;

    /// Promise to hold the result of a glib's main loop thread initialization.
    std::promise<bool> m_mainLoopInitPromise;

    /// Thread to run event listener on.
    std::thread m_eventThread;
}; 

}
