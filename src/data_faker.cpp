#include <Arduino.h>
#include "Cmd.h"
#include "Ticker.h"
#include "globals.h"


//{
//    globals[index("f1")].value = globals[index("f1")].value + (random(0,100)-50)*0.01;
//    globals[index("f2")].value = globals[index("f2")].value + (random(0,100)-50)*0.01;
//}
#define _2PI 6.283185307179586476925286766559

void _timer_task(void){
   static float time_sec = 0;
   time_sec += 0.01;
   float amplitude  =  globals[index("a1")].value;
   float frequency  =  globals[index("w1")].value; // Hz
   float offset     =  globals[index("a1")].value * 2;
    
    globals[index("f1")].value = offset + amplitude * sin(_2PI*frequency*time_sec); 
   

    amplitude  =  globals[index("a2")].value;
    frequency  =  globals[index("w2")].value; // Hz
    offset     =  globals[index("a2")].value * 2;

    globals[index("f2")].value = offset + amplitude * sin(_2PI*frequency*time_sec);

     

}



Ticker t = Ticker(_timer_task, 10, 0, MILLIS);


void setup_fake_data() {
	globals[index("w1")].value = 0.01;
	globals[index("w2")].value = 0.03;
    globals[index("a1")].value = 2.0;
	globals[index("a2")].value = 3.0;

    randomSeed(127);
    
    /*
    cmdAdd("f1", [](int argcnt, char**){
        Stream *s = cmdGetStream();
        s->println(globals[index("f1")].value);
    });

    cmdAdd("f2", [](int argcnt, char**){
        Stream *s = cmdGetStream();
        s->println(globals[index("f2")].value);
    });
    */

    t.start();

}

void loop_fake_data() {
    t.update();
}   

