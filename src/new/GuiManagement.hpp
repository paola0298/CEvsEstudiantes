#pragma one

#include <core/Godot.hpp>
#include <Control.hpp>

namespace godot {
    class GuiManagement : public Control {
        GODOT_CLASS(GuiManagement, Control);

        public:
            static void _register_methods();
            GuiManagement();
            ~GuiManagement();

            void _init();
            void _ready();
            void _process(float delta);

            void _on_Archer_pressed();
            void _on_Mage_pressed();
            void _on_Gunner_pressed();
            void _on_Fire_pressed();
            void _on_Upgrade_pressed();
            void _on_Remove_pressed();

    };
}