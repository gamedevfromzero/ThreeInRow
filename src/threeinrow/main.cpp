#include "game/game_manager.hpp"


int main(int argc, char *argv[])
{
	int windowWidth = 720;
	int windowHeight = 720;
	const char* windowName = "Three in row (by gamedevfromzero)";
	
	Session session = SessionManager::newSession();
	session.setVector2("window_size", sf::Vector2f(windowWidth, windowHeight));
	session.setString("window_name", windowName);

	GameManager gameManager(session, argc, argv);
	gameManager.run();
}