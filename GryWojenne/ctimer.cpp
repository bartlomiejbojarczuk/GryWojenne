#include "ctimer.h"
#include <windows.h>
#include <QDebug>
CTimer::CTimer()
{
    startedAt=0;
    pausedAt=0;
    paused=false;
    started=false;
    qDebug()<<"CTimer konstruktor";

}

CTimer::~CTimer()
{

}

bool CTimer::IsStarted()
{
    return started;
}
bool CTimer::IsStopped()
{
    return !started;
}
bool CTimer::IsPaused()
{
    return paused;
}
bool CTimer::IsActive()
{
    return !paused & started;
}
void CTimer::Pause()
{
    if( paused || !started )
        return;
    paused = true;
    pausedAt = clock();
    qDebug()<<"Timer PAUSED";
}
void CTimer::Resume()
{
    if( !paused )
        return;
    paused = false;
    startedAt += clock() - pausedAt;
    qDebug()<<"Timer RESUME";
}
void CTimer::Stop()
{
    started = false;
    qDebug()<<"Timer STOP";
}
void CTimer::Start()
{
    if( started )
        return;
    started = true;
    paused = false;
    startedAt = clock();
    qDebug()<<"Timer START";
}
void CTimer::Reset()
{
    paused = false;
    startedAt = clock();

}
clock_t CTimer::GetTime()
{
    if( !started )
        return 0;
    if( paused )
        return pausedAt - startedAt;
    return clock() - startedAt;
}

void CTimer::run()
{   int l=0;
    Start();
    while(1){
        while( GetTime() < 1000 );
        Reset();

        emit now();
        l++;
        qDebug()<<"Poszło "<<l <<"\n";
    }


}
