#include "engine/engine.hpp"
#include "game/components/menu/menu_background.hpp"
#include "game/components/menu/logo.hpp"
#include "game/components/menu/play_button.hpp"
#include "game/components/menu/settings_button.hpp"
#include "game/components/menu/results_button.hpp"
#include "game/components/menu/exit_button.hpp"

class MenuScene {
    public:
        MenuScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
        Logo* logo;
        PlayButton* play;
        ResultsButton* results;
        SettingsButton* settings;
        ExitButton* exit;
};
