add_executable(Tanks FSM/FSM.hpp FSM/State.hpp FSM/FSM.cpp AssetManager/AssetManager.cpp AssetManager/AssetManager.hpp InputManager/InputManager.cpp InputManager/InputManager.hpp Game/Game.cpp Game/Game.hpp Definitions/DEFINITIONS.hpp SplashState/SplashState.cpp SplashState/SplashState.hpp MainMenuState/MainMenuState.cpp MainMenuState/MainMenuState.hpp GameState/GameState.cpp GameState/GameState.hpp GameOverState/GameOverState.cpp GameOverState/GameOverState.hpp Pipe/Pipe.cpp Pipe/Pipe.hpp Player/Player.cpp Player/Player.hpp Collision/Collision.cpp Collision/Collision.hpp HUD/HUD.cpp HUD/HUD.hpp)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp *.h)
target_sources(Tanks PRIVATE ${SOURCE_FILES})
target_link_libraries(Tanks sfml-system sfml-window sfml-graphics sfml-audio)
include_directories(
        AssetManager
        FSM
        Game
        InputManager
        Definitions
        SplashState
        MainMenuState
        GameState
        GameOverState
        Pipe
        Player
        Collision
        HUD)
