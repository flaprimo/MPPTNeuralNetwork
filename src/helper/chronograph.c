#include <time.h>
#include <stdlib.h>
#include "chronograph.h"

/**
 * Given a clock, it coverts it in seconds.
 * @param clock
 * @return
 */
double chronograph_clockToSecond(clock_t clock)
{
    return (double) clock / CLOCKS_PER_SEC;
}

/**
 * Return and initializes a Chronograph with the start time.
 * @return
 */
Chronograph *chronograph_get()
{
    Chronograph *chronograph = malloc(sizeof(Chronograph));

    chronograph->startTime = chronograph_clockToSecond(clock());

    return chronograph;
}

/**
 * Given a Chronograph, it returns the delta beetween the start time and the present time
 * @param chronograph
 * @return
 */
double chronograph_getDelta(Chronograph *chronograph)
{
    return chronograph_clockToSecond(clock()) - chronograph->startTime;
}

/**
 * Frees Chronograph struct.
 * @param chronograph
 * @return
 */
void chronograph_free(Chronograph *chronograph)
{
    free(chronograph);
}