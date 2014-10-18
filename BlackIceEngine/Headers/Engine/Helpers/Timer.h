#ifndef INC_TIMER_H
#define INC_TIMER_H

class Timer
{
private:
    // The clock time when the timer started
    int startTicks;

    // The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;
	
public:
    // Initializes variables
    Timer();

    // The various clock actions
    void Start();
    void Stop();
    void Pause();
    void Unpause();

    // Gets the timer's time
    int Get_Ticks();

    // Checks the status of the timer
    bool Is_Started();
    bool Is_Paused();
};

#endif /* INC_TIMER_H */