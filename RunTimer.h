//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_RUNTIMER_H
#define PHYSICSFORMULA_RUNTIMER_H
#include <chrono>
#include <iostream>
using namespace std;
// create an enum for the different units of time
enum TimeUnit {
    SECONDS,
    MILLISECONDS,
    MICROSECONDS,
    NANOSECONDS
};

class RunTimer {
private:
    chrono::time_point<chrono::system_clock, chrono::nanoseconds> start_;
    chrono::time_point<chrono::system_clock, chrono::nanoseconds> end_;
    chrono::nanoseconds elapsed_{};
    TimeUnit timeUnit;
public:
    RunTimer();
    explicit RunTimer(TimeUnit unit);
    void start();
    void stop();
    [[nodiscard]] chrono::nanoseconds elapsed() const;
    void setTimeUnit(TimeUnit unit);
    [[nodiscard]] TimeUnit getTimeUnit() const;
    void display() const;
};
#endif //PHYSICSFORMULA_RUNTIMER_H

inline RunTimer::RunTimer() {
    start_ = chrono::system_clock::now();
    end_ = chrono::system_clock::now();
    elapsed_ = chrono::nanoseconds(0);
    timeUnit = TimeUnit::NANOSECONDS;
}

inline RunTimer::RunTimer(TimeUnit unit) {
    start_ = chrono::system_clock::now();
    end_ = chrono::system_clock::now();
    elapsed_ = chrono::nanoseconds(0);
    timeUnit = unit;
}

inline void RunTimer::start() {
    start_ = chrono::system_clock::now();

}

inline void RunTimer::stop() {
    end_ = chrono::system_clock::now();
    elapsed_ = end_ - start_;
}

inline chrono::nanoseconds RunTimer::elapsed() const
{
    return elapsed_;
}

inline void RunTimer::setTimeUnit(TimeUnit unit) {
    timeUnit = unit;
}

inline TimeUnit RunTimer::getTimeUnit() const
{
    return timeUnit;
}

inline void RunTimer::display() const
{
    switch (timeUnit) {
        case TimeUnit::SECONDS:
            cout << "Elapsed seconds: " << elapsed_.count() / 1000000000.0 << " seconds" << endl;
            break;
        case TimeUnit::MILLISECONDS:
            cout << "Elapsed milliseconds: " << elapsed_.count() / 1000000.0 << " milliseconds" << endl;
            break;
        case TimeUnit::MICROSECONDS:
            cout << "Elapsed microseconds: " << elapsed_.count() / 1000.0 << " microseconds" << endl;
            break;
        case TimeUnit::NANOSECONDS:
            cout << "Elapsed nanoseconds: " << elapsed_.count() << " nanoseconds" << endl;
            break;
    }
}

