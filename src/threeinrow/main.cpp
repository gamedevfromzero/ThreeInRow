#include "config/config.hpp"
#include "math/vector.hpp"


int main(int argc, char *argv[])
{
	Config windowConfig;
	windowConfig.registerType<Vec2u>();
	windowConfig.registerType<std::string>();

	windowConfig.set<Vec2u>("window_size", Vec2u(720, 720));
	windowConfig.set<std::string>("window_name", "Three in row | gamedevfromzero");
}