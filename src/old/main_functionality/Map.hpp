#include <core/Godot.hpp>
#include <TileMap.hpp>
#include <Node2D.hpp>
#include <KinematicBody2D.hpp>

namespace godot {
    class Map: public  TileMap{
        GODOT_CLASS(Map, TileMap);

        public:
            Map();
            ~Map();
            void _ready();
            void _process(float delta);
            void _register_methods();
    };
}