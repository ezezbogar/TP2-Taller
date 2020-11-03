#include "Thread.h"

Thread::Thread() {}

void Thread::start() {
    thread = std::thread(&Thread::verificar, this);
}

void Thread::join() {
    thread.join();
}

Thread::~Thread() {}
