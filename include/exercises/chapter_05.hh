#ifndef CHAPTER_05_HH
#define CHAPTER_05_HH

#include <string>

namespace chapter_05
{
    // enums
    enum CharacterClass
    {
        Figher,
        Wizard,
        Cleric,
        Theif
    };

    enum Direction
    {
        North,
        East,
        South,
        West
    };

    // structs
    struct Range
    {
        int low;
        int high;
    };

    struct Weapon
    {
        std::string name;
        Range damange_range;
    };

    // classes
    class Monster;

    class Player
    {
    public:
        Player();

        std::string get_name();
        void display_hp();
        int get_armor();
        bool is_dead();

        void take_damage(int damage);

        void create_class();
        bool attack(chapter_05::Monster &monster);
        void level_up();
        void rest();
        void view_stats();
        void victory(int xp);
        void game_over();

    private:
        std::string _name;
        std::string _class_name;
        int _accuracy;
        int _hp;
        int _max_hp;
        int _armor;
        int _xp;
        int _next_level_xp;
        int _level;
        Weapon _weapon;
    };

    class Monster
    {
    public:
        Monster(const std::string &name,
                int hp,
                int accuracy,
                int xp_reward,
                int armor,
                const std::string &weapon_name,
                int damage_low,
                int damage_high);

        std::string get_name();
        int get_xp_reward();
        void display_hp();
        int get_armor();
        bool is_dead();

        void attack(Player &player);
        void take_damage(int damage);

    private:
        std::string _name;
        int _hp;
        int _accuracy;
        int _xp_reward;
        int _armor;
        Weapon _weapon;
    };

    class Map
    {
    public:
        Map();

        void move_player();
        int get_player_x_pos();
        int get_player_y_pos();
        void print_player_pos();
        Monster *check_random_encounter();

    private:
        int _player_pos_x;
        int _player_pos_y;
    };

    // functions
    int random(Range r);
    int random(int low, int high);
    void game();
}

#endif // CHAPTER_05_HH
