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
    textBubbleWrapped("Welcome to this amazing dungeons and dragons adventure game where you will embark on epic quests, battle fearsome monsters, discover ancient treasures, and forge legendary friendships with fellow adventurers as you explore mystical realms filled with magic, danger, and countless opportunities for heroic deeds that will be remembered for generations to come!", 1);
}