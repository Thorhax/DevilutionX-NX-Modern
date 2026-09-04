#include "game_mode.hpp"

#include <function_ref.hpp>

#include "options.h"

namespace devilution {
namespace {
void OptionSharewareChanged()
{
	gbIsSpawn = *GetOptions().GameMode.shareware;
}
const auto OptionChangeHandlerShareware = (GetOptions().GameMode.shareware.SetValueChangedCallback(OptionSharewareChanged), true);

void OptionGameModeChanged()
{
	const bool enableHellfire = *GetOptions().GameMode.gameMode == StartUpGameMode::Hellfire;
	GetOptions().Mods.SetHellfireEnabled(enableHellfire);
}
const auto OptionChangeHandlerGameMode = (GetOptions().GameMode.gameMode.SetValueChangedCallback(OptionGameModeChanged), true);
} // namespace

GameData sgGameInitInfo;
bool gbRunGame;
bool gbIsMultiplayer;
bool gbIsSpawn;
bool gbIsHellfire;
bool gbVanilla;
bool forceHellfire;

} // namespace devilution
