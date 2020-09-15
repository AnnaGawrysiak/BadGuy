#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Person
{
public:
    string name;
    string surname;

    Person(string name_, string surname_)
    {
        name = name_;
        surname = surname_;
    }

    void Show()
    {
        ios_base::sync_with_stdio(false);
        cout << "Name: " << name << " " << " surname: " << surname << endl;
    }

};


class Gunslinger : public virtual Person
{
friend class BadDude;

private:
    int cuts;
    float time_to_draw;

public:

    Gunslinger (string name_, string surname_, int cuts_,  float time_to_draw_)
    : Person (name_, surname_), // wywolujemy konstruktor klasy bazowej
    cuts (cuts_),
    time_to_draw(time_to_draw_)
    {}

    float Draw()
    {
        return time_to_draw;
    }

    void Show()
    {
        Person::Show();
        cout << "Number of cuts on a gun: " << cuts << endl;
        cout << "Estimated time to draw a weapon: " << time_to_draw << endl;
    }
};

class PokerPlayer : public virtual Person
{
public:

    PokerPlayer (string name_, string surname_)
    : Person (name_, surname_)
    {} // wywolujemy konstruktor klasy bazowej

    int Draw()
    {
        srand(time(NULL));
        int number = (rand()%51)+1;
        return number;
    }

};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
     BadDude (string name_, string surname_, int cuts_, float time_to_draw_)
    : Person (name_, surname_),
    Gunslinger (name_, surname_, cuts_, time_to_draw_),
    PokerPlayer (name_, surname_)
    {}

    float Gdraw()
    {
        return time_to_draw; // time_t_draw jest prywatny
    }

    int Cdraw()
    {
        PokerPlayer::Draw();
    }

    void Show()
    {
        Gunslinger :: Show();
    }

};

int main()
{

    Gunslinger Walker ("Johnnie", "Walker", 14, 0.00001);

    Walker.Show();

    ios_base::sync_with_stdio(false);

    cout << "Walker's estimated time to draw a gun is: " << Walker.Draw() << endl << endl;

    PokerPlayer Joker("Anastasia", "Joker");

    Joker.Show();

    cout << "Today's card number is: " << Joker.Draw() << endl<< endl;

    BadDude Stanley ("Stanley", "Kowalski", 15, 0.006);

    Stanley.Show();

    cout << "Card of the day is: " << Stanley.Cdraw() << endl;

    cout << "Bad guy's time to draw is: " << Stanley.Gdraw() << endl;

    return 0;
}
