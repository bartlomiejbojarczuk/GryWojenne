#ifndef CTIMER_H
#define CTIMER_H

#include <ctime>
#include <QThread>
#include <QString>


class CTimer:public QThread
{ Q_OBJECT

signals:
    void now();

public:
    CTimer();
    virtual ~CTimer();
    bool IsStarted();
    bool IsStopped();
    bool IsPaused();
    bool IsActive();

    void Pause();
    void Resume();
    void Start ();
    void Stop ();
    void Reset();

    clock_t GetTime();

    void run();
private:
    clock_t startedAt;
    clock_t pausedAt;
    bool started;
    bool paused;
};

#endif // CTIMER_H
