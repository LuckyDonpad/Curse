#ifndef TANKS_DEFINITIONS_HPP
#define TANKS_DEFINITIONS_HPP

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 1000

#define SPLASH_STATE_SHOW_TIME 0.5

#define SPLASH_SCENE_BACKGROUND_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\SHUTTER.png"
#define MAIN_MENU_BACKGROUND_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\sky.png"
#define GAME_BACKGROUND_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\sky.png"
#define GAME_OVER_BACKGROUND_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\game_over_screen.png"
#define GAME_TITLE_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\Title.png"
#define PLAY_BUTTON_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\PLAY_BUTTON.png"
#define PIPE_UP_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\pipe_up.png"
#define PIPE_DOWN_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\pipe_down.png"
#define PLAYER_FRAME_1 "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\nyan\\frame_1.png"
#define PLAYER_FRAME_2 "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\nyan\\frame_2.png"
#define PLAYER_FRAME_3 "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\nyan\\frame_3.png"
#define PLAYER_FRAME_4 "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\nyan\\frame_4.png"
#define PLAYER_FRAME_5 "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\nyan\\frame_5.png"
#define PLAYER_FRAME_6 "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\nyan\\frame_6.png"

#define FONT_PATH "C:\\Users\\super\\CLionProjects\\FlappyBird\\resources\\technofosiano.ttf"

#define PIPE_MOVEMENT_SPEED 30.f
#define PIPE_SPAWN_CLOCK 1.5f
#define PLAYER_ANIMATION_DURATION 0.4f


#define PLAYER_STATE_STILL 1
#define PLAYER_STATE_FALLING 2
#define PLAYER_STATE_FLYING 3

#define GRAVITY 10.f
#define FLY_DURATION 0.15f
#define FLY_SPEED 60.f

enum GameStates{
    eReady,
    ePlaying,
    eGameOver
};


#endif //TANKS_DEFINITIONS_HPP
