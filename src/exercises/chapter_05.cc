#include <exercises/chapter_05.hh>
#include <utils/utils.hh>

#include <iostream>

using namespace std;

void chapter_05::game()
{
    Map game_map;
    Player player;
    player.create_class();

    bool done = false;
    while (!done)
    {
        game_map.print_player_pos();

        int selection = 1;
        cout << "1.) Move\t2.) Rest" << endl;
        cout << "2.) View Stats\t4.) Quit" << endl;
        cout << "Make a selection: ";
        cin >> selection;

        Monster *monster = nullptr;

        switch (selection)
        {
        case 1:
            game_map.move_player();
            monster = game_map.check_random_encounter();
            if (monster)
            {
                // battle loop
                while (true)
                {
                    // display hp
                    player.display_hp();
                    monster->display_hp();
                    cout << endl;

                    // actions
                    bool run_away = player.attack(*monster);
                    if (run_away)
                    {
                        break;
                    }

                    if (monster->is_dead())
                    {
                        player.victory(monster->get_xp_reward());
                        player.level_up();
                        break;
                    }

                    monster->attack(player);

                    if (player.is_dead())
                    {
                        player.game_over();
                        done = true;
                        break;
                    }
                }

                // free memory
                delete monster;
                monster = nullptr;
            }
            break;

        case 2:
            player.rest();
            break;

        case 3:
            player.view_stats();
            break;

        case 4:
        default:
            done = true;
            break;
        }
    }
}

int chapter_05::random(chapter_05::Range r)
{
    return utils::random(r.low, r.high);
}

int chapter_05::random(int low, int high)
{
    return utils::random(low, high);
}

chapter_05::Player::Player()
{
    _name = "Default";
    _class_name = "Default";
    _accuracy = 0;
    _hp = 0;
    _max_hp = 0;
    _armor = 0;
    _xp = 0;
    _next_level_xp = 0;
    _level = 0;
    _weapon.name = "Default Weapon Name";
    _weapon.damange_range.low = 0;
    _weapon.damange_range.high = 0;
}

std::string chapter_05::Player::get_name()
{
    return _name;
}

void chapter_05::Player::display_hp()
{
    cout << _name << "'s HP = " << _hp << endl;
}

int chapter_05::Player::get_armor()
{
    return _armor;
}

bool chapter_05::Player::is_dead()
{
    return _hp <= 0;
}

void chapter_05::Player::take_damage(int damage)
{
    _hp -= damage;
}

void chapter_05::Player::create_class()
{
    int selection = 1;

    cout << "CHARACTER CLASS SELECTOR" << endl
         << "========================" << endl;

    cout << "Enter your character's name: ";
    cin >> _name;

    cout << endl
         << "Class options" << endl
         << "1.) Fighter\t2.) Wizard" << endl
         << "3.) Cleric\t4.) Theif" << endl
         << "Select your character's class: ";
    cin >> selection;

    switch (selection)
    {
    case chapter_05::CharacterClass::Figher:
        _class_name = "Figher";
        _accuracy = 10;
        _hp = 20;
        _max_hp = 20;
        _armor = 4;
        _xp = 0;
        _next_level_xp = 1000;
        _level = 1;
        _weapon.name = "Long Sword";
        _weapon.damange_range.low = 1;
        _weapon.damange_range.high = 8;
        break;

    case chapter_05::CharacterClass::Wizard:
        _class_name = "Wizard";
        _accuracy = 5;
        _hp = 10;
        _max_hp = 10;
        _armor = 1;
        _xp = 0;
        _next_level_xp = 1000;
        _level = 1;
        _weapon.name = "Staff";
        _weapon.damange_range.low = 1;
        _weapon.damange_range.high = 4;
        break;

    case chapter_05::CharacterClass::Cleric:
        _class_name = "Cleric";
        _accuracy = 8;
        _hp = 15;
        _max_hp = 15;
        _armor = 3;
        _xp = 0;
        _next_level_xp = 1000;
        _level = 1;
        _weapon.name = "Flail";
        _weapon.damange_range.low = 1;
        _weapon.damange_range.high = 6;
        break;

    case chapter_05::CharacterClass::Theif:
    default:
        _class_name = "Theif";
        _accuracy = 7;
        _hp = 12;
        _max_hp = 12;
        _armor = 2;
        _xp = 0;
        _next_level_xp = 1000;
        _level = 1;
        _weapon.name = "Short Sword";
        _weapon.damange_range.low = 1;
        _weapon.damange_range.high = 6;
        break;
    }
}

bool chapter_05::Player::attack(Monster &monster)
{
    int selection = 1;

    cout << "Actions:" << endl;
    cout << "1.) Attack\t2.) Run" << endl;
    cout << "Select an option: ";
    cin >> selection;

    switch (selection)
    {
    case 1:
        cout << "You attack " << monster.get_name() << " with a " << _weapon.name << endl;
        if (_accuracy > random(0, 20))
        {
            // hit
            int damage_pts = chapter_05::random(_weapon.damange_range);
            int total_damage = damage_pts - monster.get_armor();

            if (total_damage > 0)
            {
                // armor was penetrated
                cout << "Your attack dealed " << total_damage << " points of damage!" << endl;
                monster.take_damage(total_damage);
            }
            else
            {
                cout << "Your attack failed to penetrate " << monster.get_name() << "'s armor!" << endl;
            }
        }
        else
        {
            cout << "Your attack missed!" << endl;
        }
        break;

    case 2:
    default:
        // attempt to run
        int roll = chapter_05::random(1, 4);
        if (roll == 1)
        {
            cout << "You run away!" << endl;
            return true;
        }
        else
        {
            cout << "You tried to run, but could not escape!" << endl;
        }
        break;
    }

    return false;
}

void chapter_05::Player::level_up()
{
    if (_xp >= _next_level_xp)
    {
        cout << "You gained a level!" << endl;
        _level++;
        _next_level_xp = _level * _level * 1000;
        _accuracy += chapter_05::random(1, 3);
        _max_hp += chapter_05::random(2, 6);
        _armor += chapter_05::random(1, 2);
        _hp = _max_hp;
    }
}

void chapter_05::Player::rest()
{
    cout << "Resting..." << endl;
    _hp = _max_hp;
}

void chapter_05::Player::view_stats()
{
    cout << "PLAYER STATS" << endl
         << "============" << endl
         << endl;

    cout << "Name          = " << _name << endl;
    cout << "Class         = " << _class_name << endl;
    cout << "Accuracy      = " << _accuracy << endl;
    cout << "HP            = " << _hp << endl;
    cout << "Max HP        = " << _max_hp << endl;
    cout << "Armor         = " << _armor << endl;
    cout << "XP            = " << _xp << endl;
    cout << "Next Level XP = " << _next_level_xp << endl;
    cout << "Level         = " << _level << endl;
    cout << "Weapon Name   = " << _weapon.name << endl;
    cout << "Weapon Range  = " << _weapon.damange_range.low << " - " << _weapon.damange_range.high << endl;
    cout << endl;
}

void chapter_05::Player::victory(int xp)
{
    cout << "You won the battle!" << endl;
    cout << "XP Gained: " << xp << "xp" << endl;
    _xp += xp;
}

void chapter_05::Player::game_over()
{
    cout << "You died in battle..." << endl
         << endl
         << "================================" << endl
         << "          GAME OVER !" << endl
         << "================================" << endl
         << "Press 'q' to quit: ";

    char q = 'q';
    cin >> q;
    cout << endl;
}

chapter_05::Monster::Monster(
    const std::string &name,
    int hp,
    int accuracy,
    int xp_reward,
    int armor,
    const std::string &weapon_name,
    int damage_low,
    int damage_high)
{
    _name = name;
    _hp = hp;
    _accuracy = accuracy;
    _xp_reward = xp_reward;
    _armor = armor;
    _weapon.name = weapon_name;
    _weapon.damange_range.low = damage_low;
    _weapon.damange_range.high = damage_high;
}

std::string chapter_05::Monster::get_name()
{
    return _name;
}

int chapter_05::Monster::get_xp_reward()
{
    return _xp_reward;
}

void chapter_05::Monster::display_hp()
{
    cout << _name << "'s HP = " << _hp << endl;
}

int chapter_05::Monster::get_armor()
{
    return _armor;
}

bool chapter_05::Monster::is_dead()
{
    return _hp <= 0;
}

void chapter_05::Monster::attack(chapter_05::Player &player)
{
    if (_accuracy > random(0, 20))
    {
        // hit
        int damage_pts = chapter_05::random(_weapon.damange_range);
        int total_damage = damage_pts - player.get_armor();

        if (total_damage > 0)
        {
            // armor was penetrated
            player.take_damage(total_damage);
        }
    }
}

void chapter_05::Monster::take_damage(int damage)
{
    _hp -= damage;
}

chapter_05::Map::Map()
{
    _player_pos_x = 0;
    _player_pos_y = 0;
}

void chapter_05::Map::move_player()
{
    int selection = 1;

    cout << "Choose a direction" << endl;
    cout << "1.) North\t2.) East" << endl;
    cout << "3.) Souty\t4.) West" << endl;
    cout << "Selection a direction: ";
    cin >> selection;

    switch (selection)
    {
    case Direction::North:
        _player_pos_y++;
        break;

    case Direction::East:
        _player_pos_x++;
        break;

    case Direction::South:
        _player_pos_y--;
        break;

    case Direction::West:
    default:
        _player_pos_x--;
        break;
    }
}

int chapter_05::Map::get_player_x_pos()
{
    return _player_pos_x;
}

int chapter_05::Map::get_player_y_pos()
{
    return _player_pos_y;
}

void chapter_05::Map::print_player_pos()
{
    cout << "Player's Current Position = (" << _player_pos_x << ", " << _player_pos_y << ")" << endl;
}

chapter_05::Monster *chapter_05::Map::check_random_encounter()
{
    int roll = chapter_05::random(0, 20);
    Monster *monster = nullptr;

    if (roll <= 5)
    {
        // no encounter
        return nullptr;
    }
    else if (roll >= 6 && roll <= 10)
    {
        monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7);
    }
    else if (roll >= 11 && roll <= 15)
    {
        monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5);
    }
    else if (roll >= 16 && roll <= 19)
    {
        monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8);
    }
    else if (roll == 20)
    {
        monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two-handed Sword", 5, 20);
    }

    cout << "You encounter an " << monster->get_name() << "!" << endl;
    cout << "Prepare for battle!" << endl;
    return monster;
}
