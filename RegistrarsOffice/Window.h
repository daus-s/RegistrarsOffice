#ifndef Window_H
#define Window_H


class Window
{
    public:
        int idleTime;
        int timeLeft;
        int currentIdle;
        int maxIdle;
        bool isOpen();
};
#endif
