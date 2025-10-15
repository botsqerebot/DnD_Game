#include "raylib.h"
#include "../../TextureLoading/background/setBackground.h"
#include "../../interactivity/buttons/createButton.h"
#include "../../interactivity/viewText/storyBubble.h"
#include "../setGameState.h"

void gameScreenMenu()
{
    // setBackground(&bg2);
    changeBackgroundTexture(&currentBg);

    buttonV2(150, 50, 100, 100, "End game!", GRAY, ORANGE, setGameState, &state0, 5);
    buttonV2(150, 50, 100, 200, "Button v2", BLUE, GRAY, setGameState, &state0, 6);
    textBubble("test", 1);
}