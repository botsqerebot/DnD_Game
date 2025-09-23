#include "raylib.h"
#include "../../TextureLoading/background/setBackground.h"
#include "../../interactivity/buttons/createButton.h"
#include "../setGameState.h"

void gameScreenMenu()
{
    // setBackground(&bg2);
    changeBackgroundTexture(&currentBg);

    buttonFunction(150, 50, 100, 600, 5, setGameState, &state0);

    drawButton(150, 50, 100, 600, "End game!", GRAY, ORANGE, 5);
}