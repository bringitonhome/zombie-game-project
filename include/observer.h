#ifndef _OBSERVER_H
#define _OBSERVER_H
//************************************************
// observer.h
//************************************************

//Include dependencies
#include "defines.h"
#include "entity.h"

//This class could greatly benefit from templating
class Observer
{
    public:
        virtual void on_notify(Event event, int id) = 0;
    private:
};

#endif

