//The Race!!
//Run to cross the finish line without losing!

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Step  //struct named step with 2 integer types of values 
{
    int type;
    int coins;
};

void clear_steps(Step steps[], int size)
{
    for (int i = 0; i < size; i++)  //for loop to initiallize each steps values to be set to zero
            {
            steps[i].type = 0;
            steps[i].coins = 0;
            }


}

void show_path(Step steps[], int size, int pos) 
{
    for (int i = 0; i < size; i++) //for loop to display each '-' and the one 'x'
    {
        if(i == pos)
            cout << "x";
        else
            cout << "-";
        
    }
}

void add_coins(Step steps[], int size) 
{
    int coin_values[10] = { 0, 0, 5, 0, 0, 10, 0, 0, 20, 0 };
    for (int i = 0; i < size; i++)  //for loop that goes through each step and randomly assigns a value from the coin_values array
    {
        steps[i].coins = coin_values[rand() % 10];
    }

}

void set_step_type(Step steps[], int size, const int type, int howmany)
{
   for (int i = 0; i < howmany; i++) //for loop to select a type for each tile
   {
        int holder = rand() % size;
        steps[holder].type = type; //here, we implement type so it can be oil, glue, bandit, etc.
        
   }

}


int main()
{
    const int TILE = 0;
    const int OIL = 1;
    const int GLUE = 2;
    const int BANDIT = 3;

    const int DISTANCE = 20;
    Step path[DISTANCE];
    int playerpos = 0;
    bool alive = true;
    char action;
    int coins = 0;

    srand(time(NULL));

    clear_steps(path, DISTANCE); //call previously made function to clean all tiles and coins
    
    add_coins(path, DISTANCE); //call previously made function to add coins to path

    set_step_type(path, DISTANCE, OIL, 3);

    set_step_type(path, DISTANCE, GLUE, 2);

    set_step_type(path, DISTANCE, BANDIT, 1);
    
    set_step_type(path, 1, TILE, 1); //sets first spot to a tile

    while (alive && playerpos < DISTANCE)
    {
        show_path(path, DISTANCE, playerpos);
        cout << "s-step, h-hop > ";
        cin >> action;

        if (path[playerpos].type == OIL && action =='h') //if statement to see if player is in oil
        {



        cout << "You're in oil. You can only step" << endl;
        action = 's';
        }

        if (path[playerpos].type == GLUE) //if statement to see if player is in glue
        {
            cout << "You stepped in glue. That makes you a glue-ser!" << endl;
            alive = false;
        }
    if (action == 's')
        playerpos++;
    if (action == 'h')
        playerpos += 2;

    coins += path[playerpos].coins;  //used to add coins to users total amount

       if (path[playerpos].type == BANDIT)

       {
           cout << "Oh no! A bandit took all your coins!" << endl;
           coins = 0;  //set users total amount to 0
       }

    cout << "COINS: " << coins << endl << endl;
    }
    if (playerpos >= DISTANCE && alive)
        cout << "You WON! You crossed the path unscathed!" << endl;
    else
        cout << "You lose. Womp womp." << endl;

    return 0;
    }





