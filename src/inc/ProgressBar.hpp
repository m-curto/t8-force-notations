#ifndef PROGRESSBAR_HPP
# define PROGRESSBAR_HPP

# include "Actor.hpp"

class ProgressBar : public Actor
{
    public:
        ProgressBar();
        ProgressBar(const ProgressBar &);
        ProgressBar(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h);

        ~ProgressBar();
        ProgressBar& operator=(const ProgressBar &);

        void step();
        void reset();

        void setTotal(const int&);
        void addTotal(const int&);

    private:
        int     total;
        int     p;
};

#endif