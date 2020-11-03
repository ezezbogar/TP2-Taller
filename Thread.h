#ifndef THREAD_H_
#define THREAD_H_

#include <thread>

class Thread {
 private:
    std::thread thread;

 public:
    /* Constructor */
    Thread();

    /* Ejecuta el thread con el metodo abstracto verificar, que sera
     * implementado por las clases hijas */
    void start();

    /* Bloquea el thread hasta que los otros completen su ejecucion */
    void join();

    /* Este metodo es implementado por las clases hijas */
    virtual void verificar() = 0;

    /* Destructor */
    virtual ~Thread();
};

#endif  // THREAD_H_
