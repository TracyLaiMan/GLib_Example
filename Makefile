
all:
	g++ GLibExample.cpp main.cpp -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0 -lpthread -o GLib_EventLoop_Example


clean:
	@if [ -e GLib_EventLoop_Example ];then rm GLib_EventLoop_Example;fi
