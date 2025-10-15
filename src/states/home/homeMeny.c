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


    buttonV2(150, 50, 100, 200, "Hello", BLUE, ORANGE, setBackground, &bg1, 1);
    buttonV2(150, 50, 100, 300, "World!", GRAY, ORANGE, setBackground, &bg2, 2);
    buttonV2(150, 50, 100, 400, "Character!", GRAY, ORANGE, setCharacterTextures, (void *)whiteMan, 3);
    buttonV2(150, 50, 100, 500, "Character2!", GRAY, ORANGE, setCharacterTextures, (void *)grayMan, 4);
    buttonV2(150, 50, 100, 600, "Start game!", GRAY, ORANGE, setGameState, &state1, 5);

    ViewCharacters(0, 200);
}