#include "raylib.h"
#include "../../interactivity/buttons/createButton.h"
#include "../../TextureLoading/background/setBackground.h"
#include "../../TextureLoading/characters/loadCharacterTextures.h"
#include "../setGameState.h"

void homeScreenMenu()
{
    // setBackground(&bg1);
    //  Draw the background texture
    changeBackgroundTexture(&currentBg);
    buttonFunction(150, 50, 100, 200, 1, setBackground, &bg1);
    buttonFunction(150, 50, 100, 300, 2, setBackground, &bg2);
    buttonFunction(150, 50, 100, 400, 3, setCharacterTextures, (void *)whiteMan);
    buttonFunction(150, 50, 100, 500, 4, setCharacterTextures, (void *)grayMan);
    buttonFunction(150, 50, 100, 600, 5, setGameState, &state1);

    ViewCharacters(0, 200);

    drawButton(150, 50, 100, 200, "Hello", BLUE, ORANGE, 1);
    drawButton(150, 50, 100, 300, "World!", GRAY, ORANGE, 2);
    drawButton(150, 50, 100, 400, "Character!", GRAY, ORANGE, 3);
    drawButton(150, 50, 100, 500, "Character2!", GRAY, ORANGE, 4);
    drawButton(150, 50, 100, 600, "Start game!", GRAY, ORANGE, 5);
}