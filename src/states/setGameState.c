int currentState = 0;

int state1 = 1;
int state0 = 0;

void setGameState(void *userData)
{
    currentState = *(int *)userData;
}