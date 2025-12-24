Talking about the question context...
Let's say all the three A threads come to the point of releasing semaphore2 i.e..last instruction (all A thread copies about to finish their execution)
At this point B will Anyway complete it's first instruction.
Because without it's first instruction's completion, No A copy passes through it's first instruction.
At this point B waits for the semaphore to get released by one of the A copies
Logically speaking B immediately gets unblocked from waiting queue after one of the A releases semaphore2 before other A's finishes releasing semaphoree2
The above statement can only be said conceptually but in reality it may not be the case.
It depends on OS scheduling as well.
Hence in reality, after A1 terminates, other A's may get terminated immediately before B.
But conceptually speaking B terminates after one A gets terminated.
